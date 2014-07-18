/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 12, 2014, 9:34 PM
 * Purpose: Project 1, Summer CSC 5, 46024
 *          The game hangman
 */

//System Level Libraries 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <limits>
using namespace std;

//User Defined Libraries

//Global Constants
const unsigned short DEC_PCT_CNV = 100;//Conversion from decimal to percent

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    //Constants
    const unsigned short MGS_MAX = 6;//Maximum number of missed guesses
    const unsigned short GS_MAX = 21;//Maximum possible number of guessed letters
    const unsigned short W_MAX = 1000;//Maximum number of words to load
    //Main game variables
    string words[W_MAX];//Array of loaded words
    string answer;//The answer to the current hangman game
    string a_so_far;//Keep track of how the user is doing on the answer to the game
    char guesses[GS_MAX+1];//Keep track of the current guesses plus the delimiter
    int a_len;//Length of the answer word
    int gs_num;//The number of guesses so far
    int gs_misd;//The number of missed guesses (current game only)
    //Inputs
    char m_chse;//The menu choice
    char guess;//The current guess
    //Used for statistics
    int gms_tot;//Total number of games played
    int gms_won;//Number of games won
    int gms_lst;//Number of games lost
    float pgms_won;//Percentage of games won
    float pgms_lst;//Percentage of games lost
    int gs_tot;//Total number of guesses
    int gs_cor;//Number of correct guesses
    int gs_miss;//Number of missed guesses (all time)
    float pgs_cor;//Percentage of guesses correct
    float pgs_misd;//Percentage of guesses missed
    //Flags
    bool running;//A flag used to determine if the current instance of hangman is over
    bool is_match;//A flag used to determine if the guessed letter was in the answer
    bool was_gsd;//A flag used to determine if the user already guessed this letter
    //File streams and variables
    fstream stats;//Stream for the statistics file
    ifstream w_file;//Stream for the words file
    int w_ld = 0;//The number of words loaded (cannot exceed W_MAX)
    
    //Begin setup for the game
    //Load the necessary data for statistics and words
    //Try to open the statistics file
    stats.open("statistics.dat",ios::in);
    if(!stats){
        //If there is no statistics file, create a statistics file and write
        //default values for the statistics to it
        gms_tot = gms_won = gs_tot = gs_cor = 0;
        stats.open("statistics.dat",ios::out);
        stats<<flush;
        stats<<gms_tot<<endl<<gms_won<<endl<<gs_tot<<endl<<gs_cor<<endl;
    }
    else{
        //If there is a statistics file, load the current statistics
        stats>>gms_tot>>gms_won>>gs_tot>>gs_cor;
    }
    
    //Close the statistics file
    stats.close();
    
    //Try to open the words file
    w_file.open("words.dat");
    if (!w_file){//If unable to load words, exit with a fatal error
        cout<<"Fatal Error: unable to open words.dat\n";
        exit(EXIT_FAILURE);
    }
    
    //Load up to W_MAX size of words (default is 1000)
    while(w_ld<W_MAX&&w_file>>words[w_ld])
        w_ld++;

    //Close the words file
    w_file.close();

    //Seed the random number generator
    srand(static_cast<int>(time(0)));
    
    //Format statistics output to two decimal places
    cout<<fixed<<showpoint<<setprecision(2);
    
    //End setup for the game

    //Output a welcome message
    cout<<"Welcome to Hangman!\n";

    //Enter main menu loop
    do{
        //Show the game menu
        cout<<"--------------------Main Menu--------------------\n";
        cout<<"1.       Start a new game of hangman\n";
        cout<<"2.        Show the rules for hangman\n";
        cout<<"3.       Show your hangman statistics\n";
        cout<<"4.                   Quit\n";

        //Get users choice
        cout<<"Choose an option from above (1-4): ";
        cin>>m_chse;
        cout<<endl;
        
        //Ignore all input except the first character
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        //Determine what to do depending on the user's choice
        switch(m_chse){
            case('1'):{
                //Pick a random word from the words loaded and get its length
                answer = a_so_far = words[rand()%w_ld];
                a_len = answer.length();
                //Set the answer found by the user so far to empty
                for(int i = 0;i<a_len;i++)
                    a_so_far[i] = '_';
                //Set the number of guesses and missed guesses to zero
                gs_num = gs_misd = 0;
                //Set the guesses so far to empty
                for(int i = 0;i<GS_MAX;i++)
                    guesses[i] = ' ';
                guesses[GS_MAX] = '\0';
                //Run the main game
                running = true;

                //Enter main game loop
                while(running){
                    //Output the number of guesses left, how much of the answer
                    //the user has gotten, and what the user has guessed so far
                    cout<<"Number of guesses left: "<<(MGS_MAX-gs_misd)<<endl;
                    cout<<"Answer so far: ";
                    for(int i = 0;i<a_len;i++)
                        cout<<a_so_far[i]<<" ";
                    cout<<endl;
                    cout<<"Letters guessed so far: ";
                    for(int i = 0;i<gs_num;i++)
                        cout<<guesses[i]<<" ";
                    cout<<endl;
                    
                    //Validate the guess, i.e., make sure it is in the alphabet
                    //and that it hasn't been guessed before
                    do{
                        //Get a guess from the user
                        cout<<"Guess a letter: ";
                        cin>>guess;

                        //Ignore all input except the first character
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        //Validation
                        guess = tolower(guess);//Convert guess to lower case
                        was_gsd = false;//Assume the guess was not already guessed
                        //Check to see if the guess was already guessed
                        for(int i = 0;i<gs_num;i++){
                               if(guesses[i] == guess){
                                   was_gsd = true;   
                                   break;//Break out if it was guessed already
                           }
                        }
                        //If it was guessed already, print that the user guessed
                        //that letter already
                        if(was_gsd)
                            cout<<"Oops! You already guessed that letter\n";
                        //If the guess isn't in the alphabet, print an error message
                        if(!isalpha(guess))
                            cout<<"Invalid input! Please enter a letter from a to z\n";
                    }while(was_gsd || !isalpha(guess));
                    
                    //Once we have valid input, continue the game as normal
                    guesses[gs_num] = guess;//Add the guess to guesses
                    gs_num++;//Increment guesses for this game by one

                    //Check to see if the guess is part of the answer
                    is_match = false;//Assume guess is not part of the answer
                    for(int i = 0;i<a_len;i++){
                        //If the guess is part of the answer, then update 
                        //the part of the answer the user has gotten so far
                        //and indicate there was a match
                        if(answer[i] == guess){
                            a_so_far[i] = guess;
                            is_match = true;
                        }
                    }

                    //If the guess was in the answer, increment the 
                    //correct guesses
                    if(is_match)
                        gs_cor++;
                    //If it wasn't, then increment the missed guesses
                    else
                        gs_misd++;

                    //If the answer the user has found so far is the same as
                    //the answer, then the user wins
                    if(!(answer.compare(a_so_far))){
                        //Output a winning message
                        cout<<"Congratulations, you've won!\n";
                        cout<<"The word was: "<<answer<<endl;
                        //Increment the games won
                        gms_won++;
                        //Set the status of the game to not running
                        running = false;
                    }

                    //If the guesses missed is equal to the max number of 
                    //missed guesses, the user loses
                    if(gs_misd >= MGS_MAX){
                        //Output a losing message
                        cout<<"You have been hung!\n";
                        cout<<"The word was: "<<answer<<endl;
                        //Set the status of the game to not running
                        running = false;
                    }
                    cout<<endl;
                }
                //Game is finished
                //Update the guess total by adding the total guesses for this game
                gs_tot += gs_num;
                //Increment the total games counter by one
                gms_tot++;
                break;
            }
            case('2'):{
                //Output the rules of hangman
                cout<<"----------------------Rules----------------------\n";
                cout<<"Objective:   Determine a word given its length.\n";
                cout<<"Constraints: You may only guess one letter at\n";
                cout<<"             a time, and you are only allowed\n";
                cout<<"             five wrong guesses.\n\n";
                break;
            }
            case('3'):{
                //Calculate games lost, guesses missed, percentage of games won
                //and percentage of guesses correct
                gms_lst = gms_tot-gms_won;
                gs_miss = gs_tot-gs_cor;
                if(gms_tot > 0){
                    pgms_won = (static_cast<float>(gms_won)/gms_tot)*DEC_PCT_CNV;
                    pgms_lst = 100-pgms_won;
                }
                else
                    pgms_won = pgms_lst = 0;
                if(gs_tot > 0){
                    pgs_cor = (static_cast<float>(gs_cor)/gs_tot)*DEC_PCT_CNV;
                    pgs_misd = 100-pgs_cor;
                }
                else
                    pgs_cor = pgs_misd = 0;
                
                //Output statistics
                cout<<"--------------------Statistics-------------------\n";
                cout<<"Games played:                  "<<setw(6)<<gms_tot<<endl;
                cout<<"Games won:                     "<<setw(6)<<gms_won<<endl;
                cout<<"Games lost:                    "<<setw(6)<<gms_lst<<endl;
                cout<<"Percentage of games won:       "<<setw(6)<<pgms_won<<"%\n";
                cout<<"Percentage of games lost:      "<<setw(6)<<pgms_lst<<"%\n";
                cout<<"Total guesses:                 "<<setw(6)<<gs_tot<<endl;
                cout<<"Correct guesses:               "<<setw(6)<<gs_cor<<endl;
                cout<<"Missed guesses:                "<<setw(6)<<gs_miss<<endl;
                cout<<"Percentage of correct guesses: "<<setw(6)<<pgs_cor<<"%\n";
                cout<<"Percentage of missed guesses:  "<<setw(6)<<pgs_misd<<"%\n\n";
                break;
            }
            case('4'):{//If 4 quit the program
                //Output a quitting message
                cout<<"Goodbye!\n";
                break;
            }
            default:{//Otherwise the input is invalid
                //Output that the input is not valid and ask again
                cout<<"Invalid input, please enter a number from 1 to 4.\n\n";
            }
        }
    }while(m_chse != '4');
    
    //Open the stats file to write the current statistics
    stats.open("statistics.dat",ios::out);
    
    //Write statistics to statistics.dat
    stats<<gms_tot<<endl<<gms_won<<endl<<gs_tot<<endl<<gs_cor<<endl;
    
    //Close the statistics file
    stats.close();
    
    //Exit program
    return 0;
}
