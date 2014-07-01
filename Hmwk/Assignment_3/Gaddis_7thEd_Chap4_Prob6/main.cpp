/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 29, 2014, 11:37 PM
 * Purpose: Gaddis, 7th Edition, Chapter 4, Problem 6
 *          Calculate an objects weight in newtons (on earth) 
 *          given the objects mass. Output the result and determine
 *          if the object is too heavy (>1000) or too light (<10) 
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
    const float E_GRAV = 9.8;
    const int W_MAX = 1000, W_MIN = 10;
    float mass, weight;
    
    //Get the mass of the object from the user
    cout<<"What is the mass of the object(in kg)?: ";
    cin>>mass;
    cout<<endl;
    
    //Calculate the weight = mass * gravity in newtons
    weight = mass * E_GRAV;
    
    //Output weight
    cout<<"The weight of the object is: "<<weight<<" N\n";
    
    //Determine if the object is above 1000N or below 10N and
    //output the result
    if (weight > W_MAX)
        cout<<"The object is too heavy!\n";
    if (weight < W_MIN)
        cout<<"The object is too light!\n";

    //Exit program
    return 0;
}

