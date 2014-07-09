/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 7, 2014, 2:50 AM
 * Purpose: Assignment # Summer CSC-5 46024 
 */

//System Level Libraries 
#include <iostream>
#include <limits>//Used for simple bad input handling
#include <cstdlib>
#include <ctime>
using namespace std;

//User Defined Libraries

//Global Constants
const unsigned short DEC_PCT_CNV = 100;//Conversion from decimal to percentage value
const float LTR_GLN_CNV = 0.264179;//Conversion from liters to gallons
const float UNI_GRAV = 6.673e-8f;//Universal gravitational constant(in cm^3/(g*sec^2))
//Function Prototypes

//Generally useful function, not specific to any problem
//Determine if the user wishes to repeat the calculation with a simple
//yes or no answer
bool repeatYN();

//Used in problem 1
//Calculate the inflation rate as the current price minus the price
//from last year divided by the price from last year
double infRate(float prc_lst_yr, float prc_cur);

//Used in problem 2
//Calculate and return the gravitational force between two objects given
//their masses(in grams) and the distance between them(in centimeters)
float gForce(float mass_1, float mass_2, float dist);

//Used in problem 3
//Calculate miles per gallon given miles and liters of gas used
float mpg(int miles, int liters);


//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    unsigned short m_choice;
    bool m_running = true; //The status of the menu loop
    //Enter menu loop
    while (m_running) {
        cout<<"1.  Savitch, 8thEd, Chapter 4, Problem 4\n";
        cout<<"2.  Savitch, 8thEd, Chapter 4, Problem 7\n";
        cout<<"3.  Savitch, 8thEd, Chapter 4, Problem 1\n";
        //cout<<"4.  Gaddis,  7thEd, Chapter 4, Problem 8\n";
        //cout<<"5.  Gaddis,  7thEd, Chapter 4, Problem 18\n";
        //cout<<"6.  Savitch, 8thEd, Chapter 3, Problem 1\n";
        //cout<<"7.  Savitch, 8thEd, Chapter 3, Problem 2\n";
        //cout<<"8.  Savitch, 8thEd, Chapter 3, Problem 12\n";
        //cout<<"9.  Savitch, 8thEd, Chapter 3, Problem 15\n";
        //cout<<"10. Savitch, 8thEd, Chapter 3, Problem 16\n";
        //cout<<"11. Quit the program\n";
        cout << "Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cout<<endl;

        switch (m_choice) {
            case(1): {
                //Short problem description
                cout<<"Gauge the percentage inflation given the price of an\n"
                    <<"item currently and the price of an item from a year \n"
                    <<"ago.\n\n";
                //Begin problem 1
                //Declare variables
                bool running = true;//Status of whether the program should continue running
                //Inputs
                float prc_lst_yr;//Price last year
                float prc_cur;//Price currently
                //Enter program loop
                while(running) {
                    //Get the current and last years price for the item
                    cout<<"How much did the item cost last year?: ";
                    cin>>prc_lst_yr;
                    cout<<"How much does the item cost now?: ";
                    cin>>prc_cur;
                    cout<<endl;
                    //Output the inflation rate
                    cout<<"The inflation rate is about: "
                        <<infRate(prc_lst_yr, prc_cur)<<"%\n";
                    //Determine if the user wants to run the program again
                    cout<<"Would you like to calculate the inflation rate "
                        <<"of another item?\n";
                    running = repeatYN();//Answer a simple Y/N to find out if the user wants to continue
                    cout<<endl;
                    }
                //End problem 1
                break;
            }
            case(2):
            {
                //Short problem description
                cout<<"Calculate the gravitational force between two objects.\n\n";
                //Begin problem 2
                //Declare variables
                //Inputs
                float mass_1, mass_2;//Masses of the two objects(in grams)
                float dist; //Distance between the two objects(in centimeters)
                bool running = true;//Status of whether the program should continue running
                //Enter program loop
                while(running) {
                    //Get input from user
                    cout<<"What is the mass of the first object(in grams)?: ";
                    cin>>mass_1;
                    cout<<"What is the mass of the second object(in grams)?: ";
                    cin>>mass_2;
                    cout<<"What is the distance between the two objects(in centimeters)?: ";
                    cin>>dist;
                    cout<<endl;
                    //Output the gravitational force between the two objects(in dynes)
                    cout<<"The gravitational force between the two objects is: "
                        <<gForce(mass_1, mass_2, dist)<<" dyn.\n";
                    //Determine if the user would like to run the program again
                    cout<<"Would you like to repeat this calculation?\n";
                    running = repeatYN();
                }
                //End problem 2
                break;
            }
            case(3):
            {
                //Short problem description
                cout<<"Calculate the miles per gallon of a car given the number\n"
                    <<"of miles driven and liters of gas used.\n\n";
                //Begin problem 3
                //Declare variables
                bool running = true;//Status of whether the program should continue running
                //Inputs
                int miles;//Miles driven
                int liters;//Liters of gas used
                //Enter program loop
                while(running) {
                    //Get miles and liters from user
                    cout<<"How many miles did you drive?: ";
                    cin>>miles;
                    cout<<"How many liters of gas did the car use?: ";
                    cin>>liters;
                    cout<<endl;
                    //Output the miles per gallon of the car
                    cout<<"Your car gets about: "<<mpg(miles, liters)
                        <<" miles per gallon\n";
                    //Determine if the user wants to run the program again
                    cout<<"Would you like to repeat this calculation?\n";
                    running = repeatYN();
                }
                //End problem 3
                break;
            }
            case(4):
            {
                //Short problem description
                //Begin problem 4
                //End problem 4
                break;
            }
            case(5):
            {
                //Short problem description
                //Begin problem 5
                //End problem 5
                break;
            }
            case(6):
            {
                //Short problem description
                //Begin problem 6
                //End problem 6
                break;
            }
            case(7):
            {
                //Short problem description
                //Begin problem 7
                //End problem 7
                break;
            }
            case(8):
            {
                //Short problem description
                //Begin problem 8
                //End problem 8
                break;
            }
            case(9):
            {
                //Short problem description
                //Begin problem 9
                //End problem 9
                break;
            }
            case(10):
            {
                //Short problem description
                //Begin problem 10
                //End problem 10
                break;
            }
            case(11):
                m_running = false;
                break;
            default:
                cout<<"Unknown input, please try again.\n\n";
        }
        cout<<endl;
        //In case of bad input
        cin.clear();//Remove the error flag on bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//Skip to the next newline character
    }
    //Exit program
    cout << "Exiting program\n";
    return 0;
}
//Function definitions
//General
bool repeatYN() {
    char usr_ipt;//User input
    //Run until there is a returned value
    while(true){
        //Get user input
        cout<<"Please enter Y/N: ";
        cin>>usr_ipt;
        switch(usr_ipt) {
            case('Y'):case('y'):
                return true;
                break;
            case('N'):case('n'):
                return false;
                break;
            default:
                cout<<"Invalid input.\n";
        }
    }
}
//Problem 1 functions
double infRate(float prc_lst_yr, float prc_cur) {
    return ((prc_cur-prc_lst_yr)/prc_lst_yr)*DEC_PCT_CNV;
}
//Problem 2 functions
float gForce(float mass_1, float mass_2, float dist) {
    return (UNI_GRAV*mass_1*mass_2)/(dist*dist);
}
//Problem 3 functions
float mpg(int miles, int liters) {
    return miles/(liters*LTR_GLN_CNV);
}

