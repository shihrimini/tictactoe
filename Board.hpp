/*******************************************************
* Project 10.a
* Author: Joseph Shih
* Description: This is the header file of Board class
*******************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
using std::string;

enum Player {X, O};

//x won, o won, draw, in progress
enum State {XWON, OWON, DRAW, PROGRESS};


class Board{
private:
	char arr[3][3];
	//helper
	string stateToString(State);

public:
	Board();
	bool makeMove(int, int, Player);
	string gameState();
	void print();
	string playerToString(Player);
};

#endif