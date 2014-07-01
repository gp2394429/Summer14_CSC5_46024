/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 28, 2014, 11:17 PM
 * Purpose: Savitch, 8th Edition, Chapter 3, Problem 1
 *          Create a rock paper scissors game
 */

//System Level Libraries 
#include <iostream>
#include <string>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    string PPR_WIN = "Paper covers rock, ";
    string RCK_WIN = "Rock breaks scissors, ";
    string SCR_WIN = "Scissors cuts paper, ";
    string P1_WIN = "player one wins!\n";
    string P2_WIN = "player two wins!\n";
    string NB_WIN = "Nobody wins.\n";
    string IE_P1 = "Invalid entry for player 1!\n";
    string IE_P2 = "Invalid entry for player 2!\n";
    char p1_entry, p2_entry, quit;
    bool running = true, valid;
    
    //Output welcome message
    cout<<"Let's play Rock, Paper, Scissors!\n\n";
    
    //Enter game loop
    while (running) {
        //Get user input
        cout<<"Enter R for rock, P for paper, or S for scissors.\n";
        cout<<"Player 1 entry: ";
        cin>>p1_entry;
        cout<<"Player 2 entry: ";
        cin>>p2_entry;
        cout<<endl;
        
        //Determine who won and how
        switch (p1_entry) {
            case 'R':
            case 'r':
                switch (p2_entry) {
                    case 'R':   
                    case 'r':
                        cout<<NB_WIN;
                        break;
                    case 'P':
                    case 'p':
                        cout<<(PPR_WIN + P2_WIN);
                        break;
                    case 'S':
                    case 's':
                        cout<<(RCK_WIN + P1_WIN);
                        break;
                    default:
                        cout<<IE_P2;
                }
                break;
            case 'P':
            case 'p':
                switch (p2_entry) {
                    case 'R':
                    case 'r':
                        cout<<(PPR_WIN + P1_WIN);
                        break;
                    case 'P':
                    case 'p':
                        cout<<NB_WIN;
                        break;
                    case 'S':
                    case 's':
                        cout<<(SCR_WIN + P2_WIN);
                        break;
                    default:
                        cout<<IE_P2;
                }
                break;
            case 'S':
            case 's':
                switch (p2_entry) {
                    case 'R':
                    case 'r':
                        cout<<(RCK_WIN + P2_WIN);
                        break;
                    case 'P':
                    case 'p':
                        cout<<(SCR_WIN + P1_WIN);
                        break;
                    case 'S':
                    case 's':
                        cout<<NB_WIN;
                        break;
                    default:
                        cout<<IE_P2;
                }
                break;
            default:
                cout<<IE_P1;
        }
        
        //Check to see if they want to play again
        valid = false; //Assume a non-valid answer
        while (!valid) {
            //Get input from user
            cout<<endl;
            cout<<"Would you like to play again?[Y/N]: ";
            cin>>quit;
            
            //Check to see if its valid input
            switch (quit) {
                case 'Y':
                case 'y':
                    valid = true;
                    break;
                case 'N':
                case 'n':
                    cout<<"See you next time.\n";
                    valid = true;
                    running = false;
                    break;
                default:
                    cout<<"Sorry, I didn't get that.\n";                
            }
        }
    }
    
    //Exit program
    return 0;
}

