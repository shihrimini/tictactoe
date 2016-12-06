/*******************************************************
* Project 10.a
* Author: Joseph Shih
* Description: This is the implementation file of Board class
*******************************************************/
#include "Board.hpp"
#include <iostream>
using std::cout;
using std::endl;


//helper
string Board::stateToString(State s){
		switch(s){
			case XWON:
			return "x has won";
			
			case OWON:
			return "o has won";
			
			case DRAW:
			return "the game is a draw";
			
			case PROGRESS:
			return "the game is still in progress";
			
			default:
			return "Unknown gamestate";
		}
}

string Board::playerToString(Player ppl){
	switch(ppl){
			case X:
			return "X";
			
			case O:
			return "O";

			default:
			return "Unknown player";
		}
};

/*******************************************************
* Default Constructor
* Initialize the array as empty
*******************************************************/
Board::Board(){
	for(int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++) arr[row][col] = '.';
	}
	//currentState = PROGRESS;
}


/*******************************************************
* The function takes x- and y-coordinate and which player's turn 
* It returns true when the position is available and the move
* is made. It returns false when the position is occupied.
*******************************************************/
bool Board::makeMove(int x, int y, Player guy){
	if (arr[x][y] != '.') return false;
	if(guy == X) arr[x][y] = 'x';
	else arr[x][y] = 'o';
	return true;
}

/*******************************************************
* The function prints out the current board
*******************************************************/
void Board::print(){
	cout << "  0 1 2" << endl;
	for(int row = 0; row < 3; row++){
		cout << row << " ";
		for(int col = 0; col < 3; col++) cout << arr[row][col] << " ";
		cout << endl;
	}
};

string Board::gameState(){
	
	State currentState = PROGRESS;

	

	//iterate through the array to see who won
	//1: any row with 3 identical marks 
	for (int i=0; i<3; i++){
		if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1]!= '.'){
				if(arr[i][1] == 'x' ) currentState = XWON;
				else currentState = OWON;
		}
	}

	//2: any column with 3 identical marks
	if(currentState == PROGRESS){
		for(int i=0; i<3; i++){
			if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i]!= '.'){
					if(arr[1][i] == 'x' ) currentState = XWON;
					else currentState = OWON;
			}
		}		
	}

	//3: diagnol with the 3 identical marks 
	if(currentState == PROGRESS){
		if((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]))
		{
			if(arr[1][1] == 'x') currentState = XWON;
			else if (arr[1][1] == 'o') currentState = OWON;
		}

	}

	//if it's a draw
	if(currentState == PROGRESS){
		bool ifDraw = true;

		for(int row = 0; row < 3; row++){
			for(int col = 0; col < 3; col++)
				if(arr[row][col] == '.') {
					ifDraw = false;
				}
		}
		if(ifDraw) currentState = DRAW;
	}

	return stateToString(currentState);
};