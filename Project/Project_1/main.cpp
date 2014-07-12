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
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    const unsigned short G_MAX = 6;//Maximum number of guesses
    const unsigned short W_SIZE = 15;//Maximum word size including delimiter
    //string S_FILE = "statistics.dat";//Name for the statistics file
    char answer[W_SIZE];//The answer to the current hangman game
    char guesses[G_MAX+1];//Keep track of the current guesses plus the delimiter
    char m_chse;//The menu choice
    char c_guess;//The current guess
    int gms_tot;//Total number of games played
    int gms_won;//Number of games won
    int gs_tot;//Total number of guesses
    int gs_cor;//Number of correct guesses
    fstream stats;//Stream for the statistics file
    
    //Try to open the statistics file
    stats.open("statistics.dat");
    if(!stats){
        //If there is no statistics file, create a statistics file and write
        //default values for the statistics to it
        gms_tot = gms_won = gs_tot = gs_cor = 0;
        stats.open("statistics.dat", ios::out);
        stats<<flush;
        stats<<gms_tot<<endl<<gms_won<<endl<<gs_tot<<endl<<gs_cor<<endl;
        stats.close();
    }
    else{
        //If there is a statistics file, load the current statistics
        stats>>gms_tot>>gms_won>>gs_tot>>gs_cor;
        stats.close();
    }
    
    //Output a welcome message
    cout<<"Welcome to Hangman!\n";
    
    //Enter the game loop
    do{
        //Show the game menu
        cout<<"------Main Menu------\n";
        cout<<"1. Start a new game of hangman\n";
        cout<<"2. Show your hangman statistics\n";
        cout<<"3. Quit\n";

        //Enter input validation loop
        do{
            //Get users choice
            cout<<"Choose an option from above: ";
            cin>>m_chse;
            cout<<endl;

            //Determine what to do depending on the input
            switch(m_chse){
                case('1'):{//If 1 run the game
                    //Run hangman game
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
                    cout<<"Invalid input, please enter a number from 1 to 3.\n";
                }
            }
        }while(m_chse < '1' || m_chse > '3');
    }while(m_chse != '3');
        
    //Exit program
    return 0;
}
