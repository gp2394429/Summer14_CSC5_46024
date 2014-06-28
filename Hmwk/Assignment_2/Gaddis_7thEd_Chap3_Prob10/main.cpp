/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 27, 2014, 8:49 PM
 * Purpose: Gaddis, 7th Edition, Chapter 3, Problem 10
 *          Calculate how many calories were consumed
 *          given the input of how many cookies the user
 *          ate
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
    const int CKE_BAG = 40, SER_BAG = 10, CAL_SER = 300;
    float cal_cke;
    unsigned int cke_ate;
    
    //Calculate the calories per cookie
    cal_cke = static_cast<float>(CAL_SER)/(CKE_BAG/SER_BAG);
    
    //Get the cookies ate by the user
    cout<<"How many cookies did you eat?: ";
    cin>>cke_ate;
    cout<<endl;
    
    //Output the number of calories consumed
    cout<<"You consumed "<<(cke_ate * cal_cke)<<" calories.\n";

    //Exit program
    return 0;
}

