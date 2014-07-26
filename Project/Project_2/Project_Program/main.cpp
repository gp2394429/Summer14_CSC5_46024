/* 
 * File:   main.cpp
 * Author: Guthrie Price
 * Created on July 24, 2014, 10:39 PM
 * Purpose: Project 2 Summer CSC-5 46024
 *          Connect Four 
 */

//System Level Libraries 
#include <iostream>
#include <limits>
using namespace std;

//User Defined Libraries

//Global Constants
const int B_MAX = 10;//Maximum size for a board

//Function Prototypes
int getNum();
bool inRange(int,int,int=0);
void empty(char[][B_MAX],int);
void boardOut(const char[][B_MAX],int);
bool isLegal(const char[][B_MAX],int);
void update(char[][B_MAX],int,int,bool,int&);
void endMsg(const char[][B_MAX],int,bool&);
bool isDraw(const char[][B_MAX],int);
bool didWin(const char[][B_MAX],int,int,int,int);
int getMatch(const char[][B_MAX],int,int,int,int,int);
void connectFour(int);
//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    int UB_MC = 3;//Upper bound for the menu choice 
    int b_size = 6;//Size of the connect four game board (default is 6)
    int m_choice;//The users menu choice
    //Enter menu loop
    do{
        //Output menu
        cout<<"1. Play Connect Four\n";
        cout<<"2. Rules for Connect Four\n";
        cout<<"3. Quit\n";
        
        //Get a number from the user
        cout<<"Enter your menu choice: ";
        m_choice = getNum();
        
        switch(m_choice){
            case(1):{
                connectFour(b_size);
                break;
            }
            case(2):{
                cout<<"Rules for connect four\n";
                break;
            }
            default:
                cout<<"Exiting game.\n";
        }
    }while(inRange(m_choice,UB_MC));//Check to see if the input is in a range

    //Exit program
    return 0;
}
//Function definitions

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
    cout<<endl;
    return choice;
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
    boardOut(board,size);
    //Wait for the user to continue
    cout<<"Press Enter to continue ";
    cin;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//Ignore all input
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
    int matches = 1;//The number of matches in a line
    enum dir{NONE = 0,UP = -1,DOWN = 1,LEFT = -1,RIGHT = 1};
    //Determine who won
    //We need only need to check if the currently placed piece creates a win
    //Look for vertical matches
    matches += getMatch(board,size,row,col,1,0);
    if(matches >= MIN_M) return true;
    else matches = 1;
    //Look for horizontal matches
    matches += getMatch(board,size,row,col,0,-1);
    matches += getMatch(board,size,row,col,0,1);
    if(matches >= MIN_M) return true;
    else matches = 1;
    //Look for diagonal matches from low to high (going left to right)
    matches += getMatch(board,size,row,col,-1,1);
    matches += getMatch(board,size,row,col,1,-1);
    if(matches >= MIN_M) return true;
    else matches = 1;
    //Look for diagonal matches from high to low (going left to right)
    matches += getMatch(board,size,row,col,-1,-1);
    matches += getMatch(board,size,row,col,1,1);
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
int getMatch(const char board[][B_MAX],int size,int r,int c,int r_d,int c_d){
    //Declare variables
    const int D_MAX = 3;//Maximum number of spaces away from the current piece that matter
    int matches = 0;//Number of matches so far to the current piece
    char c_pce = board[r][c];//Current piece type
    
    //Check the matches in the given direction
    for(int i = 1;i<=D_MAX;i++){
        r += r_d;
        c += c_d;
        if(inRange(r,size) && inRange(c,size+1) && board[r][c] == c_pce)
            matches += 1;
        else
            break;
    }
    return matches;
}
//Implements the game Connect Four of variable board size
//Inputs
//  b_size = the size of the game board
//No outputs
void connectFour(int b_size){
    //Declare variables
    char board[b_size][B_MAX];//An nx(n+1) board
    int p_col;//The column the current player chose to drop a piece
    int p_row;//The row where the current players move landed
    bool plr = true;//Flag determining which player is currently playing
    bool running = true;//Flag determining if the game is over or not
    
    //Make the board "empty"
    empty(board,b_size);
    //Start game loop
    do{
        //Output the board
        boardOut(board,b_size);
        
        //Input and validation loop
        //The input isn't valid if it is out of the range of the boards
        //columns, or if it is an illegal move
        do{
            cout<<"Enter the number of the column you would like to drop your piece: ";
            p_col = getNum();
        }while(!inRange(p_col,b_size+2) || !isLegal(board,p_col));
        
        //Update the board with the players move
        update(board,b_size,p_col,plr,p_row);
        
        //Check for game ending conditions
        if(isDraw(board,b_size)){
            //Output a draw message
            cout<<"The game is a draw!\n\n";
            //End the game
            endGame(board,b_size,running);
        }
        else if(didWin(board,b_size,p_row-1,p_col-1)){
            //Output who won
            cout<<"Player "<<static_cast<int>(plr)+1<<" has won!\n\n";
            //End the game
            endGame(board,b_size,running);
        }
        else
            //If the game isn't over, change the player
            plr = !plr;
    }while(running);
}
