/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 29, 2014, 11:23 PM
 * Purpose: Gaddis, 7th Edition, Chapter 4, Problem 4
 *          Determine the area of two rectangles given input
 *          of lengths and widths, then output which has the
 *          greater area or if they have the same area
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
    double len_1, len_2, wid_1, wid_2, area_1, area_2;
    
    //Get lengths and widths from the user
    cout<<"What are the dimensions of the first rectangle?\n";
    cout<<"Format: width length ";
    cin>>wid_1>>len_1;
    cout<<"What are the dimensions of the second rectangle?\n";
    cout<<"Format: width length ";
    cin>>wid_2>>len_2;
    cout<<endl;
    
    //Calculate area = width * length
    area_1 = wid_1 * len_1;
    area_2 = wid_2 * len_2;
    
    //Determine if the areas or the same or if one is larger and output
    //the result
    
    if (area_1 == area_2)
        cout<<"The areas are the same, and are: "<<area_1<<endl;
    else if (area_1 > area_2)
        cout<<"The first rectangle has greater area, and it is: "<<area_1<<endl;
    else
        cout<<"The second rectangle has greater area, and it is: "<<area_2<<endl;
    
    //Exit program
    return 0;
}

