/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 24, 2014, 10:39 PM
 * Purpose: Project 2 Summer CSC-5 46024
 *          Connect Four 
 */

//System Level Libraries 
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
void menuOut();
unsigned short getNum();
bool inRange(unsigned short,const short,const short=0);
//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    const short UB_MC = 3;//Upper bound for the menu choice 
    unsigned short m_choice;//The users menu choice
    //Enter menu loop
    do{
        //Output menu
        menuOut();
        
        //Get a number from the user
        m_choice = getNum();
        
        switch(m_choice){
            case(1):{
                cout<<"Connect four game\n";
                break;
            }
            case(2):{
                cout<<"Rules for connect four\n";
                break;
            }
            default:
                cout<<"Exiting game.\n";
        }
    }while(inRange(m_choice,UB_MC));//Check to see if the input is in a range

    //Exit program
    return 0;
}
//Function definitions

//Prints the main menu to the screen
//No inputs
//No outputs
void menuOut(){
    cout<<"1. Play Connect Four\n";
    cout<<"2. Rules for Connect Four\n";
    cout<<"3. Quit\n";
}

//Gets a number from the user
//No inputs
//Outputs
//  choice = the users choice
unsigned short getNum(){
    unsigned short choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}

//Determines whether input is inside a range exclusive of the bounds
//Inputs
//  ipt = input to be validated
//  LB = lower bound on the input (defaults to zero))
//  UB = upper bound on the input
//Outputs
//  bool determining if the input is valid or not
bool inRange(unsigned short ipt,const short UB,const short LB){
    //The input is in the range if it is between the upper and lower bounds
    return ipt>LB && ipt<UB;
}