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
	bool isChecked;
	Field& field;
public:
	Ship(int settingAmountOfUnits, Field& settingField) : amountOfUnits{settingAmountOfUnits}, field{settingField}
	{
		isDestroyed = false;
		isChecked = false;
	};
	void setShip(int settingFirstXCord, int settingFirstYCord, bool settingSide);
	void checkForDestroyed();
	void checkDestroyedShip();
};

