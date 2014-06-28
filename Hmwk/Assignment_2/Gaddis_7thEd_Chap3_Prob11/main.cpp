/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 27, 2014, 9:03 PM
 * Purpose: Gaddis, 7th Edition, Chapter 3, Problem 11
 *          Convert Celsius to Fahrenheit 
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
    float celsius, fahrenheit;

    //Get the Celsius temperature from the user
    cout<<"Enter a temperature in degrees Celsius: ";
    cin>>celsius;
    cout<<endl;
    
    //Calculate the temperature in degrees Fahrenheit
    fahrenheit = ((9.0f / 5) * celsius) + 32;
    
    //Output to user
    cout<<"The temperature in degrees Fahrenheit is: "<<fahrenheit<<endl;
    
    //Exit program
    return 0;
}

