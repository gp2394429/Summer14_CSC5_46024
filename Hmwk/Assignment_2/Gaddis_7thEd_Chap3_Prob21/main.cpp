/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 27, 2014, 10:27 PM
 * Purpose: Gaddis, 7th Edition, Chapter 3, Problem 21
 *          Take an input angle in radians from the user and
 *          output the sin, cos, and tan of that angle to
 *          four decimal places
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
    float rads;

    //Get the angle in radians from the user
    cout<<"Please enter an angle in radians: ";
    cin>>rads;
    cout<<endl;
    
    //Format cout for four decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    
    //Output the sin, cos, and tan of the angle
    cout<<"The sine of the angle is: "<<sin(rads)<<endl;
    cout<<"The cosine of the angle is: "<<cos(rads)<<endl;
    cout<<"The tangent of the angle is: "<<tan(rads)<<endl;
    
    //Exit program
    return 0;
}

