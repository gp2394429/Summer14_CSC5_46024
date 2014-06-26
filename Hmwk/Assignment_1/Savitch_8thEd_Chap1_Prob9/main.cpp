/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 26, 2014, 12:21 AM
 * Purpose: Savitch, 8th Edition, Chapter 1, Problem 8
 *          Calculate and display the distance traveled
 *          by an object in freefall for an input of time
 */

//System Level Libraries 
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants
const short GRAVITY = 32; //Gravitational constant on Earth in ft/s^2

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    
    //Declare variables
    double time, distance;
    
    //Input time
    cout<<"How long did the object fall?: ";
    cin>>time;
    
    //Calculate distance
    distance = (GRAVITY*time*time)/2;
    
    //Output distance
    cout<<"The total distance traveled was: "<<distance<<" ft\n";
    
    //Exit program
    return 0;
}

