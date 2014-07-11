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
#include <cstring>
#include <fstream>
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
double infRate(float prc_lst_yr, float prc_cur);//Problem asks for double specifically

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
double fracToDec(int whole, int numer, int denom);//Problem asks for double specifically

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
        cout<<"1.  Savitch, 8thEd, Chapter 4, Problem 1\n";
        cout<<"2.  Savitch, 8thEd, Chapter 4, Problem 3\n";
        cout<<"3.  Savitch, 8thEd, Chapter 4, Problem 4\n";
        cout<<"4.  Savitch, 8thEd, Chapter 4, Problem 7\n";
        cout<<"5.  Savitch, 8thEd, Chapter 4, Problem 8\n";
        cout<<"6.  Gaddis,  7thEd, Chapter 5, Problem 1\n";
        cout<<"7.  Gaddis,  7thEd, Chapter 5, Problem 2\n";
        cout<<"8.  Gaddis,  7thEd, Chapter 5, Problem 15\n";
        cout<<"9.  Gaddis,  7thEd, Chapter 5, Problem 18\n";
        cout<<"10. Gaddis,  7thEd, Chapter 5, Problem 26\n";
        cout<<"11. Quit the program\n";
        cout << "Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cout<<endl;
        
        //Begin menu
        switch(m_choice){
            case(1):{
                //Short problem description
                cout<<"Calculate the miles per gallon of a car given the number\n"
                    <<"of miles driven and liters of gas used.\n\n";
                
                //Begin problem 1
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
                //End problem 1
                break;
            }
            case(2):{
                //Short problem description
                cout<<"Determine the price of a stock given the whole dollar\n"
                    <<"and fractional portion.\n\n";
                
                //Begin problem 2
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
                //End problem 2
                break;
            }
            case(3):{
                //Short problem description
                cout<<"Gauge the percentage inflation given the price of an\n"
                    <<"item currently and the price of an item from a year \n"
                    <<"ago.\n\n";
                
                //Begin problem 3
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
                //End problem 3
                break;
            }
            case(4):{
                //Short problem description
                cout<<"Calculate the gravitational force between two objects.\n\n";
                
                //Begin problem 4
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
                //End problem 4
                break;
            }
            case(5):{
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
            case(6):{
                //Short problem description
                cout<<"Display the characters for each ASCII code from 32 and 127.\n";
                
                //Begin problem 6
                //Declare variables
                const int START = 32;//Start at ASCII code 36
                const int FINISH = 127;//End the loop when count is greater than this
                const int LINEBREAK = 16;//New line every 16 characters
                int count = START;//Count for the for loop
                //Enter program loop
                for(count;count<=FINISH;count++){
                    //Ensure a new line every 16 characters
                    if (((count-START)%LINEBREAK == 0))
                        cout<<endl;
                    
                    //Output an ASCII character followed by a space
                    cout<<static_cast<char>(count)<<" ";
                }
                //End problem 6
                //Two newlines to make the output pretty
                cout<<endl<<endl;
                break;
            }
            case(7):
            {
                //Short problem description
                cout<<"Sum all the integers from 1 to a given integer.\n\n";
                //Begin problem 7
                //Declare variables
                //Inputs
                int num;//Integer to sum to
                //Outputs
                unsigned int sum = 0;//The sum to output
                
                //Get the number to sum to from the user and verify it is not less than one
                do{
                    cout<<"Please enter an integer of 1 or greater: ";
                    cin>>num;
                }while(num<1);
                
                //Sum to the given integer
                for(num;num>=1;num--)
                    sum+=num;
                
                //Output the result
                cout<<"The sum is: "<<sum<<endl;
                
                //End problem 7
                cout<<endl;
                break;
            }
            case(8):
            {
                //Short problem description
                cout<<"Calculate the size of a population each day for a given number\n"
                    <<"of days, the original population size, and percent increase in\n"
                    <<"daily population, and number.\n\n";
                //Begin problem 8
                //Declare variables
                //Inputs
                int n_days;//Number of days
                float pop_size;//Population size
                float pct_inc;//Percent increase per day
                
                //Get number of days, population size, and percent increase per day 
                //Validate that the population size is >= 2
                do{
                    cout<<"What is the starting population?: ";
                    cin>>pop_size;
                }while(pop_size<2);
                //Validate that the percent increase is non-negative
                do{
                    cout<<"What is the percent increase per day?: ";
                    cin>>pct_inc;
                }while(pct_inc<0);
                //Validate that the number of days is not < 1
                do{
                    cout<<"How many days would you like to track the growth?: ";
                    cin>>n_days;
                }while(n_days<1);
                cout<<endl;
                
                //Calculate and print the population on each day tracked
                for(int count = 1;count<=n_days;count++){
                    cout<<"Day "<<count<<": "<<static_cast<int>(pop_size)<<endl;
                    pop_size+=pop_size*(pct_inc/DEC_PCT_CNV);
                }
                //End problem 8
                cout<<endl;
                break;
            }
            case(9):
            {
                //Short problem description
                cout<<"Display a rectangle of dimensions MxN where M and N are inputs\n"
                    <<"and are >= 2 and <= 10, using the larger number as the length.\n\n";
                //Begin problem 9
                //Declare variables
                //Inputs
                unsigned short len;//Length of the rectangle
                unsigned short wid;//Width of the rectangle
                
                //Get length and width from user and check for errors
                do{
                cout<<"Enter the length and width of the rectangle (between 2 and 10): ";
                cin>>len>>wid;
                cout<<endl;
                }while(len<2||len>10||wid<2||wid>10);
                
                //Switch length and width if width is greater than length
                if(wid>len){
                    unsigned short temp = len;//Switching variable
                    len = wid;
                    wid = temp;
                }
                
                //Output the rectangle to the screen
                for(unsigned short c1 = 0;c1<wid;c1++){
                    cout<<"     ";
                    for(unsigned short c2 = 0;c2<len;c2++){
                        cout<<"X";
                    }
                    cout<<endl;
                }
                //End problem 9
                cout<<endl;
                break;
            }
            case(10): {
                //Short problem description
                cout<<"Read students first names from a file and determine which should\n"
                    <<"be first in line and which should be last alphabetically.\n\n";
                //Begin problem 10
                //Declare variables
                const unsigned short N_SIZE = 25;//Maximum size for a name including delimiter
                char c_name[N_SIZE];//The current name being read by the file
                //Inputs
                ifstream in_file;//In input file
                //Outputs
                char f_line[N_SIZE];//The current candidate for who is first in line
                char l_line[N_SIZE];//The current candidate for who is last in line
                
                //Open the input file and test for errors
                in_file.open("LineUp.dat");
                if(!in_file)
                    cout<<"Error opening file."<<endl;
                else {
                    //Read the first name and set it to both the first and last in line
                    in_file>>c_name;
                    strcpy(f_line,c_name);
                    strcpy(l_line,c_name);
                    
                    //Loop through the file reading in names
                    while(in_file>>c_name) {
                        //Check to see if the current name should be the first or last in line
                        if(strcmp(c_name,f_line)<0)
                            strcpy(f_line,c_name);//Set the first in line to be the current name
                        if(strcmp(c_name,l_line)>0)
                            strcpy(l_line,c_name);//Set the last in line to be the current name
                    }

                    //Output the names of the people first and last in line
                    cout<<"First in line: "<<f_line<<endl;
                    cout<<"Last in line: "<<l_line<<endl;
                    
                    //Close the input file
                    in_file.close();
                }
                //End problem 10
                cout<<endl;
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
                //In case of bad input
                cin.clear();//Remove the error flag on bad input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');//Skip to the next newline character
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

