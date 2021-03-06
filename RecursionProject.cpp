// RecursionProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int whiteCheck(int x, int y, vector<vector<char>>& grid) {
	int jumpNumber = 1;
	grid[y][x] = 'v';
	if (grid[y][x + 1] == 'w') { //check right
		jumpNumber += whiteCheck(x+1, y, grid);
	}
	if (grid[y - 1][x] == 'w') { // check below
		jumpNumber +=whiteCheck(x, y-1, grid);
	}
	if (grid[y][x - 1] == 'w') { // check left
		jumpNumber +=whiteCheck(x-1, y, grid);
	}
	if (grid[y + 1][x] == 'w') { // check above
		jumpNumber +=whiteCheck(x, y+1, grid);
	}
	return jumpNumber;
}

int main() 
{
	ifstream myFile;
	myFile.open("Recursion.txt");
	char ch;
	vector<vector<char>> grid;
	vector<char> row;
	while (myFile.get(ch)) {
		if (ch == '\n'){
			grid.push_back(row);
			row = vector<char>();
		}
		else {
			row.push_back(ch);
		} 
	}
	grid.push_back(row);
	myFile.close();

	std::list<int> intList;
	int counter = 0;
	for (int y = 0; y < grid.size(); y++) {
		for (int x = 0; x < row.size(); x++) {
			if (grid[y][x] == 'w') {
				counter++;
				intList.push_front(whiteCheck(x, y, grid));
				//cout << whiteCheck(x, y, grid) << endl;
			}
		}
	}
	cout << "There are " << counter << " groups with the following cell count: ";
	for (std::list<int>::const_iterator iterator = intList.begin(), end = intList.end(); iterator != end; ++iterator) {
		std::cout << *iterator << +" ";
	}
	cout << "\n";
    return 0;
}

