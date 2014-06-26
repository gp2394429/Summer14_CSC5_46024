/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 25, 2014, 8:53 PM
 * Purpose: Gaddis, 7th Edition, Chapter 2, Problem 10
 *          Calculate miles per gallon (MPG) of a vehicle
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
    unsigned short gallons = 12;
    //Declare miles as a float to ensure MPG will also be a float
    float miles = 350, mpg;
    
    //Calculate MPG
    mpg = miles/gallons;
    
    //Output MPG to the screen
    cout<<"The miles per gallon of this vehicle is: "<<mpg<<endl;
    
    //Exit program
    return 0;
}

