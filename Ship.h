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
	
	// Конструктор класса "Корабль".
	Ship(int settingAmountOfUnits, Field& settingField) : amountOfUnits{settingAmountOfUnits}, field{settingField}
	{
		isDestroyed = false;
		isChecked = false;
	};

	// Установка корабля на поле с проверкой на доступность места.
	// Принимает первые координаты по осям X и Y, и направление.
	void setShip(int settingFirstXCord, int settingFirstYCord, bool settingSide);

	// Проверка: уничтожен ли корабль? Если уничтожен, то вокруг корабля печатает символы промахов.
	void checkForDestroyed();

	// Меняет поле "isChecked" класса на значение "true"(необходимо при переборе кораблей для проверки на их целостность). 
	void checkDestroyedShip();

	// Вовзращение статуса "Уничтожен ли?".
	bool returnStatusIsDestroyed() { return isDestroyed; }

	// Возвращение статуса "Проверен ли?".
	bool returnStatusIsChecked() { return isChecked; }
};

