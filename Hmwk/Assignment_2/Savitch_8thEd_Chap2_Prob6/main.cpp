/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 27, 2014, 7:19 PM
 * Purpose: Savitch, 8th Edition, Chapter 2, Problem 6
 *          Determine if a meeting room is following fire
 *          regulations given the input of max capacity and
 *          number of people attending
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
    int num_ppl, max_cap, abs_diff;
    
    //Get input for number of people and max capacity
    cout<<"How many people are attending?: ";
    cin>>num_ppl;
    cout<<"What is the max capacity of the room?: ";
    cin>>max_cap;
    cout<<endl;
 
    //Calculate the absolute difference between 
    //number of people and max capacity
    abs_diff = abs(max_cap - num_ppl);
    
    //Determine if the meeting room meets fire regulations
    if (num_ppl <= max_cap) {
        cout<<"Congratulations, your meeting meets fire regulations.\n";
        cout<<"Additionally, "<<abs_diff<<" more people can attend legally.\n";
    }
    else {
        cout<<"Sorry, your meeting doesn't meet regulations.\n";
        cout<<"You must exclude "<<abs_diff<<" people to meet legally.\n";
    }
  
    //Exit program
    return 0;
}

