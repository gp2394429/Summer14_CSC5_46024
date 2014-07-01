/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 29, 2014, 11:51 PM
 * Purpose: Gaddis, 7th Edition, Chapter 4, Problem 7
 *          Output the number of days, or number of hours
 *          or number of minutes, given a value of seconds
 */

//System Level Libraries 
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    const int SEC_DAY = 86400, SEC_HR = 3600, SEC_MIN = 60;
    double seconds;
    
    //Get the number of seconds from the user
    cout<<"Enter a number in seconds: ";
    cin>>seconds;
    cout<<endl;
    
    //Determine the number of days or hours or minutes for the given value
    //of seconds, and output the result to the screen
    if (seconds >= SEC_DAY)
        cout<<"There are "<<(seconds/SEC_DAY)<<" days ";
    else if (seconds >= SEC_HR)
        cout<<"There are "<<(seconds/SEC_HR)<<" hours ";
    else if (seconds >= SEC_MIN)
        cout<<"There are "<<(seconds/SEC_MIN)<<" minutes ";
    else
        cout<<"Well... There are certainly "<<seconds<<" seconds ";
    cout<<"in "<<seconds<<" seconds!\n";
        
    //Exit program
    return 0;
}

