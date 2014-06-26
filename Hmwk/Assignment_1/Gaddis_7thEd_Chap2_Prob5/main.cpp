/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 25, 2014, 8:31 PM
 * Purpose: Gaddis, 7th Edition, Chapter 2, Problem 5
 *          Calculate the average of five given numbers
 *          and display that value to the screen
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
    const short num_1 = 28, num_2 = 32, num_3 = 37,
                num_4 = 24, num_5 = 33;
    short sum;
    float average;
    
    //Calculate sum and average
    sum = num_1 + num_2 + num_3 + num_4 + num_5;
    average = sum/(5.0f); //Make sure the value of average is a float
    
    //Display the average to the screen
    cout<<"The average of 28, 32, 37, 24, and 33 is: "<<average<<endl;
    
    //Exit program
    return 0;
}

