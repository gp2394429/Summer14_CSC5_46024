/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 30, 2014, 12:15 AM
 * Purpose: Gaddis, 7th Edition, Chapter 4, Problem 8
 *          Math tutor program that outputs two random numbers
 *          between 10 and 50 and gets the answer from the 
 *          sum of these two numbers from the user
 */

//System Level Libraries 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    const int MAX_RNG = 41; //We want random numbers in the range 0-40
    unsigned seed; //Seed for the random number generator
    int r_num_1, r_num_2, answer, usr_ans;
    
    //Set up random number generator
    seed = time(0);
    srand(seed);
    
    //Calculate random numbers in the range 10-50, this means we calculate
    //our random numbers as: (rand() % MAX_RNG) + 10. Also calculate the sum
    r_num_1 = (rand() % MAX_RNG) + 10;
    r_num_2 = (rand() % MAX_RNG) + 10;
    answer = r_num_1 + r_num_2;
    
    //Display these numbers to the user and ask the user to solve the addition
    //problem
    cout<<"Welcome to the simple addition math tutor!\n\n";
    cout<<"       "<<r_num_1<<endl;
    cout<<"      +"<<r_num_2<<endl;
    cout<<"       --\n\n";
    cout<<"What is the answer to the above problem?: ";
    cin>>usr_ans;
    cout<<endl;
    
    //Determine if the user is correct
    if (usr_ans == answer)
        cout<<"Congratulations, you got it!\n";
    else
        cout<<"Nice try, but the answer is actually: "<<answer<<endl;
    
    //Exit program
    return 0;
}

