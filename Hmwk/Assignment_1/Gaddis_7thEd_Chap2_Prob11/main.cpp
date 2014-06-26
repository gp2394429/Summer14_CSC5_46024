/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 25, 2014, 9:04 PM
 * Purpose: Gaddis, 7th Edition, Chapter 2, Problem 11
 *          Calculate the distance a car can travel in 
 *          the town and on the highway given the amount 
 *          of gas the car can hold and the average 
 *          miles per gallon.
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
    unsigned short total_gas = 20;
    float town_mpg = 21.5, high_mpg = 26.8, dis_town, dis_high;
    
    //Calculate distance in town and distance on the highway
    dis_town = total_gas*town_mpg;
    dis_high = total_gas*high_mpg;
    
    //Output to screen
    cout<<"Distance you can travel in town is: "<<dis_town<<endl;
    cout<<"Distance you can travel on the highway is: "<<dis_high<<endl;
    
    //Exit program
    return 0;
}

