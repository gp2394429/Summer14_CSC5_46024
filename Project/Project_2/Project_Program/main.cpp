/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 24, 2014, 10:39 PM
 * Purpose: Project 2 Summer CSC-5 46024
 *          Connect Four 
 */

//System Level Libraries 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

//User Defined Libraries

//Global Constants
const int B_MAX = 10;//Maximum size for a board plus 1

//Function Prototypes
int linSrch(string,const vector<string>&);
bool isYes();
int getNum();
void waitIpt();
bool inRange(int,int,int=0);
void empty(char[][B_MAX],int);
void acctOut(const vector<string>&,int);
void boardOut(const char[][B_MAX],int);
bool isLegal(const char[][B_MAX],int);
void update(char[][B_MAX],int,int,bool,int&);
void endMsg(const char[][B_MAX],int,bool&);
bool isDraw(const char[][B_MAX],int);
bool didWin(const char[][B_MAX],int,int,int,int);
int getMatch(const char[][B_MAX],int,int,int,char,int,int);
int getValue(const char[][B_MAX],int,char,int,int);
void connectFour(int,bool);
//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    const int B_MIN = 4;//Minimum board size minus 1
    string acct_name;//User's account name choice
    int acct_len;//Length of the users account name
    int b_size = 6;//Size of the connect four game board (default is 6)
    int m_choice;//User's menu choice
    int s_choice;//User's settings choice
    int p_choice;//User's player choice
    bool comp_opp = false;//Toggle for computer opponent
    vector<string> plrs;//A list of registered players
    vector<int> stats;//A list of statistics for each player
    int p1_id = -1;//Identification number for player one (default loaded at startup)
    int p2_id = -1;//Identification number for player two (default loaded at startup)
    fstream plr_file;//Stream for the player file
    fstream stat_file;//Stream for the statistics file
    
    //Try to load registered players
    plr_file.open("players.csv");
    if(!plr_file.is_open())
        cout<<"Error, \"players.csv\" not found. No Statistics will be available.\n";
    else{
        string load;//Dummy variable for loading
        while(plr_file>>load)
            plrs.push_back(load);
        plr_file.clear();
    }
    
    //Try to load statistics for registered players
    stat_file.open("stats.csv");
    if(!stat_file.is_open())
        cout<<"Error, \"stats.csv\" not found.\n";
    else{
        int load;//Dummy variable for loading
        while(stat_file>>load){
            stats.push_back(load);
        }
        stat_file.clear();
    }
    
    //Enter menu loop
    do{
        //Output menu
        cout<<"----------Menu-Menu----------\n";
        cout<<"1. Play Connect Four\n";
        cout<<"2. Change account\n";
        cout<<"3. Settings Menu\n";
        cout<<"4. Rules for Connect Four\n";
        cout<<"5. Quit\n";
        cout<<endl;
        //Get a number from the user
        cout<<"Enter your menu choice: ";
        m_choice = getNum();
        cout<<endl;
        
        switch(m_choice){
            case(1):{
                connectFour(b_size,comp_opp);
                break;
            }
            case(2):{
                cout<<"Player 1's current account: ";
                acctOut(plrs,p1_id);
                cout<<endl;
                cout<<"Player 2's current account: ";
                acctOut(plrs,p2_id);
                cout<<endl;
                cout<<"Change which player's account?(1 or 2):";
                p_choice = getNum();
                if(p_choice == 1 || p_choice == 2){
                    do{
                    cout<<"Enter account name(from 1 to 10 characters): ";
                    getline(cin,acct_name);
                    acct_len = acct_name.length();
                    }while(acct_len<=0 || acct_len>10);
                    //See if the given account name exists already
                    int id = linSrch(acct_name,plrs);//Dummy variable for id number
                    //If the name isn't found, ask to register the account
                    if(id<0){
                        cout<<"Account name not found, register new account?: ";
                        if(isYes()){
                            cout<<acct_name;
                            cout<<"!@#$"<<endl;
                            id = plrs.size();
                            plrs.push_back(acct_name);
                            plr_file<<acct_name<<endl;
                            stats.push_back(id);
                            stats.push_back(0);
                            stats.push_back(0);
                            stat_file<<id<<endl<<0<<endl<<0<<endl;
                            cout<<"Account registered\n\n";
                        }
                        else cout<<"Setting to default account\n\n";
                    }
                    else cout<<"Welcome back "<<acct_name<<"!\n\n";
                    
                    if(p_choice == 1) p1_id = id;
                    else p2_id = id;
                }
                else
                    cout<<"Invalid input\n\n";
                break;
            }
            case(3):{
                do{
                    //Output settings menu
                    cout<<"-------------------Settings------------------\n";
                    cout<<"1. Change board size [currently "<<b_size<<" by "<<b_size+1<<"]\n";
                    cout<<"2. Toggle computer opponent [currently ";
                    if(comp_opp) cout<<"on";
                    else cout<<"off";
                    cout<<"]\n";
                    cout<<"3. Change player account\n";
                    cout<<"4. Don't change settings\n\n";

                    //Get users settings choice
                    cout<<"Enter your settings choice: ";
                    s_choice = getNum();
                    cout<<endl;
                    
                    switch(s_choice){
                        case(1):{
                            cout<<"The board size is (N-1) by N, ";
                            cout<<"where N is the number of columns.\n";
                            cout<<"Enter the number of columns for the board";
                            cout<<"("<<B_MIN<<" to "<<B_MAX<<"): ";
                            b_size = getNum()-1;
                            cout<<endl;
                            if(inRange(b_size,B_MAX,B_MIN))
                                cout<<"The board size is now "<<b_size<<" by "<<b_size+1<<endl<<endl;
                            else{
                                b_size = B_MIN+1;//Default board size
                                cout<<"Invalid input, setting board size to ";
                                cout<<b_size<<" by "<<b_size+1<<endl<<endl;
                            }
                            break;
                        }
                        case(2):{
                            comp_opp = !comp_opp;
                            cout<<"Computer opponent is now ";
                            if(comp_opp) cout<<"on";
                            else cout<<"off";
                            cout<<endl<<endl;
                            break;
                        }
                        default:
                            cout<<"Exiting settings menu\n\n";
                    }
                }while(inRange(s_choice,3));
                break;
            }
            case(4):{
                cout<<"----------------------------Rules-for-Connect-Four--------------------------------\n";
                cout<<"Players: 2\n\n";
                cout<<"Description: Players take turns trying to get four of their pieces lined up\n";
                cout<<"             vertically, horizontally, or diagonally, while attempting\n";
                cout<<"             to stop the other player from doing the same.\n\n";
                cout<<"Objective: Obtain a line of four of pieces vertically, horizontally, or\n";
                cout<<"           or diagonally.\n\n";
                cout<<"Constraints: Players may only choose which column they want their piece\n";
                cout<<"             to fall. Once chosen, the piece falls to the lowest non-occupied\n";
                cout<<"             space in the chosen column.\n\n";
                cout<<"Ending conditions: 1. Either player gets four pieces in a row, and wins.\n";
                cout<<"                   2. There are no more places to play, and the game is a draw.\n\n";
                waitIpt();
                cout<<endl;
                break;
            }
            default:
                cout<<"Exiting game.\n";
        }
    }while(inRange(m_choice,5));//Check to see if the input is in a range
    
    //Close files
    plr_file.close();
    stat_file.close();
    
    //Exit program
    return 0;
}
//Function definitions

//Implementation of a linear search for string vectors
//Returns the index of the position of the string if found, otherwise returns -1
//Inputs
//  item = the string being searched for
//  list = the list of strings being searched
//Outputs
//  index = the index of the item (or -1 if not found)
int linSrch(string item,const vector<string>& list){
    for(int i = 0;i<list.size();i++){
        if(item == list[i])
            return i;
    }
    return -1;
}

//Determine if the user entered y or Y for yes
//No inputs
//Outputs
//  bool indicating if the user entered y or Y
bool isYes(){
    char input;//User's input
    cin>>input;
    //Clear the input buffer
    cin.clear();//Remove the error flag on bad input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//Skip to the next newline character
    return(input == 'y' || input == 'Y');
}

//Gets a number from the user (assumes input validation elsewhere)
//No inputs
//Outputs
//  choice = the users choice
int getNum(){
    //Get the choice
    int choice;
    cin>>choice;
    //Clear the input buffer
    cin.clear();//Remove the error flag on bad input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//Skip to the next newline character
    return choice;
}

//Waits for user input before continuing
//No Inputs
//No Outputs
void waitIpt(){
    cout<<"Press Enter to continue ";
    cin;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//Ignore all input
}

//Determines whether input is inside a range exclusive of the bounds
//Inputs
//  ipt = input to be validated
//  LB = lower bound on the input (defaults to zero))
//  UB = upper bound on the input
//Outputs
//  bool determining if the input is valid or not
bool inRange(int ipt,int ub,int lb){
    //The input is in the range if it is between the upper and lower bounds
    return ipt>lb && ipt<ub;
}

//Fills an nx(n+1) array with '.' characters
//Inputs
//  arr = a 2-dimensional array
//  size = number of rows and number of columns-1
//Outputs
//  arr = a 2-dimensional array filled with '.' characters
void empty(char arr[][B_MAX],int size){
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size+1;j++)
            arr[i][j] = '.';
    }
}

//Prints an account name to the screen based on the players id number
//Inputs
//  plrs = vector of player names
//  id = players current id number
//No outputs
void acctOut(const vector<string>& plrs,int id){
    if(id<0) cout<<"Guest";
    else cout<<plrs[id];
}

//Print the board to the screen
//Inputs
//  board = the current board
//  size = the size of the board
//No outputs
void boardOut(const char board[][B_MAX],int size){
    //Output numbers above each column on the board
    cout<<"    ";
    for(int i = 0;i<size+1;i++)
        cout<<" "<<i+1;
    cout<<endl;
    //Output the board
    for(int i = 0;i<size;i++){
        cout<<"    |";
        for(int j = 0;j<size+1;j++)
            cout<<board[i][j]<<"|";
        cout<<endl;
    }
    cout<<endl;
}

//Determines whether a players move is legal given the current board
//A move is legal if there is at least one space empty in the players
//chosen column
//Inputs
//  board = the current state of the board
//  p_move = the players move
//Output
//  bool indicating if the move is legal
bool isLegal(const char board[][B_MAX],int p_move){
    return(board[0][p_move-1] == '.');
}

//Updates the board with the current players move
//Inputs
//  board = the current state of the board
//  size = the size of the board
//  MOVE = the current player's move
//  plr = the current player
//Outputs
//  board = the board updated with the current players move
//  row = the row where the piece landed
void update(char board[][B_MAX],int size,int MOVE,bool plr,int& row){
    char crd;//The current coordinate being examined
    for(int i = size-1;i>=0;i--){
        crd = board[i][MOVE-1];
        if(crd == '.'){
            if(plr) crd = 'O';
            else crd = 'X';
            board[i][MOVE-1] = crd;
            row = i+1;
            break;
        }
    }
}

//End the game by printing the final board position and setting the game to stop
//running
//Inputs
//  board = the final board position
//  size = size of the board
//Outputs (by reference)
//  running = flag determining whether the game should keep running
void endGame(const char board[][B_MAX],int size,bool& running){
    //Output the final position
    cout<<"     Ending position\n";
    cout<<"-------------------------\n";
    boardOut(board,size);
    //Wait for the user to continue
    waitIpt();
    cout<<endl;
    //Set the status of the game to not be running
    running = false;
    
}
//Determines if the game is a draw
//A game is a draw if the entire first row is filled with pieces
//Inputs
//  board = the current board state
//  size = size of the game board
//Output
//  flag determining if the game is a draw
bool isDraw(const char board[][B_MAX],int size){
    for(int i = 0;i<size+1;i++){
        if(board[0][i] == '.')
            return false;
    }
    return true;
}

//Determine if a player has won
//A player wins if he has four pieces in a row vertically, horizontally, or
//diagonally
//Inputs
//  board = current board status
//  size = size of the board
//  PLR = the current player
//Outputs
//  bool determining if the current player has won
bool didWin(const char board[][B_MAX],int size,int row,int col){
    //Declare variables
    const int MIN_M = 4;//The minimum number of matches for a win
    char c_pce = board[row][col];//The current type of piece
    int matches = 1;//The number of matches in a line
    //Determine who won
    //We need only need to check if the currently placed piece creates a win
    matches += getValue(board,size,c_pce,row,col);
    if(matches >= MIN_M) return true;
    else return false;
}

//Give the number of repeated matches of the current piece from a given location
//up to 3 spaces away in a given direction
//Inputs
//  board = the current board state
//  size = the board size
//  r = the row index of the current piece
//  c = the column index of the current piece
//  r_d = the direction the row index will move
//  c_d = the direction the column index will move
//Outputs
//  matches = the number of matches in the given direction
int getMatch(const char board[][B_MAX],int size,int r,int c,char c_pce,int r_d,int c_d){
    //Declare variables
    const int D_MAX = 3;//Maximum number of spaces away from the current piece that matter
    int matches = 0;//Number of matches so far to the current piece
    
    //Check the matches in the given direction
    for(int i = 1;i<=D_MAX;i++){
        r += r_d;
        c += c_d;
        if(inRange(r,size,-1) && inRange(c,size+1,-1) && board[r][c] == c_pce)
            matches += 1;
        else
            break;
    }
    return matches;
}

//Examines the surrounding areas of a space on the board for unbroken lines of
//a specific type of game piece.
//Used to assign values for computer moves and determine if there is a winner
//Inputs
//  board = current board state
//  size = size of the board
//  pce = the type of piece to check for
//  row = the row of the reference space
//  col = the column of the reference space
//Outputs
//  highest = the highest value
int getValue(const char board[][B_MAX],int size,char pce,int row,int col){
    int val = 0;//The current value
    int highest;//The highest value
    enum dir{NONE = 0,UP = -1,DOWN = 1,LEFT = -1,RIGHT = 1};//Directions
    
    highest = getMatch(board,size,row,col,pce,DOWN,NONE);
    //Look for horizontal matches
    val += getMatch(board,size,row,col,pce,NONE,LEFT);
    val += getMatch(board,size,row,col,pce,NONE,RIGHT);
    if(val > highest) highest = val;
    val = 0;
    //Look for diagonal matches from low to high (going left to right)
    val += getMatch(board,size,row,col,pce,UP,RIGHT);
    val += getMatch(board,size,row,col,pce,DOWN,LEFT);
    if(val > highest) highest = val;
    val = 0;
    //Look for diagonal matches from high to low (going left to right)
    val += getMatch(board,size,row,col,pce,UP,LEFT);
    val += getMatch(board,size,row,col,pce,DOWN,RIGHT);
    if(val > highest) highest = val;
    
    return highest;
}

//Implementation of a basic computer opponent
//The computer plays entirely defensively, assigning values to each open space
//depending on how many pieces the human player has in a row surrounding that space
//Inputs
//  board = the current board position
//  size = the size of the board
//Outputs
//  move = the chosen column by the computer
int compMove(const char board[][B_MAX],int size){
    //Declare variables
    char plr = 'X';//The human player's piece
    int c_val;//The value of the current space being examined
    int h_val = 0;//The highest valued spot
    int move = 0;//The computers chosen column
    //Loop through every space
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size+1;j++){
            //If the space is empty, get the value of that space
            //Otherwise move on to the next space
            if(board[i][j] == '.'){
                c_val = getValue(board,size,plr,i,j);
                //If the current spaces value is greater than the highest value
                //set the move to equal the current column and set the highest
                //value to the current value
                if(c_val > h_val){
                    move = j;
                    h_val = c_val;
                }
            }
        }
    }
    return move;
}
//Implements the game Connect Four of variable board size
//Inputs
//  b_size = the size of the game board
//No outputs
void connectFour(int b_size, bool c_opp){
    //Declare variables
    char board[b_size][B_MAX];//An nx(n+1) board
    int p_col;//The column the current player chose to drop a piece
    int p_row;//The row where the current players move landed
    bool plr = false;//Flag determining which player is currently playing
    bool running = true;//Flag determining if the game is over or not
    
    //Make the board "empty"
    empty(board,b_size);
    
    //Start game loop
    do{
        //Determine if its the computers turn
        if(c_opp && plr)
            //Get the computers move
            p_col = compMove(board,b_size)+1;
        else{
            //Output the board
            boardOut(board,b_size);

            //Input and validation loop
            //The input isn't valid if it is out of the range of the boards
            //columns, or if it is an illegal move
            do{
                cout<<"Player "<<static_cast<int>(plr)+1<<", enter your move: ";
                p_col = getNum();
            }while(!inRange(p_col,b_size+2) || !isLegal(board,p_col));
            cout<<endl;
        }
        
        //Update the board with the current players move
        update(board,b_size,p_col,plr,p_row);
        
        //Check for game ending conditions
        if(isDraw(board,b_size)){
            //Output a draw message
            cout<<"   The game is a draw!\n\n";
            //End the game
            endGame(board,b_size,running);
        }
        else if(didWin(board,b_size,p_row-1,p_col-1)){
            //Output who won
            if(c_opp && plr)
                cout<<"   The computer won!\n\n";
            else
                cout<<"   Player "<<static_cast<int>(plr)+1<<" has won!\n\n";
            
            //End the game
            endGame(board,b_size,running);
        }
        else
            //If the game isn't over, change the player
            plr = !plr;
    }while(running);
}
