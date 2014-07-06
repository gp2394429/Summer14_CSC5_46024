/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 2, 2014, 10:51 PM
 * Purpose: Assignment 3 for Summer CSC-5 46024
 */

//System Level Libraries 
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    unsigned short m_choice;
    bool m_running = true; //The status of the menu loop
    //Enter menu loop
    while(m_running) {
        cout<<"1.  Gaddis,  7thEd, Chapter 4, Problem 4\n";
        cout<<"2.  Gaddis,  7thEd, Chapter 4, Problem 6\n";
        cout<<"3.  Gaddis,  7thEd, Chapter 4, Problem 7\n";
        cout<<"4.  Gaddis,  7thEd, Chapter 4, Problem 8\n";
        cout<<"5.  Gaddis,  7thEd, Chapter 4, Problem 18\n";
        cout<<"6.  Savitch, 8thEd, Chapter 3, Problem 1\n";
        cout<<"7.  Savitch, 8thEd, Chapter 3, Problem 2\n";
        cout<<"8.  Savitch, 8thEd, Chapter 3, Problem 12\n";
        cout<<"9.  Savitch, 8thEd, Chapter 3, Problem 15\n";
        cout<<"10. Savitch, 8thEd, Chapter 3, Problem 16\n";
        cout<<"11. Quit the program\n";
        cout<<"Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cout<<endl;
        
        switch(m_choice) {
            case(1): {
                //Begin problem 1
                //Declare variables
                //Inputs
                float len_1, len_2, wid_1, wid_2;//Lengths and widths
                //Outputs
                float area_1, area_2;
                //Get lengths and widths from the user
                cout<<"What are the dimensions of the first rectangle?\n";
                cout<<"Format: width length ";
                cin>>wid_1>>len_1;
                cout<<"What are the dimensions of the second rectangle?\n";
                cout<<"Format: width length ";
                cin>>wid_2>>len_2;
                cout<<endl;
                //Calculate area = width * length
                area_1 = wid_1 * len_1;
                area_2 = wid_2 * len_2;
                //Determine if the areas or the same or if one is larger 
                //and output the result
                if (area_1 == area_2)
                    cout<<"The areas are the same, and are: "<<area_1<<endl;
                else if (area_1 > area_2)
                    cout<<"The first rectangle has greater area, and it is: "
                        <<area_1<<endl;
                else
                    cout<<"The second rectangle has greater area, and it is: "
                        <<area_2<<endl;
                //End problem 1
                cout<<endl;
            }
                break;
            case(2): {
                //Begin problem 2
                //Declare variables
                const float E_GRAV = 9.8;//Gravity on earth in m/s
                const int W_MAX = 1000;//Upper bound for the weight
                const int W_MIN = 10;//Lower bound for the weight
                //Inputs
                float mass; 
                //Outputs
                float weight;
                //Get the mass of the object from the user
                cout<<"What is the mass of the object(in kg)?: ";
                cin>>mass;
                cout<<endl;
                //Calculate the weight = mass * gravity in newtons
                weight = mass * E_GRAV;
                //Output weight
                cout<<"The weight of the object is: "<<weight<<" N\n";
                //Determine if the object is above 1000N or below 10N and
                //output the result
                if (weight > W_MAX)
                    cout<<"The object is too heavy!\n";
                if (weight < W_MIN)
                    cout<<"The object is too light!\n";
                //End problem 2
                cout<<endl;
            }
                break;
            case(3): {
                //Begin problem 3
                //Declare variables
                const int SEC_DAY = 86400;//Seconds in a day
                const int SEC_HR = 3600; //Seconds in an hour
                const int SEC_MIN = 60;//Seconds in a minute
                //Inputs
                float seconds;
                //Get the number of seconds from the user
                cout<<"Enter a number in seconds: ";
                cin>>seconds;
                cout<<endl;
                //Determine the number of days or hours or minutes for the
                //given value of seconds, and output the result to the screen
                if (seconds >= SEC_DAY)
                    cout<<"There are "<<(seconds/SEC_DAY)<<" days ";
                else if (seconds >= SEC_HR)
                    cout<<"There are "<<(seconds/SEC_HR)<<" hours ";
                else if (seconds >= SEC_MIN)
                    cout<<"There are "<<(seconds/SEC_MIN)<<" minutes ";
                else
                    cout<<"Well... There are certainly "<<seconds<<" seconds ";
                cout<<"in "<<seconds<<" seconds!\n";
                //End problem 3
                cout<<endl;
            }
                break;
            case(4): {
                //Begin problem 4
                //Declare variables
                const int MAX_RNG = 41;//Upper bound exclusive for random range
                int r_num_1, r_num_2;//Random numbers
                //Output
                int answer;//Correct answer
                int usr_ans;//The user's answer
                //Set up random number generator
                srand(time(0));
                //Calculate two random numbers in the range 10-50 and calculate
                //the sum of these two numbers
                r_num_1 = (rand() % MAX_RNG) + 10;
                r_num_2 = (rand() % MAX_RNG) + 10;
                answer = r_num_1 + r_num_2;
                //Display these numbers to the user and ask the user to solve 
                //the addition problem
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
                //End problem 4
                cout<<endl;
            }
                break;
            case(5): {
                //Begin problem 5
                //Declare variables
                const float GAM_UB = 1e-11;//Upper bound on Gamma Rays
                const float X_UB = 1e-8;//Upper bound on X Rays
                const float UV_UB = 4e-7;//Upper bound on Ultraviolet radiation
                const float VL_UB = 7e-7;//Upper bound on Visible Light
                const float IR_UB = 1e-3;//Upper bound on Infrared radiation
                const float MW_UB = 1e-2;//Upper bound on Microwaves
                //Inputs
                float wav_len;//Wavelength given by user
                //Outputs
                string rad_type;//Radiation type
                //Get wavelength from user
                cout<<"Please enter a wavelength(in meters): ";
                cin>>wav_len;
                cout<<endl;
                //Determine what type of radiation the given wavelength is
                rad_type=(wav_len<=GAM_UB)?"Gamma Rays":
                         (wav_len<=X_UB)?"X Rays":
                         (wav_len<=UV_UB)?"Ultraviolet":
                         (wav_len<=VL_UB)?"Visible Light":
                         (wav_len<=IR_UB)?"Infrared":
                         (wav_len<=MW_UB)?"Microwaves":"Radio Waves";
                //Output the radiation type to the screen
                cout<<"The type of radiation is: "<<rad_type<<endl;
                //End problem 5
                cout<<endl;
            }
                break;
            case(6): {
                //Start problem 6
                //Declare variables
                //Certain comments are used many times, so define them as variables
                string PPR_WIN = "Paper covers rock, ";
                string RCK_WIN = "Rock breaks scissors, ";
                string SCR_WIN = "Scissors cuts paper, ";
                string P1_WIN = "player one wins!\n";
                string P2_WIN = "player two wins!\n";
                string NB_WIN = "Nobody wins.\n";
                string IE_P1 = "Invalid entry for player 1!\n";
                string IE_P2 = "Invalid entry for player 2!\n";
                bool running = true;//Should the program continue running?
                //Inputs
                char p1_entry, p2_entry;//Player entries
                char quit;//Used to determine if the user wants to quit
                //Output welcome message
                cout<<"Let's play Rock, Paper, Scissors!\n\n";
                //Enter game loop
                while (running) {
                    //Get user input
                    cout<<"Enter R for rock, P for paper, or S for scissors.\n";
                    cout<<"Player 1 entry: ";
                    cin>>p1_entry;
                    cout<<"Player 2 entry: ";
                    cin>>p2_entry;
                    cout<<endl;
                    //Determine who won and how
                    switch (p1_entry) {
                        case 'R':
                        case 'r':
                            switch (p2_entry) {
                                case 'R':   
                                case 'r':
                                    cout<<NB_WIN;
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<(PPR_WIN + P2_WIN);
                                    break;
                                case 'S':
                                case 's':
                                    cout<<(RCK_WIN + P1_WIN);
                                    break;
                                default:
                                    cout<<IE_P2;
                            }
                            break;
                        case 'P':
                        case 'p':
                            switch (p2_entry) {
                                case 'R':
                                case 'r':
                                    cout<<(PPR_WIN + P1_WIN);
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<NB_WIN;
                                    break;
                                case 'S':
                                case 's':
                                    cout<<(SCR_WIN + P2_WIN);
                                    break;
                                default:
                                    cout<<IE_P2;
                            }
                            break;
                        case 'S':
                        case 's':
                            switch (p2_entry) {
                                case 'R':
                                case 'r':
                                    cout<<(RCK_WIN + P2_WIN);
                                    break;
                                case 'P':
                                case 'p':
                                    cout<<(SCR_WIN + P1_WIN);
                                    break;
                                case 'S':
                                case 's':
                                    cout<<NB_WIN;
                                    break;
                                default:
                                    cout<<IE_P2;
                            }
                            break;
                        default:
                            cout<<IE_P1;
                    }        
                    //Check to see if they want to play again
                    bool valid = false; //Assume a non-valid answer
                    while (!valid) {
                        //Get input from user
                        cout<<endl;
                        cout<<"Would you like to play again?[Y/N]: ";
                        cin>>quit;
                        //Check to see if the input is valid
                        switch (quit) {
                            case 'Y':
                            case 'y':
                                valid = true;
                                break;
                            case 'N':
                            case 'n':
                                cout<<"See you next time.\n";
                                valid = true;
                                running = false; //The program should no longer run
                                break;
                            default:
                                cout<<"Sorry, I didn't get that.\n";                
                        }
                    }
                }
                //End problem 6
                cout<<endl;
            }
                break;
            case(7): {
                //Begin problem 7
                //Declare variables
                const float INST_1000 = 1.5e-2;//Interest up to $1000
                const float INST_OVER = 1e-2;//Interest over $1000
                const float PAY_MUL = 1e-1;//Payment multiplier
                const int DUE_TH = 10;//Due threshold
                const int BAL_TH = 1000;//Balance threshold for normal interest
                //Inputs
                float balance;//Balance on the account
                //Outputs
                float inst_due;//Interest due
                float tot_due;//Total due
                float min_pay;//Minimum payment
                char cont = 'y';//Condition to keep running the program
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
                //End problem 7
                cout<<endl;
            }
                break;
            case(8): {
                //Begin problem 8
                //Declare variables
                bool running = true; //Our program is running until the user says otherwise
                //Inputs
                int n_terms;//The number of terms used to approximate pi
                char cont;//Used to see if the user wants to continue
                //Outputs
                float pi_aprx;//Our approximate value of pi
                while(running) {
                    pi_aprx = 0;//Our initial approximation for pi
                    //Get the number of terms to approximate from the user
                    cout<<"Enter the number of terms to approximate pi: ";
                    cin>>n_terms;
                    cout<<endl;    
                    //For n_terms >= 0, calculate (-1^n)/(2n+1), add it to pi,
                    //and decrement n_terms
                    for(n_terms;n_terms>=0;n_terms--) {
                        pi_aprx+=(pow(-1,n_terms))/(2*n_terms+1);
                    }
                    //To complete the formula, multiply the value of pi by 4
                    pi_aprx*=4;
                    //Output the approximated value of pi to the user
                    cout<<"The approximate value of pi is: "<<pi_aprx<<endl;
                    //See if the user is done
                    cout<<"Would you like to make another approximation of pi?\n";
                    cout<<"Enter y if yes: ";
                    cin>>cont;
                    cout<<endl;
                    //If the user enters Y or y, continue running the program
                    running=(cont=='Y'||cont=='y'); 
                }
                //End problem 8
                cout<<endl;
            }
                break;
            case(9): {
                //Begin problem 9
                //Declare variables
                const float GAMMA = 62.4; //The weight per unit volume of water (lb/ft^3)
                const float PI = 3.14;
                float volume;
                //Inputs
                float radius, weight;
                //Outputs
                float b_force;
                //Get the radius and weight of the sphere from the user
                cout<<"What is the radius of the sphere(in feet)?: ";
                cin>>radius;
                cout<<"What is the weight of the sphere(in pounds)?: ";
                cin>>weight;
                cout<<endl; 
                //Calculate the volume of the sphere = (4/3)*PI*radius^3
                //and the buoyant force = volume*GAMMA
                volume = (4.0/3)*PI*pow(radius,3);
                b_force = volume*GAMMA;
                //The sphere will float if the buoyant force is greater than or
                //equal to the weight of the sphere it will float, otherwise it will sink.
                //Output the buoyancy force and whether it will sink or float to the user
                cout<<"The buoyancy force is: "<<b_force<<" lbs, which means... ";
                cout<<(b_force>=weight?"It floats!":"It sinks!");
                cout<<endl;
                //End Problem 9
                cout<<endl;
            }
                break;
            case(10): {
                //Begin Problem 10
                //Declare variables
                //Start value for celsius is 100 by the problem description
                int celsius = 100; 
                //Output
                int fahrenheit;
                //Decrement celsius and calculate fahrenheit until they are equal
                do {
                celsius--;
                fahrenheit = ((9*celsius)/5)+32;
                } while(celsius!=fahrenheit);
                //Output the temperature where celsius and fahrenheit are equal
                cout<<"Celsius and Fahrenheit temperatures are equal at: "
                    <<celsius<<" degrees.\n";
                //End Problem 10
                cout<<endl;
            }
                break;
            case(11): {
                m_running = false;
            }
                break;
            default: {
                cout<<"Unknown input\n";
            }
        }
    }
    //Exit program
    cout<<"Exiting program\n";
    return 0;
}

