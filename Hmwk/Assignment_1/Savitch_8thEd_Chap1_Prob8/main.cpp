/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 26, 2014, 12:09 AM
 * Purpose: Savitch, 8th Edition, Chapter 1, Problem 8
 *          Calculate and display the amount of change
 *          for an input of the numbers of quarters,
 *          dimes, and nickels
 */

//System Level Libraries 
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants
const short Q_VALUE = 25, D_VALUE = 10, N_VALUE = 5;

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    
    //Declare variables
    int quarters, dimes, nickels, total;
    
    //Input for quarters, dimes, and nickels
    cout<<"How many quarters do you have?: ";
    cin>>quarters;
    cout<<"How about dimes?: ";
    cin>>dimes;
    cout<<"Nickels?: ";
    cin>>nickels;
    
    //Calculate total
    total = (Q_VALUE*quarters)+(D_VALUE*dimes)+(N_VALUE*nickels);
    
    //Output the total change
    cout<<"Your total change is: "<<total<<" cents.\n";
    
    //Exit Program
    return 0;
}

