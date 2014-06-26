/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 26, 2014, 3:09 PM
 * Purpose: Savitch, 8th Edition, Chapter 2, Problem 1
 *          Calculate and display the weight of cereal in
 *          metric tons and the total amount of cereal in
 *          a metric ton given an input of the weight of the
 *          cereal in ounces.
 */

//System Level Libraries 
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants
const float M_TON = 35273.92; //Metric ton in ounces

//Function Prototypes

//Begin Execution
int main(int argc, char** argv) {
    
    //Declare variables
    double c_wht_oz; //Cereal weight in ounces
    double c_wht_mt; //Cereal weight in metric tons
    double num_box; //Number of boxes of the cereal to equal a metric ton.
    char cont = 'y';
    
    //Begin IO loop
    while (cont == 'y') {
        //Get cereal weight in ounces
        cout<<"What is the cereal's weight(in ounces)?: ";
        cin>>c_wht_oz;
        
        //Calculate cereal weight in metric tons and number of boxes in
        //a metric ton
        c_wht_mt = c_wht_oz/M_TON;
        num_box = M_TON/c_wht_mt;
        
        //Output results
        cout<<"The weight of the cereal in metric tons is: "<<c_wht_mt<<endl;
        cout<<"The number of boxes in a metric ton is: "<<num_box<<endl;
        
        //Does the user wish to continue?
        cout<<"Do you wish to continue?\n";
        cout<<"Enter y if so: ";
        cin>>cont;
    }
    
    cout<<"Good bye!\n";
    //Exit program
    return 0;
}

