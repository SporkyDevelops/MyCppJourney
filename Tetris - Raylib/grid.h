#pragma once
#include <vector>
#include <raylib.h>


class Grid {
public:
	//assigns Grid() to Grid class
	Grid();

	//declares an array with 20 rows and 10 collums
	int grid[20][10];

	//public method to print array values to console
	void Print();

	//public method to initialize the array grid
	void Initialize();

	//draw grid method
	void Draw();

	bool IsCellOutside(int row, int column);
	bool IsCellEmpty(int row, int column);
	int ClearFullRows();

private:
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);
	int numRows;
	int numCols;
	int cellSize;

	//data structure to hold colors to use
	std::vector<Color> colors;

};
