#include <iostream>
#include "Ship.h"
using namespace std;

void Ship::setShip(int settingFirstXCord, int settingFirstYCord, int amountOfUnits, bool settingSide/*Field& field*/)
{
	isVertical = settingSide;
	firstXCord = settingFirstXCord;
	firstYCord = settingFirstYCord;

	for (int i = 0; i < amountOfUnits; i++)
			{
				if (!isVertical)
					field.setUnit(SHIP, firstXCord, firstYCord + i);
				else
					field.setUnit(SHIP, firstXCord + i, firstYCord);
			}
	
}

void Ship::checkForDestroyed(/*Field& field*/)
{
	int amountOfDestroyedUnits = 0;
	if (!isVertical)
	{
		for (int i = 0; i < amountOfUnits; i++)
		{
			if (field.returnSign(firstXCord, firstYCord + i) == HIT)
				amountOfDestroyedUnits++;
		}
	}
	else
	{
		for (int i = 0; i < amountOfUnits; i++)
		{
			if (field.returnSign(firstXCord + i, firstYCord) == HIT)
				amountOfDestroyedUnits++;
		}
	}
	if (amountOfDestroyedUnits == amountOfUnits)
	{
		if (!isVertical)
		{
			if (firstYCord == 0)
			{
				if (firstXCord == 0)
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord + 1, firstYCord + i);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord, firstYCord + amountOfUnits);
							field.setUnit(MISS, firstXCord + 1, firstYCord + amountOfUnits);
						}
					}
				}
				else if (firstXCord == 9)
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord - 1, firstYCord + i);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord, firstYCord + amountOfUnits);
							field.setUnit(MISS, firstXCord - 1, firstYCord + amountOfUnits);
						}
					}
				}
				else
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord + 1, firstYCord + i);
						field.setUnit(MISS, firstXCord - 1, firstYCord + i);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord, firstYCord + amountOfUnits);
							field.setUnit(MISS, firstXCord + 1, firstYCord + amountOfUnits);
							field.setUnit(MISS, firstXCord - 1, firstYCord + amountOfUnits);
						}
					}
				}
			}
			else if (firstYCord == 10 - amountOfUnits)
			{
				if (firstXCord == 0)
				{
					field.setUnit(MISS, firstXCord, firstYCord - 1);
					field.setUnit(MISS, firstXCord + 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord + 1, firstYCord + i);
					}
				}
				else if (firstXCord == 9)
				{
					field.setUnit(MISS, firstXCord, firstYCord - 1);
					field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord - 1, firstYCord + i);
					}
				}
				else
				{
					field.setUnit(MISS, firstXCord, firstYCord - 1);
					field.setUnit(MISS, firstXCord + 1, firstYCord - 1);
					field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord + 1, firstYCord + i);
						field.setUnit(MISS, firstXCord - 1, firstYCord + i);
					}
				}
			}
		}
		else
		{
			if (firstXCord == 0)
			{
				if (firstYCord == 0)
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord + 1);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord);
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord + 1);
						}
					}
				}
				else if (firstYCord == 9)
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord - 1);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord);
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord - 1);
						}
					}
				}
				else
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord + 1);
						field.setUnit(MISS, firstXCord + i, firstYCord - 1);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord);
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord + 1);
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord - 1);
						}
					}
				}
			}
			else if (firstXCord == 10 - amountOfUnits)
			{
				if (firstYCord == 0)
				{
					field.setUnit(MISS, firstXCord - 1, firstYCord);
					field.setUnit(MISS, firstXCord - 1, firstYCord + 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord + 1);
					}
				}
				else if (firstYCord == 9)
				{
					field.setUnit(MISS, firstXCord - 1, firstYCord);
					field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord - 1);
					}
				}
				else
				{
					field.setUnit(MISS, firstXCord - 1, firstYCord);
					field.setUnit(MISS, firstXCord - 1, firstYCord + 1);
					field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord + 1);
						field.setUnit(MISS, firstXCord + i, firstYCord - 1);
					}
				}
			}
			else
			{
				field.setUnit(MISS, firstXCord - 1, firstYCord);
				field.setUnit(MISS, firstXCord - 1, firstYCord + 1);
				field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
				for (int i = 0; i < amountOfUnits; i++)
				{
					field.setUnit(HIT, firstXCord + i, firstYCord);
					field.setUnit(MISS, firstXCord + i, firstYCord + 1);
					field.setUnit(MISS, firstXCord + i, firstYCord - 1);
					if (i == amountOfUnits - 1)
					{
						field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord);
						field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord + 1);
						field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord - 1);
					}
				}
			}
		}
	}
}





/*
void Ship::checkForDestroyed(Field& field)
{
	int amountOfDestroyedUnits = 0;
	if (!isVertical) 
	{
		for (int i = 0; i < amountOfUnits; i++)
		{
			if (field.returnSign(firstXCord, firstYCord + i) == HIT)
				amountOfDestroyedUnits++;
		}
	}
	else
	{
		for (int i = 0; i < amountOfUnits; i++)
		{
			if (field.returnSign(firstXCord + i, firstYCord) == HIT)
				amountOfDestroyedUnits++;
		}
	}
	if (amountOfDestroyedUnits == amountOfUnits)
	{
		if (!isVertical) 
		{
			if (firstYCord == 0)
			{
				if (firstXCord == 0) 
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord + 1, firstYCord + i);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord, firstYCord + amountOfUnits);
							field.setUnit(MISS, firstXCord + 1, firstYCord + amountOfUnits);
						}
					}
				}
				else if (firstXCord == 9)
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord - 1, firstYCord + i);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord, firstYCord + amountOfUnits);
							field.setUnit(MISS, firstXCord - 1, firstYCord + amountOfUnits);
						}
					}
				}
				else
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord + 1, firstYCord + i);
						field.setUnit(MISS, firstXCord - 1, firstYCord + i);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord, firstYCord + amountOfUnits);
							field.setUnit(MISS, firstXCord + 1, firstYCord + amountOfUnits);
							field.setUnit(MISS, firstXCord - 1, firstYCord + amountOfUnits);
						}
					}
				}
			}
			else if (firstYCord == 10 - amountOfUnits)
			{
				if (firstXCord == 0)
				{
					field.setUnit(MISS, firstXCord, firstYCord - 1);
					field.setUnit(MISS, firstXCord + 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord + 1, firstYCord + i);
					}
				}
				else if (firstXCord == 9)
				{
					field.setUnit(MISS, firstXCord, firstYCord - 1);
					field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord - 1, firstYCord + i);
					}
				}
				else
				{
					field.setUnit(MISS, firstXCord, firstYCord - 1);
					field.setUnit(MISS, firstXCord + 1, firstYCord - 1);
					field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord, firstYCord + i);
						field.setUnit(MISS, firstXCord + 1, firstYCord + i);
						field.setUnit(MISS, firstXCord - 1, firstYCord + i);
					}
				}
			}
		}
		else
		{
			if (firstXCord == 0)
			{
				if (firstYCord == 0)
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord + 1);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord);
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord + 1);
						}
					}
				}
				else if (firstYCord == 9)
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord - 1);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord);
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord - 1);
						}
					}
				}
				else
				{
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord + 1);
						field.setUnit(MISS, firstXCord + i, firstYCord - 1);
						if (i == amountOfUnits - 1)
						{
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord);
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord + 1);
							field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord - 1);
						}
					}
				}
			}
			else if (firstXCord == 10 - amountOfUnits)
			{
				if (firstYCord == 0)
				{
					field.setUnit(MISS, firstXCord - 1, firstYCord);
					field.setUnit(MISS, firstXCord - 1, firstYCord + 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord + 1);
					}
				}
				else if (firstYCord == 9)
				{
					field.setUnit(MISS, firstXCord - 1, firstYCord);
					field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord - 1);
					}
				}
				else
				{
					field.setUnit(MISS, firstXCord - 1, firstYCord);
					field.setUnit(MISS, firstXCord - 1, firstYCord + 1);
					field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
					for (int i = 0; i < amountOfUnits; i++)
					{
						field.setUnit(HIT, firstXCord + i, firstYCord);
						field.setUnit(MISS, firstXCord + i, firstYCord + 1);
						field.setUnit(MISS, firstXCord + i, firstYCord - 1);
					}
				}
			}
			else
			{
				field.setUnit(MISS, firstXCord - 1, firstYCord);
				field.setUnit(MISS, firstXCord - 1, firstYCord + 1);
				field.setUnit(MISS, firstXCord - 1, firstYCord - 1);
				for (int i = 0; i < amountOfUnits; i++)
				{
					field.setUnit(HIT, firstXCord + i, firstYCord);
					field.setUnit(MISS, firstXCord + i, firstYCord + 1);
					field.setUnit(MISS, firstXCord + i, firstYCord - 1);
					if (i == amountOfUnits - 1)
					{
						field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord);
						field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord + 1);
						field.setUnit(MISS, firstXCord + amountOfUnits, firstYCord - 1);
					}
				}
			}
	}
}*/