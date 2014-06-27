/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 26, 2014, 6:47 PM
 * Purpose: Savitch, 8th Edition, Chapter 2, Problem 15
 *          Approximate the speed of sound for a temperature range
 *          input from the user and output the result to the screen
 */

//System Level Libraries 
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    //Define variables
    const float V_CNST_1 = 331.3, V_CNST_2 = 0.61; //Constants defined by the
                                                   //problem
    short low_temp, high_temp;
    float velocity;
    
    //Get temperature range in degrees Celsius from the user
    cout<<"Input an integer temperature range in degrees Celsius\n";
    cout<<"Enter the lower bound: ";
    cin>>low_temp;
    cout<<"Enter the upper bound: ";
    cin>>high_temp;
    
    //Enter output loop
    while (low_temp <= high_temp) {
        //Calculate velocity
        velocity = V_CNST_1 + (V_CNST_2*low_temp);
        
        //Output velocity
        cout<<"At "<<low_temp<<" degrees Celsius the velocity of sound is "
            <<velocity<<" m/s\n";
        
        //Increment low_temp
        low_temp++;
    }
    
    //Exit program
    return 0;
}

