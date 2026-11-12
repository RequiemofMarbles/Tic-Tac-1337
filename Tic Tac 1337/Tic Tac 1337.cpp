#include <iostream>
#include <string>
#include "functions.h"

int main()
{
	std::vector<std::vector<char>> gameboard(4, std::vector<char>(4, ' '));

	gameboard[1][0] = '1'; //row headers
	gameboard[2][0] = '2';
	gameboard[3][0] = '3';

	gameboard[0][1] = 'a'; //column headers (or vice versa)
	gameboard[0][2] = 'b';
	gameboard[0][3] = 'c';


	std::cout << "\nHere is the gameboard for your selections use (a1) (b2) (c3) etc. \n";

	displayBoard(gameboard);

	std::string p1 = "P1";
	std::string p2 = "P2";

	auto hasWinner = [&gameboard](char marker)
	{
		for (int row = 1; row <= 3; ++row)
		{
			if (gameboard[row][1] == marker && gameboard[row][2] == marker && gameboard[row][3] == marker)
				return true;
		}

		for (int column = 1; column <= 3; ++column)
		{
			if (gameboard[1][column] == marker && gameboard[2][column] == marker && gameboard[3][column] == marker)
				return true;
		}

		return (gameboard[1][1] == marker && gameboard[2][2] == marker && gameboard[3][3] == marker) ||
			(gameboard[1][3] == marker && gameboard[2][2] == marker && gameboard[3][1] == marker);
	};

	for (int move = 0; move < 9; ++move)
	{
		const std::string& player = move % 2 == 0 ? p1 : p2;
		const char marker = move % 2 == 0 ? 'X' : 'O';
		std::cout << (marker == 'X' ? "Player 1" : "Player 2")
			<< " select where you would like to place an (" << marker << ")\n";

		if (!playerTurn(gameboard, player))
		{
			std::cout << "Input ended.\n";
			return 0;
		}

		displayBoard(gameboard);
		if (hasWinner(marker))
		{
			std::cout << (marker == 'X' ? "Player 1" : "Player 2") << " wins!\n";
			return 0;
		}
	}

	std::cout << "The game is a draw.\n";
}