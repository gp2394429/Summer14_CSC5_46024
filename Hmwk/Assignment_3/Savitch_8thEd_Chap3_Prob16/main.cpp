/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 30, 2014, 8:20 PM
 * Purpose: Savitch, 8th Edition, Chapter 3, Problem 16
 *          Determine at what integer temperature 
 *          Fahrenheit is equal to Celsius
 */

//System Level Libraries
#include <iostream>//Input Output Library
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution Begins

int main(int argc, char** argv) {
    //Declare variables
    //Start value for celsius is 100 by the problem description
    int celsius = 100, fahrenheit;
    
    //Decrement celsius and calculate fahrenheit until they are equal
    do {
        celsius--;
        fahrenheit = ((9*celsius)/5)+32;
    } while(celsius!=fahrenheit);
    
    //Output the temperature where celsius and fahrenheit are equal
    cout<<"Celsius and Fahrenheit temperatures are equal at: "<<celsius
        <<" degrees.";
    
    //Exit program
    return 0;
}

