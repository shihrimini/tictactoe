/*******************************************************
* Project 10.a
* Author: Joseph Shih
* Description: This is the implementation file of TicTacToe class
*******************************************************/
#include "TicTacToe.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

TicTacToe::TicTacToe(char theFirstMove){
	if(theFirstMove == 'x') nextTurn = X;
	else nextTurn = O; 
};

void TicTacToe::changePlayer(){
	if(nextTurn == X) nextTurn = O;
	else nextTurn = X;
};

void TicTacToe::play(){

	int xCoord=-1, yCoord=-1;

	while(theBoard.gameState() == "the game is still in progress"){
		
			cout << "Player " << theBoard.playerToString(nextTurn) << ": please enter your move." << endl;
			cin >> xCoord >> yCoord;

			if(theBoard.makeMove(xCoord, yCoord, nextTurn)) changePlayer();
			else cout << "The square is already taken." << endl;
			cout << endl;
			theBoard.print();
			cout << endl;
	}
	cout << theBoard.gameState() << endl;
	cout << endl;
};

int main(){
	char user;

	cout << "Which player go first? Enter x or o" << endl;
	
	cin >> user;
	
	if(user == 'x' || user == 'X') user = 'x';
	else if (user == 'o' || user == 'O') user = 'o';
	else {
		cout << "Error...input unvalid." << endl;
		return -1;	
	}


	TicTacToe gameBuildUp(user);
	gameBuildUp.play();

	return 0;
}