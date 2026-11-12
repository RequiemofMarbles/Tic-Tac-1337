#include"functions.h"

#include <iostream>
#include <string>
#include <map>
#include <cctype>




void displayBoard(const std::vector<std::vector<char>>& gameboard)
{
	//gameboard[0][0] = 's'; //ain't gonna happen, bro!

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cout << gameboard[i][j] << " ";
		}
		std::cout << "\n";
	}
}

std::pair<int, int> convertStringInputToRowAndColumn(const std::string& input)
{
	std::map<std::string, std::pair<int, int>> stringsToRowsAndColumns =
	{
		{"a1", {1,1}},
		{"a2", {2,1}},
		{"a3", {3, 1}},

		// Column 2 (b)
		{"b1", {1, 2}}, // Row 1, Column 2
		{"b2", {2, 2}}, // Row 2, Column 2
		{"b3", {3, 2}}, // Row 3, Column 2

		// Column 3 (c)
		{"c1", {1, 3}}, // Row 1, Column 3
		{"c2", {2, 3}}, // Row 2, Column 3
		{"c3", {3, 3}}  // Row 3, Column 3
	};

	if (stringsToRowsAndColumns.find(input) == stringsToRowsAndColumns.end())
	{
		std::cout << "The input " << input << " is not an allowed position.\n";
		return {-1, -1};
	}

	return stringsToRowsAndColumns[input];
}

bool playerTurn(std::vector<std::vector<char>>& gameboard, const std::string& pid)
{
	std::string input;
	while (std::getline(std::cin, input))
	{
		for (char& character : input)
		{
			character = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));
		}

		auto position = convertStringInputToRowAndColumn(input);
		if (position.first < 0)
			continue;

		if (gameboard[position.first][position.second] != ' ')
		{
			std::cout << "That position is already occupied. Choose another position.\n";
			continue;
		}

		gameboard[position.first][position.second] = pid == "P1" ? 'X' : 'O';
		return true;
	}

	return false;
}