#include "Field.h"
#pragma once

class Ship
{
private:
	int firstXCord;
	int firstYCord;
	int amountOfUnits;
	bool isVertical;
	bool isDestroyed;
public:
	void setShip(Field& field);
	void checkForDestroyed(Field& field);
};

