/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 12, 2014, 9:34 PM
 * Purpose: Project 1, Summer CSC 5, 46024
 *          The game hangman
 */

//System Level Libraries 
#include <iostream>
#include <limits>//Used for simple bad input handling
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    const unsigned short G_MAX = 6;//Maximum number of guesses
    const unsigned short W_SIZE = 15;//Maximum word size including delimiter
    char answer[W_SIZE];//The answer to the current hangman game
    char guesses[G_MAX+1];//Keep track of the current guesses plus the delimiter
    char m_chse;//The menu choice
    char c_guess;//The current guess
    
    //Enter the game loop
    do{
        //Show the game menu
        cout<<"Welcome to Hangman!\n";
        cout<<"1. Start a new game\n";
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

