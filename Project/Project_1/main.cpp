/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 12, 2014, 9:34 PM
 * Purpose: Project 1, Summer CSC 5, 46024
 *          The game hangman
 */

//System Level Libraries 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    const unsigned short MGS_MAX = 6;//Maximum number of missed guesses
    const unsigned short GS_MAX = 17;//Maximum possible number of guessed letters
    const unsigned short W_MAX = 200;//Maximum number of words to load
    //string S_FILE = "statistics.dat";//Name for the statistics file
    string words[W_MAX];//Array of words
    string answer;//The answer to the current hangman game
    string a_so_far;//Keep track of how the user is doing on the answer to the game
    char guesses[GS_MAX+1];//Keep track of the current guesses plus the delimiter
    char m_chse;//The menu choice
    char guess;//The current guess
    int a_len;//Length of the answer word
    int gs_num;//The number of guesses so far
    int gs_misd;//The number of guesses missed
    int w_ld = 0;//The number of words loaded (cannot exceed W_MAX)
    int gms_tot;//Total number of games played
    int gms_won;//Number of games won
    int gs_tot;//Total number of guesses
    int gs_cor;//Number of correct guesses
    bool running;//Status of the current main game instance
    bool is_match;//A flag used to determine if the guessed letter was in the answer
    fstream stats;//Stream for the statistics file
    ifstream w_file;//Stream for the words file
    
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
    }
    else {//Otherwise load the words from words.dat and continue the program
        //Load up to W_MAX size of words (default is 200)
        while(w_ld<W_MAX&&w_file>>words[w_ld])
            w_ld++;
        
        //Close the words file
        w_file.close();
        
        //Seed the random number generator
        srand(static_cast<int>(time(0)));
        //End setup for the game
        
        //Output a welcome message
        cout<<"Welcome to Hangman!\n";

        //Enter main menu loop
        do{
            //Show the game menu
            cout<<"------Main Menu------\n";
            cout<<"1. Start a new game of hangman\n";
            cout<<"2. Show your hangman statistics\n";
            cout<<"3. Quit\n";
            
            //Get users choice
            cout<<"Choose an option from above: ";
            cin>>m_chse;
            cout<<endl;

            //Determine what to do depending on the user's choice
            switch(m_chse){
                case('1'):{//If 1 run the main game
                    //Pick a random word from the words loaded and get its length
                    answer = words[rand()%w_ld];
                    a_len = answer.length();
                    //Set the a_so_far to the default value
                    for(int i = 0;i<a_len;i++)
                        a_so_far+='_';
                    //Set the number of guesses and missed guesses to zero
                    gs_num = gs_misd = 0;
                    //Set the guesses so far to the default value
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
                        
                        //Get a guess from the user
                        cout<<"Guess a letter: ";
                        cin>>guess;
                        
                        //Validate guess i.e. make sure it is in the alphabet
                        if(isalpha(guess)){
                            guess = tolower(guess);//Convert guess to lower case
                            guesses[gs_num] = guess;//Add the guess to the guessed letters
                            gs_num++;//Increment the number of guesses for this game by one
                            
                            //Check to see if the guess is part of the answer
                            is_match = false;//Assume there is no match
                            for(int i = 0;i<a_len;i++){
                                //If there is a match, then update a_so_far and set the flag to true
                                if(answer[i] == guess){
                                    a_so_far[i] = guess;
                                    is_match = true;
                                }
                            }
                            
                            //If the guess was in the answer, increment gs_cor
                            if(is_match)
                                gs_cor++;
                            //If it wasn't, then increment gs_misd
                            else
                                gs_misd++;
                            
                            //If the answer the user has found so far is equal to
                            //the answer, then the user wins
                            if(!(answer.compare(a_so_far))){
                                //Output a winning message
                                cout<<"Congratulations, you've won!\n";
                                cout<<"The word was: "<<answer<<endl<<endl;
                                //Increment the gms_won
                                gms_won++;
                                //Make sure the game is no longer running
                                running = false;
                            }
                            
                            //If the guesses missed is equal to the max number of 
                            //missed guesses, the user loses
                            if(gs_misd >= MGS_MAX){
                                //Output a losing message
                                cout<<"You lost...\n";
                                cout<<"The word was: "<<answer<<endl;
                                //Make sure the game is no longer running
                                running = false;
                            }
                        }
                        else{
                            //Output an error message for the input
                            cout<<"Invalid input!\n"; 
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
                case('2'):{//If 2 output the users hangman statistics
                    //Output statistics for this session
                    cout<<"Games played:    "<<gms_tot<<endl;
                    cout<<"Games won:       "<<gms_won<<endl;
                    cout<<"Total guesses:   "<<gs_tot<<endl;
                    cout<<"Correct guesses: "<<gs_cor<<endl<<endl;
                    break;
                }
                case('3'):{//If 3 quit the program
                    //Output a quitting message
                    cout<<"Quitting...\n";
                    cout<<"Goodbye!\n";
                    break;
                }
                default:{//Otherwise the input is invalid
                    //Output that the input is not valid and ask again
                    cout<<"Invalid input, please enter a number from 1 to 3.\n\n";
                }
            }
        }while(m_chse != '3');
    }
    
    //Open the stats file to write the current statistics
    stats.open("statistics.dat",ios::out);
    
    //Write statistics to statistics.dat
    stats<<gms_tot<<endl<<gms_won<<endl<<gs_tot<<endl<<gs_cor<<endl;
    
    //Close the statistics file
    stats.close();
    
    //Exit program
    return 0;
}
