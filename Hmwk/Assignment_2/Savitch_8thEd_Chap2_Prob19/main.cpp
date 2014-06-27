/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 26, 2014, 7:11 PM
 * Purpose: Savitch, 8th Edition, Chapter 2, Problem 19
 *          Calculate the total grade for n classroom exercises
 *          as a percentage.
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
    unsigned short cur_ex = 1, tot_ex;
    float ex_scr, ex_max, max_scr = 0, usr_scr = 0, p_total;
    
    //Get total exercises
    cout<<"How many exercises to input? ";
    cin>>tot_ex;
    cout<<endl;
    
    //Enter IO loop
    while (cur_ex <= tot_ex) {
        //Get user score and max score for the current exercise
        cout<<"Score received for exercise "<<cur_ex<<": ";
        cin>>ex_scr;
        cout<<"Total points possible for exercise "<<cur_ex<<": ";
        cin>>ex_max;
        cout<<endl;
        
        //Calculate running totals for scores
        usr_scr += ex_scr;
        max_scr += ex_max;
        
        //Increment the current exercise
        cur_ex++;
    }
    
    //Output totals but make sure there was at least one exercise!
    if (tot_ex <= 0)
        cout<<"There were no exercises!\n";
    else {
        //Calculate the percentage total
        p_total = (usr_scr/max_scr)*100; //Convert from decimal to percentage
        
        //Output total
        cout<<"Your total is "<<usr_scr<<" out of "<<max_scr<<", or "
            <<p_total<<"%.\n";
    }
    
    //Exit program
    return 0;
}

