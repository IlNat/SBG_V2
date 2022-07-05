#include <iostream>
#include "Field.h"
using namespace std;

void Field::setUnit(char sign, int XCord, int YCord)
{
	field[XCord][YCord] = sign;
}

void Field::print()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0 && j != 0)
			{
				if (j == 10)
				{
					cout << 0;
				}
				else
				{
					cout << j;
				}
			}
			else if (j == 0)
			{
				if (i == 10)
				{
					cout << 0;
				}
				else
				{
					cout << i;
				}
			}
			else
			{
				cout << field[i - 1][j - 1];
			}
		}
		cout << '\n';
	}
}


/*
void print_field(char field[10][10], int a)
{
	if (a == 1)
	{
		cout << "Печать игрового поля пользователя(\'#\' - пустое пространство; \'*\' - корабль/часть корабля; \'-\' - промах; \'+\' - попадание по Вашему кораблю;): \n";
	}
	if (a == 2)
	{
		cout << "Печать игрового поля противника(\'#\' - пустое пространство; \'+\' - попадание; \'-\' - промах;): \n";
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0 && j != 0)
			{
				if (j == 10)
				{
					cout << 0;
				}
				else
				{
					cout << j;
				}
			}
			else if (j == 0)
			{
				if (i != 10)
				{
					cout << i;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << field[i - 1][j - 1];
			}
		}
		cout << "\n";
	}
	cout << '\n';
}*/

bool Field::isAvailable(int XCord, int YCord, int amountOfUnits, bool isVertical)
{
	int operationNumber = 0;
	if (!isVertical)
	{
		if (XCord == 0 && YCord == 0)
			operationNumber = 1;
		else if (XCord == 0 && YCord > 0 && YCord < size - amountOfUnits)
			operationNumber = 2;
		else if (XCord > 0 && XCord < 9 && YCord == 0)
			operationNumber = 3;
		else if (XCord > 0 && XCord < 9 && YCord > 0 && YCord < size - amountOfUnits)
			operationNumber = 4;
		else if (XCord == 9 && YCord == 0)
			operationNumber = 5;
		else if (XCord == 9 && YCord > 0 && YCord < size - amountOfUnits)
			operationNumber = 6;
		else 
			return false;
	}
	else
	{
		if (XCord == 0 && YCord == 0)
			operationNumber = 7;
		else if (YCord == 0 && XCord > 0 && XCord < size - amountOfUnits)
			operationNumber = 8;
		else if (YCord > 0 && YCord < 9 && XCord == 0)
			operationNumber = 9;
		else if (YCord > 0 && YCord < 9 && XCord > 0 && YCord < size - amountOfUnits)
			operationNumber = 10;
		else if (YCord == 9 && XCord == 0)
			operationNumber = 11;
		else if (YCord == 9 && XCord > 0 && XCord < size - amountOfUnits)
			operationNumber = 12;
		else
			return false;
	}
	switch (operationNumber)
	{
	case 1:
	{
		
		break;
	}
	default:
	{
		cout << "Ошибка!\n";
	}
	}
}

bool Field::checkForAvailability(int XCord, int YCord, int amountOfUnits, bool isVertical, int caseNumber)
{
	if (YCord != 9)
	{
		for (int i = 0; i < amountOfUnits; i++)
		{
			if (!isVertical)
			{
				if (field[XCord][YCord + i] == SHIP)
				{
					return false;
				}
				if (caseNumber == 3 || caseNumber == 1)
				{
					if (field[XCord++][YCord + i] == SHIP)
					{
						return false;
					}
				}
				if (caseNumber == 3 || caseNumber == 2)
				{
					if (field[XCord--][YCord + i] == SHIP)
					{
						return false;
					}
				}
			}
			else
			{
				if (field[XCord + i][YCord] == SHIP)
				{
					return false;
				}
				if (caseNumber == 3 || caseNumber == 1)
				{
					if (field[XCord + i][YCord++] == SHIP)
					{
						return false;
					}
				}
				if (caseNumber == 3 || caseNumber == 2)
				{
					if (field[XCord + i][YCord--] == SHIP)
					{
						return false;
					}
				}
			}
		}
	}
	else if (XCord == 0)
	{

	}
	else if (XCord == 9)
	{

	}
	else
	{
		if (field[XCord++][YCord--] == SHIP)
		return true;
	}
}