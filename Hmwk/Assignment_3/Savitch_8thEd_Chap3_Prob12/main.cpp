/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 30, 2014, 9:02 PM
 * Purpose: Savitch, 8th Edition, Chapter 3, Problem 12
 *          Approximate the value of pi to n terms using
 *          the formula 4(1-(1/3)+(1/5)-...+((-1)^n)/(2n+1))
 */

//System Level Libraries
#include <iostream>//Input Output Library
#include <cmath>//Needed for the pow() function
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Execution Begins

int main(int argc, char** argv) {
    //Declare variables
    int n_terms;
    double pi;
    bool running = true; //Our program is running until the user says otherwise
    
    while(running) {
        pi = 0;//Our initial approximation for pi
        //Get the number of terms to approximate from the user
        cout<<"Enter the number of terms to approximate pi: ";
        cin>>n_terms;
        cout<<endl;
    
        //For n_terms >= 0, calculate (-1^n)/(2n+1), add it to pi,
        //and decrement n_terms
        for(n_terms;n_terms>=0;n_terms--) {
            pi+=(pow(-1,n_terms))/(2*n_terms+1);
         }
         
         //To complete the formula, multiply the value of pi by 4
         pi*=4;
         
         //Output the approximated value of pi to the user
         cout<<"The approximate value of pi is: "<<pi<<endl;
         
         //See if the user is done
         char cont; //User input to determine if they are done
         cout<<"Would you like to make another approximation of pi?\n";
         cout<<"Enter y if yes: ";
         cin>>cont;
         cout<<endl;
         //If the user doesn't enter N or n, continue running the program
         running=(cont=='Y'||cont=='y'); 
         }
    
    //Exit program
    return 0;
}

