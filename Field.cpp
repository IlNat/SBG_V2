#include <iostream>
#include "Field.h"
using namespace std;

// Конструктор по умолчанию. Все элементы двумерного массива устанавливаются на "Пустые ячейки".
Field::Field()
{
	for (int i = 0; i < sizeOfLine; i++)
	{
		for (int j = 0; j < sizeOfLine; j++)
		{
			field[i][j] = NOTHING;
		}
	}
}

// Установка символа по координатам.
void Field::setUnit(char sign, int XCord, int YCord)
{
	field[XCord][YCord] = sign;
}

// Печать поля.
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
				if (field[i - 1][j - 1] != NOTHING)
					cout << field[i - 1][j - 1];
				else
					cout << ' ';
			}
		}
		cout << '\n';
	}
}

// Проверка на доступность. Принимает координаты по осям X и Y, количество палуб(ячеек), направление.
bool Field::checkForAvailability(int XCord, int YCord, int amountOfUnits, bool isVertical)
{
	if (!isVertical)
	{
		if (YCord + amountOfUnits - 1 < sizeOfLine)
			return checkForHorizontalLocationMistakes(XCord, YCord, amountOfUnits);
		else
			return false;
	}
	else	
	{
		if (XCord + amountOfUnits - 1 < sizeOfLine)
			return checkForVerticalLocationMistakes(XCord, YCord, amountOfUnits);
		else
			return false;
	}
	
}

// Проверка на доступность по горизонтали.
bool Field::checkForHorizontalLocationMistakes(int XCord, int YCord, int amountOfUnits)
{
	if (YCord != 9)
	{
		if (XCord != 0 && XCord != 9)
		{
			if (YCord == 0)
			{
				if (field[XCord][YCord] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord + 1][YCord] == SHIP)
					return false;
			}
			else
			{
				if (field[XCord][YCord] == SHIP || field[XCord - 1][YCord - 1] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord + 1][YCord] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord + 1][YCord - 1] == SHIP)
					return false;
			}
		}
		else if (XCord == 0)
		{
			if (YCord == 0)
			{
				if (field[XCord][YCord] == SHIP || field[XCord + 1][YCord] == SHIP)
					return false;
			}
			else
			{
				if (field[XCord][YCord] == SHIP || field[XCord + 1][YCord] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord + 1][YCord - 1] == SHIP)
					return false;
			}
		}
		else
		{
			if (YCord == 0)
			{
				if (field[XCord][YCord] == SHIP || field[XCord - 1][YCord] == SHIP)
					return false;
			}
			else
			{
				if (field[XCord][YCord] == SHIP || field[XCord - 1][YCord - 1] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord][YCord - 1] == SHIP)
					return false;
			}
		}
		for (int i = 0; i <= amountOfUnits; i++)
		{
			if (field[XCord][YCord + i] == SHIP)
				return false;
			if (XCord != 9)
			{
				if (field[XCord + 1][YCord + i] == SHIP)
					return false;
			}
			if (XCord != 0)
			{
				if (field[XCord - 1][YCord + i] == SHIP)
					return false;
			}
		}
	}
	else
	{
		if (amountOfUnits == 1)
		{
			if (XCord == 0)
			{
				if (field[XCord][YCord] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord + 1][YCord] == SHIP || field[XCord + 1][YCord - 1] == SHIP)
					return false;
			}
			else if (XCord != 9)
			{
				if (field[XCord][YCord] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord - 1][YCord - 1] == SHIP || field[XCord + 1][YCord - 1] == SHIP || field[XCord + 1][YCord] == SHIP)
					return false;
			}
			else
			{
				if (field[XCord][YCord] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord - 1][YCord - 1] == SHIP)
					return false;
			}
			
		}
		else
			return false;
	}
	return true;
}

// Проверка на доступность по вертикали.
bool Field::checkForVerticalLocationMistakes(int XCord, int YCord, int amountOfUnits)
{
	if (XCord != 9)
	{
		if (YCord != 0 && YCord != 9)
		{
			if (XCord == 0)
			{
				if (field[XCord][YCord] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord][YCord + 1] == SHIP)
					return false;
			}
			else
			{
				if (field[XCord][YCord] == SHIP || field[XCord - 1][YCord - 1] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord][YCord + 1] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord - 1][YCord + 1] == SHIP)
					return false;
			}
		}
		else if (YCord == 0)
		{
			if (XCord == 0)
			{
				if (field[XCord][YCord] == SHIP || field[XCord][YCord + 1] == SHIP)
					return false;
			}
			else
			{
				if (field[XCord][YCord] == SHIP || field[XCord][YCord + 1] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord - 1][YCord + 1] == SHIP)
					return false;
			}
		}
		else 
		{
			if (XCord == 0)
			{
				if (field[XCord][YCord] == SHIP || field[XCord][YCord - 1] == SHIP)
					return false;
			}
			else
			{
				if (field[XCord][YCord] == SHIP || field[XCord - 1][YCord - 1] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord - 1][YCord] == SHIP)
					return false;
			}
		}

		for (int i = 0; i <= amountOfUnits; i++)
		{
			if (field[XCord + i][YCord] == SHIP)
				return false;
			if (YCord != 9)
			{
				if (field[XCord + i][YCord + 1] == SHIP)
					return false;
			}
			if (YCord != 0)
			{
				if (field[XCord + i][YCord - 1] == SHIP)
					return false;
			}
		}
		
	}
	else
	{
		if (amountOfUnits == 1)
		{
			if (YCord == 0)
			{
				if (field[XCord][YCord] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord][YCord + 1] == SHIP || field[XCord - 1][YCord + 1] == SHIP)
					return false;
			}
			else if (YCord != 9)
			{
				if (field[XCord][YCord] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord - 1][YCord - 1] == SHIP || field[XCord - 1][YCord + 1] == SHIP || field[XCord][YCord + 1] == SHIP)
					return false;
			}
			else
			{
				if (field[XCord][YCord] == SHIP || field[XCord - 1][YCord] == SHIP || field[XCord][YCord - 1] == SHIP || field[XCord - 1][YCord - 1] == SHIP)
					return false;
			}
			
		}
		else
			return false;
	}
	return true;
}
