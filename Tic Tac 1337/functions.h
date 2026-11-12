#pragma once

//#include<pair>
#include<string>
#include <utility>
#include <vector>


void displayBoard(const std::vector<std::vector<char>>&gameboard);
bool playerTurn(std::vector<std::vector<char>>& gameboard, const std::string& pid);


std::pair<int, int> convertStringInputToRowAndColumn(const std::string& input);