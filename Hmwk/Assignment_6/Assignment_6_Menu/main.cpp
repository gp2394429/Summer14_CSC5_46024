/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 22, 2014, 2:36 PM
 * Purpose: Assignment 6 Summer CSC-5 46024 
 */

//System Level Libraries 
#include <iostream>
#include <limits>
using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
//Generally useful functions
bool doRepeat();
int getChLen(const char[], const int);

//Problem 1 functions
bool isHexDgt(char);
void getHex(char[],const int);
short chrInt(char,const short,const short);
void addHexDgt(char,char,char&,bool&);
void addHex(char[],char[],const int,char[],bool&);
//Problem 2 functions
void delete_repeats(char[],int&);//required by book
//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    unsigned short m_choice;
    //Enter menu loop
    do {
        cout << "1. Savitch, 8th Edition, Chapter 7, Problem 2\n";
        cout << "2. \n";
        cout << "3. \n";
        cout << "4. \n";
        cout << "5. \n";
        cout << "6. \n";
        cout << "7. \n";
        cout << "8. \n";
        cout << "9. \n";
        cout << "10.\n";
        cout << "11. Quit the program\n";
        cout << "Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (m_choice) {
            case(1):
            {
                //Short problem description
                cout<<"Add two hexidecimal numbers.\n\n";
                //Begin problem 1
                //Declare variables
                const int HX_MAX = 10;//Maximum hexidecimal size plus
                char hx_num_1[HX_MAX];//First hexidecimal number
                char hx_num_2[HX_MAX];//Second hexidecimal number
                char answer[HX_MAX];//The result of the addition
                bool overflow;//Flag for determining overflow
                
                //Repeat calculation loop (required by problem)
                do{
                    //Get user input
                    cout<<"Enter two hexidecimal numbers to be added\n";
                    getHex(hx_num_1, HX_MAX);
                    getHex(hx_num_2, HX_MAX);
                    //Calculate the hexidecimal number
                    addHex(hx_num_1, hx_num_2, HX_MAX, answer, overflow);
                    
                    //Output the result
                    if(overflow)
                        cout<<"Addition overflow\n";
                    else{
                        cout<<"The sum is: ";
                        for(int i = 0;i<HX_MAX;i++)
                            cout<<answer[i];
                        cout<<endl;
                    }
                                
                }while(doRepeat());
                //End problem 1
                cout << endl;
                break;
            }
            case(2):
            {
                //Short problem description
                cout<<"Delete repeated characters in a character array.\n\n";
                //Begin problem 2
                //Declare variables
                const int MAX_SIZE = 21;//Max size of the character array plus null terminator
                char chr_arr[MAX_SIZE];//Character array
                int act_size;
                
                //Get a string of characters from the user
                cout<<"Enter a string of up to 20 characters: ";
                cin.getline(chr_arr, MAX_SIZE);
                
                //Determine how many characters were added to the array
                act_size = getChLen(chr_arr, MAX_SIZE);
                act_size--;//Assume no null delimeter
                cout<<act_size<<endl;
                //Remove all repeated characters from the array
                delete_repeats(chr_arr, act_size);
                
                //Output results assuming no null delimiter
                cout<<"The array with no repeated characters: ";
                for(int i = 0;i<act_size;i++)
                    cout<<chr_arr[i];
                cout<<endl;
                //End problem 2
                cout << endl;
                break;
            }
            case(3):
            {
                //Short problem description
                //Begin problem 3
                //End problem 3
                cout << endl;
                break;
            }
            case(4):
            {
                //Short problem description
                //Begin problem 4
                //End problem 4
                cout << endl;
                break;
            }
            case(5):
            {
                //Short problem description
                //Begin problem 5
                //End problem 5
                cout << endl;
                break;
            }
            case(6):
            {
                //Short problem description
                //Begin problem 6
                //End problem 6
                cout << endl;
                break;
            }
            case(7):
            {
                //Short problem description
                //Begin problem 7
                //End problem 7
                cout << endl;
                break;
            }
            case(8):
            {
                //Short problem description
                //Begin problem 8
                //End problem 8
                cout << endl;
                break;
            }
            case(9):
            {
                //Short problem description
                //Begin problem 9
                //End problem 9
                cout << endl;
                break;
            }
            case(10):
            {
                //Short problem description
                //Begin problem 10
                //End problem 10
                cout << endl;
                break;
            }
            default:
                cout << "Exiting program\n";
        }
    } while (m_choice > 0 && m_choice <= 10);

    //Exit program
    return 0;
}
//Generally useful functions
//Returns true or false depending if the user wants to repeat the calculation or not
bool doRepeat(){
    //Declare variables
    char answer;//Users answer
    
    //Determine if the user wants to repeat the calculation
    cout<<"Would you like to repeat the calculation?\n";
    cout<<"Enter Y if yes: ";
    cin>>answer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<endl;
    
    //Return true if the answer is yes
    return (answer == 'y' || answer == 'Y');
}
//Determine how full an array of characters is assuming it is null terminated
//Inputs
//  chr_arr = character array
//  SIZE = maximum size of the array
//Outputs
//  act_size = the number of elements being used
int getChLen(const char chr_arr[],const int SIZE){
    int act_size = 0;
    for(act_size;act_size<SIZE;act_size++){
        if(chr_arr[act_size] == '\0'){
            act_size++;
            break;
        }
    }
    return act_size;
}
//Problem 1 functions
//Determine if a character can be a hexidecimal digit
//Inputs
//  hd = hexidecimal digit
//Outpus
//  bool indicating if hd is a hexidecimal digit
bool isHexDgt(char hd){
    return (hd>='0' && hd<='9') || (hd>='a' && hd<='f');
}
//Get a hexidecimal digit from a user
//Output be reference
//Inputs
//  SIZE = maximum size of the hexidecimal number
//Outputs
//  hex_num = array of characters representing a hexidecimal number
//  act_size = actual size of the hexidecimal number
void getHex(char hex_num[],const int SIZE){
    //Declare variables
    bool valid;//Flag for valid input
    char hd;//Current digit being examined
    int act_size;//The actual size of the hexidecimal number
    char buffer[SIZE+1];//Buffer for input
    //Validate input
    do{
        //Assume the input will be valid
        valid = true;
        
        //Prompt user for hexidecimal number
        cout<<"Enter a hexidecimal number of 10 digits or less: ";
        cin.getline(buffer, SIZE+1);
        
        //Determine if the characters in the array are valid and get the
        //actual size of the array
        act_size = 0;
        for(act_size;act_size<SIZE;act_size++){
            hd = buffer[act_size];
            if(hd == '\0')break;//If you reach the end of the number, break out
            if(!isHexDgt(hd)){
                cout<<"Invalid input, please try again\n";
                valid = false;
                break;//If the digit being looked at is invalid, break out
            }
            hex_num[act_size] = buffer[act_size];
        }
    }while(!valid);
    
    //Reorganize the array to be right justified if act_size < SIZE
    if(act_size < SIZE){
        for(int i = SIZE-1, j = act_size-1;i>=0;i--,j--){
            //Shift elements to the right until and fill the rest with zeros
            if(j < 0)
                hex_num[i] = '0';
            else
                hex_num[i] = hex_num[j];   
        }
    }
}
//Convert a character to a base 10 number that can be easily converted to hex
//Inputs
//  chr = The char to be converted
//  chr_enc = Conversion from a character representation of a hex character to a base 10 number
//  num_enc = Conversion from a character representation of a hex number to a base 10 number
//Outputs
//  A base 10 representation of a character representation of a hex number or character
short chrNum(char chr,const short CHR_ENC,const short NUM_ENC){
    if(chr>='0' && chr<='9')
        return static_cast<short>(chr)-NUM_ENC;
    else
        return static_cast<short>(chr)-CHR_ENC;
}
//Calculate the sum of two hexidecimal digits
//Output be reference
//Inputs
//  chr_1, chr_2 = the digits to be added
//Outputs
//  a_chr = the answer of the addition
//  carry = flag to determine if there was carry over
void addHexDgt(char chr_1,char chr_2,char& a_chr,bool& carry){
    //Declare variables
    const short CHR_ENC = 87;//Conversion from a character representation of a hex character in base 10
    const short NUM_ENC = 48;//Conversion from a character representation of a hex number in base 10
    const short H_MAX = 15;//Greatest value for a hexidecimal digit in base 10
    short a_num;//Answer as a base 10 number
    
    //Calculate the answer digit
    a_num = chrNum(chr_1,CHR_ENC,NUM_ENC)+chrNum(chr_2,CHR_ENC,NUM_ENC);
    if (carry){
        a_num++;
        carry = false;
    }
    if(a_num>H_MAX){
        carry = true;
        a_num-=H_MAX+1;
    }
    
    //Convert the answer digit to hexidecimal form
    if(a_num>=10){
        a_chr = a_num+CHR_ENC;
    }
    else
        a_chr = a_num+NUM_ENC;
}
//Calculate the sum of two hexidecimal numbers
//Output by reference
//Inputs
//  h_num_1, h_num_2 = The two hexidecimal numbers to be added
//  SIZE = Maximum size of the hexidecimal numbers
//Outputs
//  answer = the sum of the two hexidecimal numbers
//  overflow = flag to determine if the addition overflowed
void addHex(char h_num_1[],char h_num_2[],const int SIZE,char answer[],bool& overflow){
    //Declare variables
    bool carry = false;//Flag for carry over
    char c_dgt;//The current digits sum value
    for(int i = SIZE-1;i>=0;i--){
        addHexDgt(h_num_1[i],h_num_2[i],c_dgt,carry);
        answer[i]=c_dgt;
    }
    //If there is a carry on the final addition, then there is an overflow
    overflow = carry;
}
//Problem 2 functions

//Deletes repeated characters in an array assuming no null terminator and
//keeps the array organized
//Outputs by reference
//Inputs
//  chr_arr = the original character array
//  size = the original size
//Outputs
//  chr_arr = the new array with no repeated characters
//  size = the new size of the array
void delete_repeats(char chr_arr[],int& size){
    //Declare variables
    char cur;//Current character to check the array for repeats of
    int start = 0;//Current starting index
    
    //Enter deletion loop
    for(start;start<(size-1);start++){
        //Set the current character to be examined to current starting point
        cur = chr_arr[start];
        //Look at each character to the right of the starting point
        for(int i = start+1;i<size;i++){
            //If one of these characters is the same as the current character,
            //remove it by shifting all characters to the left
            if(cur == chr_arr[i]){
                //If the matching character is at the end of the array
                //replace it will a null terminator
                if(i == size-1)
                    chr_arr[i] = '\0';
                //Shift all character to the left
                else{
                    for(int j = i, k = i+1;k<size;j++,k++)
                        chr_arr[j] = chr_arr[k];
                }
                //Decrement the actual size of the array by one
                size--;
                //Keep the index i at the same location. Because we have shifted
                //the elements to the left, we haven't looked at the element at
                //the ith location yet
                i--;
            }
        }
    }
}