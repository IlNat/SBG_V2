#pragma once
class Field
{
private: 
	const int sizeOfLine = 10;
	char field[10][10];	
	enum { SHIP = '*', NOTHING = '#', HIT = '+', MISS = '-' };
public: 
	
	// Конструктор по умолчанию. Все элементы двумерного массива устанавливаются на "Пустые ячейки".
	Field();

	// Установка символа по координатам.
	void setUnit(char sign, int XCord, int YCord);

	// Печать поля.
	void print();

	// Проверка на доступность. Принимает координаты по осям X и Y, количество палуб(ячеек), направление.
	bool checkForAvailability(int XCord, int YCord, int amountOfUnits, bool isVertical);

	// Проверка на доступность по горизонтали.
	bool checkForHorizontalLocationMistakes(int XCord, int YCord, int amountOfUnits);

	// Проверка на доступность по вертикали.
	bool checkForVerticalLocationMistakes(int XCord, int YCord, int amountOfUnits);

	// Вовзращение элемента двумерного массива.
	char returnSign(int XCord, int YCord) { return field[XCord][YCord]; };

	~Field()
	{
		if (field != nullptr)
			delete[] field;
	}
};

