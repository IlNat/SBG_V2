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
	Field& field;
public:
	Ship(int settingAmountOfUnits, Field& settingField) : amountOfUnits{settingAmountOfUnits}, field{settingField}
	{
		isDestroyed = false;
	};
	void setShip(int settingFirstXCord, int settingFirstYCord, int amountOfUnits, bool settingSide/*Field& field*/);
	void checkForDestroyed(/*Field& field*/);
};

