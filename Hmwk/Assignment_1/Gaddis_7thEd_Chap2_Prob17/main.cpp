/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 25, 2014, 11:54 PM
 * Purpose: Gaddis, 7th Edition, Chapter 2, Problem 17
 *          Calculate and display the cost of buying
 *          some stock
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
    short stk_amnt = 600;
    float stk_price = 21.77, cmision = 2e-2f, stk_cost, cmision_cost, total;
    
    //Calculate stock cost, commission cost, and total cost
    stk_cost = stk_amnt * stk_price;
    cmision_cost = stk_cost * cmision;
    total = stk_cost + cmision_cost;
    
    //Format cout for dollar amount
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    //Output stock cost, commission cost and total cost to the screen
    cout<<"Cost of stock (without commission): $"<<stk_cost<<endl;
    cout<<"Cost of commission: $"<<cmision_cost<<endl;
    cout<<"Total cost: $"<<total<<endl;
    
    //Exit program
    return 0;
}

