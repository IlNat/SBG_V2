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

}