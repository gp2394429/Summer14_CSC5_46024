/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 26, 2014, 4:37 PM
 * Purpose: Savitch, 8th Edition, Chapter 2, Problem 12
 *          Calculate the square root of a number n using
 *          the Babylonian algorithm
 */

//System Level Libraries 
#include <iostream>
#include <cmath>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {

    //Declare variables
    int n; //The integer we are trying to find the square root of
    float threshold = 1e-2f; //Our threshold condition for stopping the loop
    double r, prev_guess, guess, p_range;
    
    //Get the integer we are trying to find the square root of
    cout<<"Please enter an integer: ";
    cin>>n;
    
    //Set our initial guess condition
    guess = n/2.0;
            
    //Start calculation
    do {
        prev_guess = guess;
        r = n/guess;
        guess = (guess+r)/2;
        //Calculate how close the new guess is to the old guess as a percentage
        p_range = abs((prev_guess-guess)/prev_guess);
 
    } while (p_range > threshold);
    
    //Output the result
    cout<<"The square root of "<<n<<" is approximately: "<<guess<<endl;
    
    //Exit program
    return 0;
}

