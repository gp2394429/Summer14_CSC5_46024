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
const short B_MAX = 10;//Maximum size for a board

//Function Prototypes
short getNum();
bool inRange(short,short,short=0);
void empty(char[][B_MAX],short);
void boardOut(const char[][B_MAX],short);
bool isLegal(const char[][B_MAX],short);
void update(char[][B_MAX],short,short,bool,short&);
void endMsg(const char[][B_MAX],short,bool&);
bool isDraw(const char[][B_MAX],short);
bool didWin(const char[][B_MAX],short,short,short,short);
void connectFour(short);
//Begin Execution

int main(int argc, char** argv) {
    //Main menu setup and output
    short UB_MC = 3;//Upper bound for the menu choice 
    short b_size = 6;//Size of the connect four game board (default is 6)
    short m_choice;//The users menu choice
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
                cout<<"Connect four game\n";
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
    }while(!inRange(m_choice,UB_MC));//Check to see if the input is in a range

    //Exit program
    return 0;
}
//Function definitions

//Gets a number from the user (assumes input validation elsewhere)
//No inputs
//Outputs
//  choice = the users choice
short getNum(){
    //Get the choice
    short choice;
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
bool inRange(short ipt,short ub,short lb){
    //The input is in the range if it is between the upper and lower bounds
    return ipt>lb && ipt<ub;
}

//Fills an nx(n+1) array with '.' characters
//Inputs
//  arr = a 2-dimensional array
//  size = number of rows and number of columns-1
//Outputs
//  arr = a 2-dimensional array filled with '.' characters
void empty(char arr[][B_MAX],short size){
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
void boardOut(const char board[][B_MAX],short size){
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
bool isLegal(const char board[][B_MAX],short p_move){
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
void update(char board[][B_MAX],short size,short MOVE,bool plr,short& row){
    char crd;//The current coordinate being examined
    for(short i = size-1;i>=0;i--){
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
void endGame(const char board[][B_MAX],short size,bool& running){
    //Output the final position
    boardOut(board,size);
    //Wait for the user to continue
    cout<<"Enter anything to continue ";
    cin;
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
bool isDraw(const char board[][B_MAX],short size){
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
bool didWin(const char board[][B_MAX],short size,short row,short col){
    //Declare variables
    const short S_MAX = 3;//The maximum number of spaces away from the current move that matters
    char p_pce = board[row][col];//The current players type of piece
    short v_mch,h_mch,d1_mch,d2_mch;//The number of matches vertically, horizontally, and diagonally
    v_mch = h_mch = d1_mch = d2_mch = 1;//Set the current matches to 1
    
    //Determine who won
    //We need only look at the areas surrounding the currently placed piece
    }
}

//Try to match
//Implements the game Connect Four of variable board size
//Inputs
//  b_size = the size of the game board
//No outputs
void connectFour(short b_size){
    //Declare variables
    char board[b_size][B_MAX];//An nx(n+1) board
    short p_col;//The column the current player chose to drop a piece
    short p_row;//The row where the current players move landed
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
            cout<<"Player "<<static_cast<short>(plr)+1<<" has won!\n\n";
            //End the game
            endGame(board,b_size,running);
        }
        else
            //If the game isn't over, change the player
            plr = !plr;
    }while(running);   
}
