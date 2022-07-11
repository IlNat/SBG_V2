#pragma once
class Field
{
private: 
	const int size = 10;
	char field[10][10];	
	enum { SHIP = '*', NOTHING = '#', HIT = '+', MISS = '-' };
public: 
	Field();
	void setUnit(char sign, int XCord, int YCord);
	void print();
	bool isAvailable(int XCord, int YCord, int amountOfUnits, bool isVertical);
	bool checkForAvailability(int XCord, int YCord, int amountOfUnits, bool isVertical, int caseNumber);

	char returnSign(int XCord, int YCord) { return field[XCord][YCord]; };
};

