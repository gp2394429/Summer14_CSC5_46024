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

//Used in problem 4
//Determine the decimal value of a number given the whole value and
//fractional part
double fracToDec(int whole, int numer, int denom);

//Used in problem 5
//Calculate an interest payment as the initial loan balance times the
//interest rate
float istPymt(int init_bal, float ist_rate);
//Calculate the annual mortgage cost as the 3% of the initial loan balance
//credited toward paying off the principle, plus the interest payment
float anMorCst(int init_bal, float ist_pymt);
//Calculate the tax savings as the interest payment times the marginal
//tax rate
float taxSave(float ist_pymt, float tax_rate);

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
        cout<<"4.  Savitch, 8thEd, Chapter 4, Problem 3\n";
        cout<<"5.  Savitch, 8thEd, Chapter 4, Problem 8\n";
        cout<<"6.  Gaddis,  7thEd, Chapter 5, Problem 1\n";
        //cout<<"7.  Savitch, 8thEd, Chapter 3, Problem 2\n";
        //cout<<"8.  Savitch, 8thEd, Chapter 3, Problem 12\n";
        //cout<<"9.  Savitch, 8thEd, Chapter 3, Problem 15\n";
        //cout<<"10. Savitch, 8thEd, Chapter 3, Problem 16\n";
        cout<<"11. Quit the program\n";
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
                    cout<<endl;
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
                    cout<<endl;
                }
                //End problem 3
                break;
            }
            case(4):
            {
                //Short problem description
                cout<<"Determine the price of a stock given the whole dollar\n"
                    <<"and fractional portion.\n\n";
                //Begin problem 4
                //Declare variables
                bool running = true;//Status of whether the program should continue running
                //Inputs
                int shr_own;//Number of the shares owned
                int wl_dol;//Whole dollar value of the stock
                int numer;//Numerator of the fractional part
                int denom;//Denominator of the fractional part
                //Outputs
                double tot_val;//Total value of the user's holdings
                //Enter program loop
                while(running) {
                    //Get number of shares owned and the whole dollar and fractional part 
                    cout<<"Enter how many shares you own: ";
                    cin>>shr_own;
                    cout<<"Enter the whole dollar value of the stock: ";
                    cin>>wl_dol;
                    cout<<"Enter the numerator of the fractional part: ";
                    cin>>numer;
                    cout<<"Enter the denominator of the fractional part: ";
                    cin>>denom;
                    cout<<endl;
                    //Calculate the total value of the users holdings
                    tot_val = fracToDec(wl_dol, numer, denom)*shr_own;
                    //Output the dollar value in decimal form
                    cout<<"The total value of your holdings is: $"<<tot_val<<endl;
                    //Determine if the user wants to repeat the program
                    cout<<"Would you like to repeat this calculation?\n";
                    running = repeatYN();
                    cout<<endl; 
                }
                //End problem 4
                break;
            }
            case(5):
            {
                //Short problem description
                cout<<"Determine the annual after-tax cost of a new house for\n"
                    <<"the first year of ownership.\n\n";
                //Begin problem 5
                //Declare variables
                const float TAX_RATE = 3.5e-1f;//Marginal tax rate
                const float IST_RATE = 6e-2f;//Interest rate
                bool running = true;//Status of whether the program should continue running
                int init_bal;//Initial loan balance
                float ist_pymt;//Interest payment
                //Inputs
                int hse_prc;//Cost of the house
                int dwn_pymt;//Down payment on the house
                //Output
                float an_cst;//Total annual cost
                while(running){
                    //Get the house price and down payment from user
                    cout<<"How much did the house cost?: ";
                    cin>>hse_prc;
                    cout<<"How much was the down payment?: ";
                    cin>>dwn_pymt;
                    cout<<endl;
                    //Calculations
                    init_bal = hse_prc-dwn_pymt;//Calculate initial balance
                    ist_pymt = istPymt(init_bal, IST_RATE);//Calculate the interest payments
                    //Total after tax payment is total payment minus tax deductions
                    an_cst = anMorCst(init_bal, ist_pymt)-taxSave(ist_pymt, TAX_RATE);
                    //Output the result
                    cout<<"The total after-tax cost of your new house for the "
                        <<"first year is: $"<<an_cst<<endl;
                    //Determine if the user wants to run the program again
                    cout<<"Would you like to repeat this calculation?\n";
                    running = repeatYN();
                    cout<<endl;
                }
                //End problem 5
                break;
            }
            case(6):
            {
                //Short problem description
                cout<<"Display the characters for each ASCII code from 32 and 127.\n\n";
                //Begin problem 6
                //Declare variables
                const int START = 32;//Start at ASCII code 36
                const int FINISH = 127;//End the loop when count is greater than this
                const int LINEBREAK = 16;//New line every 16 characters
                //Enter program loop
                for(int count = START;count<=FINISH;count++){
                    //Ensure a new line every 16 characters
                    if (((count-START)%LINEBREAK == 0))
                        cout<<endl;
                    //Print out an ASCII character followed by a space
                    cout<<static_cast<char>(count)<<" ";
                }
                //Pretty printing
                cout<<endl<<endl;
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
//Problem 4 functions
double fracToDec(int whole, int numer, int denom) {
    return (whole+(static_cast<double>(numer)/denom));
}
//Problem 5 functions
float istPymt(int prnpl, float ist_rate){
    return prnpl*ist_rate;
}

float anMorCst(int ln_bal, float ist_pymt){
    //Assume 3% credit towards the principal
    const float PNL_CRE = 3e-2f;
    return ist_pymt+(ln_bal*PNL_CRE);
}

float taxSave(float ist_pymt, float tax_rate){
    return ist_pymt*tax_rate;
}

