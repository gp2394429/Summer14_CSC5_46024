/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 1, 2014, 12:36 AM
 * Purpose: Gaddis, 7th Edition, Chapter 4, Problem 18
 *          For an input of a wavelength in meters, determine
 *          what type of radiation it is
 */

//System Level Libraries 
#include <iostream>
#include <string>
using namespace std;

//User Defined Libraries

//Global Constants
const double GAM_UB = 1e-11,//Upper bound on Gamma Rays
             X_UB = 1e-8,//Upper bound on X Rays
             UV_UB = 4e-7,//Upper bound on Ultraviolet radiation
             VL_UB = 7e-7,//Upper bound on Visible Light
             IR_UB = 1e-3,//Upper bound on Infrared radiation
             MW_UB = 1e-2;//Upper bound on Microwaves

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    double wav_len; //Wavelength given by user
    string rad_type; //Radiation type
    
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
    
    //Exit program
    return 0;
}

