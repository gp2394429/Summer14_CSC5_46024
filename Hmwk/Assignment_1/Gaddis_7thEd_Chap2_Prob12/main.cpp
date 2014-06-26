/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 25, 2014, 9:22 PM
 * Purpose: Gaddis, 7th Edition, Chapter 2, Problem 12
 *          Calculate the number of acres in a given 
 *          square footage.
 */

//System Level Libraries 
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants
const unsigned short ACRE = 43560; //number of square feet in an acre
//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    
    //Declare variables
    float sq_feet = 389767;
    float tot_acres;
    
    //Calculate the total amount of acres
    tot_acres = sq_feet/ACRE;
    
    //Output to the screen
    cout<<"The total number of acres is: "<<tot_acres<<endl;
    
    //Exit program
    return 0;
}

