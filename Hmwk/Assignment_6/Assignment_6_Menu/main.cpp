/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 22, 2014, 2:36 PM
 * Purpose: Assignment 6 Summer CSC-5 46024 
 */

//System Level Libraries 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
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

//Problem 3 functions
double stdDev(double[], int);//required by book (double also required by book)

//Problem 4 functions
void pb4Out(const int[],const int);

//Problem 5 functions
void istSort(int[],const int);//required by book
void pb5Out(const int[],const int);

//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    unsigned short m_choice;
    
    //Seed random number generator
    srand(static_cast<int>(time(0)));
    
    //Enter menu loop
    do {
        cout << "1. Savitch, 8th Edition, Chapter 7, Problem 2\n";
        cout << "2. Savitch, 8th Edition, Chapter 7, Problem 3\n";
        cout << "3. Savitch, 8th Edition, Chapter 7, Problem 4\n";
        cout << "4. Savitch, 8th Edition, Chapter 7, Problem 5\n";
        cout << "5. Savitch, 8th Edition, Chapter 7, Problem 6\n";
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
                cout<<"Demonstrates a standard deviation program.\n\n";
                //Begin problem 3
                //Declare variables
                const int MAX_SIZE = 25;//Maximum size of the example array
                const int N_PER_L = 5;//Numbers to be print per line
                double example[MAX_SIZE];//Double as per book definition
                int act_size = rand()%(MAX_SIZE-N_PER_L+1)+N_PER_L;//Number of values in the array (between 5 and 25)
                
                //Fill the example array with random numbers
                for(int i = 0;i<act_size;i++)
                    example[i] = static_cast<double>(rand())/rand();
                
                //Calculate the standard deviation and output to the screen
                cout<<"Numbers in the array:\n";
                for(int i = 0;i<act_size;i++){
                    cout<<setw(10)<<example[i];
                    if((i+1)%(N_PER_L+1) == 0)
                        cout<<endl;
                    else
                        cout<<" ";
                }
                cout<<endl;
                cout<<"The standard deviation is: "<<stdDev(example, act_size);
                cout<<endl;
                //End problem 3
                cout << endl;
                break;
            }
            case(4):
            {
                //Short problem description
                cout<<"Count how many integers are in an array and output it to the screen.\n\n";
                //Begin problem 4
                //Declare variables
                const int MAX_SIZE = 50;//Maximum size of the array
                int i_arr[MAX_SIZE];//Array for storing integers
                int a_size;//Actual size of the array
                char input_c;//Input choice of file or console supplied by the user
                char f_name[MAX_SIZE];//File name for input
                ifstream i_file;//File containing integers
                
                //Ask the user to read the input by console or by file
                cout<<"Would you like to use the console or a file for input?\n";
                cout<<"Format: [C for console, F for file]: ";
                cin>>input_c;
                cout<<endl;
                
                //Determine the users choice of input and act accordingly
                if(input_c == 'c' || input_c == 'C'){
                    //Read numbers from the console
                    //Simple input validation
                    do{
                        cout<<"How many integers would you like to enter?\n";
                        cout<<"Format: [n ("<<MAX_SIZE<<" or less)]: ";
                        cin>>a_size;
                    }while(a_size<0 || a_size>MAX_SIZE);
                    cout<<"Please enter "<<a_size<<" integers\n";
                    cout<<"Format: [n1 n2 n3...]: ";
                    for(int i = 0;i<a_size;i++)
                        cin>>i_arr[i];
                }
                else if(input_c == 'f' || input_c == 'F'){
                    //Get the file name
                    cout<<"Please enter the name of the file\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.getline(f_name, MAX_SIZE);
                    //Try to open the file
                    i_file.open(f_name);
                    //If the file can't be found, print and error and exit
                    if(!i_file){
                        cout<<"Couldn't find file "<<i_file<<endl;
                        exit(EXIT_FAILURE);
                    }
                    //Otherwise load up to MAX_SIZE integers from the file
                    cout<<"Loading integers...";
                    for(a_size = 0;a_size<MAX_SIZE&&i_file>>i_arr[a_size];a_size++);
                }
                
                //Sort the array from highest to lowest
                istSort(i_arr, a_size);//Defined in problem 5
                
                //Output the result
                cout<<"    N    Count\n";
                cRpeats(i_arr, a_size);
                //End problem 4
                cout << endl;
                break;
            }
            case(5):
            {
                //Short problem description
                cout<<"Demonstrate the use of an insertion sort program.\n\n";
                //Begin problem 5
                //Declare variables
                const int MAX_SIZE = 20;//Maximum size of the array
                int ex_arr[MAX_SIZE];//The example array being used
                
                //Fill the array with random numbers
                for(int i = 0;i<MAX_SIZE;i++)
                    ex_arr[i] = rand()%(MAX_SIZE+1);
                
                //Output the unsorted array
                cout<<"Unsorted array\n";
                pb5Out(ex_arr, MAX_SIZE);
                
                //Sort the array
                istSort(ex_arr, MAX_SIZE);
                
                //Output the sorted array
                cout<<"Sorted array\n";
                pb5Out(ex_arr, MAX_SIZE);
                
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
//Problem 3 functions

//Calculate the standard deviation for an array of numbers
//Formula: sqrt((sigma from i=1 to N of (x_i-x_bar)^2)/N)
//         where x_bar = the average of x_1 to x_N
//Inputs
//  num_arr = array of numbers used to calculate the standard deviation
//  size = the number of numbers in the array
//Outputs
//  the standard deviation of all the numbers in num_arr
double stdDev(double num_arr[], int size){
    //Declare variables
    double avg = 0;//The average value of all the numbers in the array
    double result = 0;//The result of the standard deviation calculation
    
    //Calculate the average
    //Sum all the numbers in the array
    for(int i = 0;i<size;i++)
        avg += num_arr[i];
    //Divide by the number of elements in the array
    avg /= size;
    
    //Get the sum of all the standard deviation terms
    for(int i = 0;i<size;i++){
        double x = num_arr[i];
        result += (x-avg)*(x-avg);
    }
    
    //Divide the result by the number of elements, take the square root, and return
    return sqrt(result/size);
}
//Problem 4 functions

//Insertion sort is found in the next problem!!

//Count the number of repeated elements in a sorted list from highest to lowest
//and output to the screen
//No outputs
//Inputs
//  arr = array of integers
//  size = size of the array
void cRpeats(const int arr[],const int size){
    //Declare variables
    int c_num = arr[0];//The current element being examined (starts at the first element)
    int count = 1;//current number of repeated elements including the original element
    
    for(int i = 1;i<size;i++){
        if(c_num == arr[i])
            count += 1;
        else{
            cout<<setw(5)<<c_num;
            cout<<setw(5)<<count;
            count = 1;
            c_num = arr[i];
        }
    }
    //Print the final element result
    cout<<setw(5)<<c_num;
    cout<<setw(5)<<count;
}
//Problem 5 functions

//Sorts a list according to the insertion sort algorithm from highest to lowest
//Outputs be reference
//Inputs
//  arr = array to be sorted
//  size = size of the array
//Outputs
//  arr = array that is now sorted
void istSort(int arr[],const int SIZE){
    //Declare variables
    int unst_i = 1;//the beginning of the unsorted portion of the array
    int c_num;//current number being sorted
    int swap;//used for swaps
    
    for(unst_i;unst_i<SIZE;unst_i++){
        c_num = arr[unst_i];
        
        //Insert the next element in the unsorted list into the sorted section
        for(int i = 0;i<=unst_i;i++){
            if(c_num<arr[i]){
                swap = arr[i];
                arr[i] = c_num;
                c_num = swap;
            }
        }
    }
}