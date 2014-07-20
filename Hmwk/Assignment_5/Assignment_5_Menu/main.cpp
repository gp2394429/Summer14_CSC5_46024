/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 20, 2014, 1:17 AM
 * Purpose: Assignment #5 Summer CSC-5 46024 
 */

//System Level Libraries 
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants
const unsigned short HRS_DAY = 24;//Hours in a day
const unsigned short MIN_HR = 60;//Minutes in an hour
//Function Prototypes
bool doRepeat();//Generally useful function
void getTime(int& hrs, int& mns);//Used in problem 1
void milOut(int time);//Used in problem 1

//Begin Execution

int main(int argc, char** argv) {
    //Declare menu variables
    short m_choice;//Users choice
    //Main menu setup and output
    //Enter menu loop
    do{
        cout << "1.  Savitch, 8thEd, Chapter 5, Problem 2\n";
        cout << "2.  Gaddis,  7thEd, Chapter 4, Problem 6\n";
        cout << "3.  Gaddis,  7thEd, Chapter 4, Problem 7\n";
        cout << "4.  Gaddis,  7thEd, Chapter 4, Problem 8\n";
        cout << "5.  Gaddis,  7thEd, Chapter 4, Problem 18\n";
        cout << "6.  Savitch, 8thEd, Chapter 3, Problem 1\n";
        cout << "7.  Savitch, 8thEd, Chapter 3, Problem 2\n";
        cout << "8.  Savitch, 8thEd, Chapter 3, Problem 12\n";
        cout << "9.  Savitch, 8thEd, Chapter 3, Problem 15\n";
        cout << "10. Savitch, 8thEd, Chapter 3, Problem 16\n";
        cout << "11. Quit the program\n";
        cout << "Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cout << endl;

        switch (m_choice) {
            case(1):
            {
                //Short problem description
                cout<<"Outputs the time it will be after waiting a given period\n";
                cout<<"of time in military time.\n\n";
                //Begin problem 1
                //Declare variables
                //Inputs
                int c_hours, c_mins;//Hours and minutes currently
                int w_hours, w_mins;//Hours and minutes waited
                //Outputs
                int hours, mins;//Hours and minutes after waiting
                
                do{
                    //Get input from user
                    //Validate input time
                    do{
                        cout<<"Please enter the current time\n";
                        getTime(c_hours, c_mins);
                    }while(c_hours < 0 || c_hours >= HRS_DAY ||
                           c_mins  < 0 || c_mins  >= MIN_HR);
                    
                    cout<<"Please enter the waiting period\n";
                    getTime(w_hours, w_mins);
                    
                    //Calculate the result
                    hours = c_hours+w_hours;
                    mins = c_mins+w_mins;
                    while(mins>=MIN_HR){
                         mins -= MIN_HR;
                         hours++;
                    }
                    hours %= HRS_DAY;
                    
                    //Output the result
                    cout<<"The time after waiting is: ";
                    milOut(hours);
                    cout<<":";
                    milOut(mins);
                    cout<<endl;
                    
                }while(doRepeat());//Ask if the user wants to repeat the calculation
                //End problem 1
                break;
            }
            case(2):
            {
                //Short problem description
                //Begin problem 2
                //End problem 2
                cout << endl;
                break;
            }
            case(3):
            {
                //Short problem description
                //Begin problem 3
                //End problem 3
                cout << endl;
                break;
            }
            case(4):
            {
                //Short problem description
                //Begin problem 4
                //End problem 4
                cout << endl;
                break;
            }
            case(5):
            {
                //Short problem description
                //Begin problem 5
                //End problem 5
                cout << endl;
                break;
            }
            case(6):
            {
                //Short problem description
                //Begin problem 6
                //End problem 6
                cout << endl;
                break;
            }
            case(7):
            {
                //Short problem description
                //Begin problem 7
                //End problem 7
                cout << endl;
                break;
            }
            case(8):
            {
                //Short problem description
                //Begin problem 8
                //End problem 8
                cout << endl;
                break;
            }
            case(9):
            {
                //Short problem description
                //Begin problem 9
                //End problem 9
                cout << endl;
                break;
            }
            case(10):
            {
                //Short problem description
                //Begin problem 10
                //End problem 10
                cout << endl;
                break;
            }
            default:
                cout << "Exiting program\n";
        }
    }while(m_choice <= 10 && m_choice > 0);
    
    //Exit program
    return 0;
}
//Generally useful functions

//Returns true or false depending if the user wants to repeat the calculation or not
bool doRepeat(){
    //Declare variables
    char answer;//Users answer
    
    //Determine if the user wants to repeat the calculation
    cout<<"Would you like to repeat the calculation?\n";
    cout<<"Enter Y if yes: ";
    cin>>answer;
    cout<<endl;
    
    //Return true if the answer is yes
    return (answer == 'y' || answer == 'Y');
}
//Problem one functions

//Function that allows the user to input military time
//Output is by reference
//Input
//  hrs = hours
//  mns = minutes
//Output
//  hrs = hours
//  mns = minutes
void getTime(int& hrs, int& mns){
    //Get hours and minutes from the user
    cout<<"Format [hours minutes]: ";
    cin>>hrs>>mns;
}
//Correctly prints military time
//No outputs
//Inputs
//  time = some value of time in hours, minutes, or seconds
void milOut(int time){
    if(time<10)
        cout<<"0";
    cout<<time;
}