/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 27, 2014, 9:11 PM
 * Purpose: Gaddis, 7th Edition, Chapter 3, Problem 11
 *          Covert U.S. dollar amount to Yen and Euros
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
    const float USD_YEN = 101.42, USD_EURO = 0.7326;
    float usd_amt, yen_amt, euro_amt;
    
    //Get amount of USD from user
    cout<<"Please enter an amount in U.S. dollars: ";
    cin>>usd_amt;
    cout<<endl;
    
    //Calculate the equivalent amount in the Yen and Euro
    yen_amt = usd_amt*USD_YEN;
    euro_amt = usd_amt*USD_EURO;
    
    //Formate cout for currency
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    //Output these values to the user
    cout<<"The equivalent amount in Yen is: "<<yen_amt<<endl;
    cout<<"The equivalent amount in Euros is: "<<euro_amt<<endl;
    
    //Exit program
    return 0;
}

