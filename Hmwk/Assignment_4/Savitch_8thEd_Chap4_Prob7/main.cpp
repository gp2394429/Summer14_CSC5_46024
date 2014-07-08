/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 7, 2014, 7:43 PM
 */

//System level libraries
#include <iostream>
using namespace std;

//User defined libraries

//Global constants
const float UNI_GRAV = 6.673e-8f;//Universal gravitational constant(in cm^3/(g*sec^2))
//Function prototypes
float gForce(float mass_1, float mass_2, float dist);
//Calculate and return the gravitational force between two objects given
//their masses(in grams) and the distance between them(in centimeters)

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    //Input
    float mass_1, mass_2;//Masses of the two objects(in grams)
    float dist; //Distance between the two objects(in centimeters)
    //Get input from user
    cout<<"What is the mass of the first object(in grams)?: ";
    cin>>mass_1;
    cout<<"What is the mass of the second object(in grams)?: ";
    cin>>mass_2;
    cout<<"What is the distance between the two objects(in centimeters)?: ";
    cin>>dist;
    cout<<endl;
    //Output the gravitational force between the two objects(in dynes)
    cout<<"The gravitational force between the two objects is: "
        <<gForce(mass_1, mass_2, dist)<<" dyn.\n";
    //Exit program
    return 0;
}
//Function definitions
float gForce(float mass_1, float mass_2, float dist) {
    return (UNI_GRAV*mass_1*mass_2)/(dist*dist);
}

