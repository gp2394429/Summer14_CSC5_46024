/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 25, 2014, 7:21 PM
 * Purpose: Gaddis, 7th Edition, Chapter 2, Problem 8
 *          Calculate the total sales price given
 *          the price of the items and the sales tax
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
    float item_1 = 12.95, item_2 = 24.95, item_3 = 6.95,
          item_4 = 14.95, item_5 = 3.95, tax = 6e-2f, subtotal, 
          tax_total, total;
    
    //Calculate subtotal, tax on the subtotal, and the total price
    subtotal = item_1 + item_2 + item_3 + item_4 + item_5; //Calculate subtotal
    tax_total = subtotal*tax; //Calculate the tax on the subtotal
    total = subtotal+tax_total; //Calculate the total price
    
    //Set cout format for dollar value
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    //Output item costs, subtotal, total tax, and total
    cout << "Price of item 1: $" << item_1 << endl;
    cout << "Price of item 2: $" << item_2 << endl;
    cout << "Price of item 3: $" << item_3 << endl;
    cout << "Price of item 4: $" << item_4 << endl;
    cout << "Price of item 5: $" << item_5 << endl;
    cout << "The subtotal is: $" << subtotal << endl;
    cout << "The total tax is: $" << tax_total << endl;
    cout << "The total is: $" << total << endl;
    
    //Exit program
    return 0;
}

