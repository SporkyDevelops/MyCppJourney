#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
public:
	//contructor
	Block();

	void Draw();

	void Move(int rows, int columns);

	std::vector<Position> GetCellPositions();

	void Rotate();

	void UndoRotation();

	//id to distinguish each block
	int id;

	//map that uses int and vector to determine block id
	std::map<int, std::vector<Position>> cells;

private:
	int cellSize;
	int rotationState;

	std::vector<Color> colors;

	int rowOffset;
	int columnOffset;
};