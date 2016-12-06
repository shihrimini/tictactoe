all: TicTacToe

TicTacToe: Board.o TicTacToe.o
	g++ -g TicTacToe.o Board.o -o TicTacToe

TicTacToe.o: TicTacToe.cpp TicTacToe.hpp Board.hpp
	g++ -c TicTacToe.cpp

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp

clean:
	rm -f *.o