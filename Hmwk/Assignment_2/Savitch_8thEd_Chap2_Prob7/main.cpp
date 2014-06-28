/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on June 27, 2014, 7:44 PM
 * Purpose: Savitch, 8th Edition, Chapter 2, Problem 7
 *          Calculate the amount paid to a worker given
 *          the number of hours worked and number of
 *          dependants
 */

//System Level Libraries 
#include <iostream>
#include <iomanip>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes

//Begin Execution

int main(int argc, char** argv) {
    //Declare variables
    const float HR_WAGE = 16.78, OT_MUL = 1.5, SS_TAX = 6e-2f,
                FI_TAX = 1.4e-1f, SI_TAX = 5e-2f;
    const int NON_OT_HR = 40, UN_DUES = 10, MIN_DEP = 3, DEP_DUES = 35;
    float hr_wrked, grs_pay, tot_pay;
    unsigned int dependants;

    //Get input on hours worked and number of dependants
    cout<<"How many hours did you work this week?: ";
    cin>>hr_wrked;
    cout<<"How many dependants do you have?: ";
    cin>>dependants;
    cout<<endl;
    
    //Calculate gross pay
    if (hr_wrked > NON_OT_HR) {
        float ot_wage = HR_WAGE * OT_MUL, //Overtime wage
              ot_hrs = hr_wrked - NON_OT_HR; //Overtime hours
        grs_pay = (HR_WAGE * NON_OT_HR) + (ot_wage * ot_hrs);
    }
    else
        grs_pay = HR_WAGE * hr_wrked;
    
    //Calculate amount withheld from various taxes and total pay
    float ss_held = grs_pay * SS_TAX, //Withheld for Social Security tax
          fi_held = grs_pay * FI_TAX, //Withheld for federal income tax
          si_held = grs_pay * SI_TAX; //Withheld for state income tax
    int dep_held = 0; //Withheld for dependants
    tot_pay = grs_pay - ss_held - fi_held - si_held - UN_DUES;
    if (dependants >= MIN_DEP) //Does he have to pay for dependants?
        dep_held = DEP_DUES;
        tot_pay -= DEP_DUES;
   
    //Format cout for dollar value
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    //Output everything
    cout<<"Gross pay:                        "<<setw(6)<<grs_pay<<endl;
    cout<<"Withheld for Social Security tax: "<<setw(6)<<ss_held<<endl;
    cout<<"Withheld for federal income tax:  "<<setw(6)<<fi_held<<endl;
    cout<<"Withheld for state income tax:    "<<setw(6)<<si_held<<endl;
    cout<<"Withheld for union dues:          "<<setw(6)<<UN_DUES<<endl;
    cout<<"Withheld for health insurance:    "<<setw(6)<<dep_held<<endl;
    cout<<"Total net pay:                    "<<setw(6)<<tot_pay<<endl;
    
    //Exit program
    return 0;
}

