/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 29, 2014, 12:44 AM
 * Purpose: Savitch, 8th Edition, Chapter 3, Problem 2
 *          Calculate interest due, amount due, and minimum
 *          payment due on a credit account.
 */

//System Level Libraries 
#include <iostream>
#include <iomanip>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    const float INST_1000 = 1.5e-2, INST_OVER = 1e-2, PAY_MUL = 1e-1;
    const int DUE_TH = 10, BAL_TH = 1000;
    double inst_due, tot_due, min_pay, balance;
    char cont = 'y';
    
    //Enter program loop
    while (cont == 'y' || cont == 'Y') {
        //Get balance from user
        cout<<"What is the balance for your account?: $";
        cin>>balance;
        
        //Calculate interest due
        inst_due = balance * INST_1000; //Interest on first $1000
        if (balance >= BAL_TH) //Is the balance greater than $1000?
            inst_due += ((balance - BAL_TH) * INST_OVER); //Interest on the rest
        
        //Calculate total amount due
        tot_due = balance + inst_due;
        
        //Calculate minimum payment
        if (tot_due <= DUE_TH)
            min_pay = tot_due;
        else
            min_pay = tot_due * PAY_MUL;
        
        //Format output for currency
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        //Output result
        cout<<"Balance:          "<<setw(8)<<balance<<endl;
        cout<<"Interest due:     "<<setw(8)<<inst_due<<endl;
        cout<<"Total amount due: "<<setw(8)<<tot_due<<endl;
        cout<<"Minimum payment:  "<<setw(8)<<min_pay<<endl;
        
        //Repeat the calculation?
        cout<<"Would you like to repeat the calculation?\n";
        cout<<"If yes, enter y: ";
        cin>>cont;
    }
    cout<<"Exiting program.\n";
    
    //Exit program
    return 0;
}

