#include "grid.h"
#include <raylib.h>
#include <iostream>
#include "colors.h"

//constructor
Grid::Grid() {

	//initalizes the int atributes
	numRows = 20;
	numCols = 10;
	cellSize = 30;

	//calls Initialize to be run
	Initialize();

	//loads list of colors
	colors = GetCellColors();
}


//initalizes array and makes sure all values are set to 0
void Grid::Initialize() {

	for (int row = 0; row < numRows; row++) {
		
		for (int column = 0; column < numCols; column++) {

			grid[row][column] = 0;
		}
	}
}


void Grid::Print() {
	for (int row = 0; row < numRows; row++) {

		for (int column = 0; column < numCols; column++) {

			std::cout << grid[row][column] << " ";
		}

		std::cout << std::endl;
	}
}


//draws each cell of the grid with its specific color
void Grid::Draw() {
	for (int row = 0; row < numRows; row++) {
		
		for (int column = 0; column < numCols; column++) {

			int cellValue = grid[row][column];

			//draws rectangle shape to screen, 5 input values int posX, int posY, in width, int height, color
			//x = column but since its a grid it needs to be * the cell size, same goes for y
			//cellValue var is used to index the colors vector and retrieve the cells color
			//+1 -1 to create an offset then make square only 29x29
			DrawRectangle(column * cellSize+1, row * cellSize+1, cellSize-1, cellSize-1, colors[cellValue]);
		}
	}
}

bool Grid::IsCellOutside(int row, int column)
{
	if (row >= 0 && row < numRows && column >= 0 && column < numCols) {

		return false;
	}

	return true;
}

bool Grid::IsCellEmpty(int row, int column){
	
	if (grid[row][column] == 0) {
		return true;
	}
	return false;
}

int Grid::ClearFullRows(){
	
	int completed = 0;
	for (int row = numRows - 1; row >= 0; row--) {

		if (IsRowFull(row)) {

			ClearRow(row);
			completed++;
		}
		else if (completed > 0) {

			MoveRowDown(row, completed);
		}
	}
	return completed;
}

bool Grid::IsRowFull(int row)
{
	for (int column = 0; column < numCols; column++) {

		if (grid[row][column] == 0) {

			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row){

	for (int column = 0; column < numCols; column++) {

		grid[row][column] == 0;
	}
}

void Grid::MoveRowDown(int row, int numRows){

	for (int column = 0; column < numCols; column++) {

		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}
