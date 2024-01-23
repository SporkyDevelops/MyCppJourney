#include "position.h"


Position::Position(int row, int column) {
	//this is keyword refering to current object. this-> is used to access a variable withing the object
	//assigns the value of row parameter to row attribute, same with column
	this->row = row;
	this->column = column;
}