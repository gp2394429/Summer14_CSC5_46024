/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 2, 2014, 10:51 PM
 * Purpose: Assignment 3 for Summer CSC-5 46024
 */

//System Level Libraries 
#include <iostream>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    char m_choice;
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
        cout<<"11. Quit the program"
        cout<<"Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cout<<endl;
        
        switch(m_choice) {
            case('1'):
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
                break;
            case('2'):
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
                cout<<(weight > W_MAX)?"The object is too heavy!\n":
                      (weight < W_MIN)?"The object is too light!\n":
                                       "The object is just right!\n";
                //End problem 2
                break;
            case('3'):
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
                break;
            case('4'):
                //Begin problem 4
                //Declare variables
                const int MAX_RNG = 41;//Upper bound exclusive for random range
                int r_num_1, r_num_2;//Random numbers
                //Output
                int answer//Correct answer
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
                cout<<(usr_ans == answer)?"Congratulations, you got it!\n":
                                          "Nice try, but the answer is actually: "
                                          <<answer<<endl;
                //End problem 4
                break;
            case('5'):
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
                break;
            case('6'):
            case('7'):
            case('8'):
            case('9'):
            case('10'):
            case('11'):
                m_running = false;
                break;
            default:
                cout<<"Unknown input\n";
        }
    }
    //Exit program
    cout<<"Exiting program\n";
    return 0;
}

