#pragma once
class Field
{
private: 
	char field[10][10];	
public: 
	void setUnit(char sign, int XCord, int YCord);
	char returnUnit(int XCord, int YCord) { return field[XCord][YCord]; };
	void print();
	bool isAvailable(int XCord, int YCord, int amountOfUnits, bool isVertical);
};

