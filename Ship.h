#include "Field.h"
#pragma once

class Ship
{
private:
	enum {SHIP = '*', HIT = '+', MISS = '-'};
	int firstXCord;
	int firstYCord;
	int amountOfUnits;
	bool isVertical;
	bool isDestroyed;
public:
	Ship() {};
	void setShip(Field& field);
	void checkForDestroyed(Field& field);
};

