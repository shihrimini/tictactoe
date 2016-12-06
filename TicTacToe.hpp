/*******************************************************
* Project 10.a
* Author: Joseph Shih
* Description: This is the header file of TicTacToe class
*******************************************************/
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"

class TicTacToe{
private:
	Board theBoard;
	Player nextTurn;
	//helper
	void changePlayer();
public:
	TicTacToe(){};
	TicTacToe(char);
	void play();
};
#endif