/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 30, 2014, 11:27 PM
 * Purpose: Savitch, 8th Edition, Chapter 3, Problem 15
 *          Given an input of radius (in feet) and weight
 *          (in pounds) of a sphere, calculate whether the
 *          sphere will sink or float in water.
 */         

//System Level Libraries 
#include <iostream>
#include <cmath> //Included for the pow() function
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    const float GAMMA = 62.4, //The weight per unit volume of water (lb/ft^3)
                PI = 3.14;
    double radius, weight, volume, b_force;
    
    //Get the radius and weight of the sphere from the user
    cout<<"What is the radius of the sphere(in feet)?: ";
    cin>>radius;
    cout<<"What is the weight of the sphere(in pounds)?: ";
    cin>>weight;
    cout<<endl;
    
    //Calculate the volume of the sphere = (4/3)*PI*radius^3
    //and the buoyant force = volume*GAMMA
    volume = (4.0/3)*PI*pow(radius,3);
    b_force = volume*GAMMA;
    
    //The sphere will float if the buoyant force is greater than or
    //equal to the weight of the sphere it will float, otherwise it will sink.
    //Output the buoyancy force and whether it will sink or float to the user
    cout<<"The buoyancy force is: "<<b_force<<" lbs, which means... ";
    cout<<(b_force>=weight?"It floats!\n":"It sinks!\n");
    
    //Exit program
    return 0;
}

