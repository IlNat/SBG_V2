#include <iostream>
#include "Field.h"
#pragma once

using namespace std;

// Класс "Серия очков". Если количество серий очков в системе не равняется "0", то существует возможность вызова метода их атак.
class ScoreStreak
{
private:
	int amountOfGunRun; // Количество "Авиаударов" в системе.
	int amountOfBomberRun; // Количество "Бомбардировок" в системе.
	Field& enemyField; // Ссылка на поле врага, на котором будет разворачиваться действия серии очков. 
	enum { SHIP = '*', NOTHING = '#', HIT = '+', MISS = '-' };
public: 

	// Конструктор класса.
	ScoreStreak(Field& settingEnemyField);

	// Атака "Авиаудара". По вертикали или горизонтали в ряду выставляются противоположные знаки.
	void gunRunAttack(int Cord, bool isVertical);

	// Атака "Бомбардировки". На площади в 3*3 выставляются противоположные знаки.
	void bomberRunAttack(int XCord, int YCord);

	// Увеличение количества(на 1) "Авиаударов" в системе.
	void increaseAmountOfGunRun() { amountOfGunRun++; };

	// Увеличение количества(на 1) "Бомбардировок" в системе.
	void increaseAmountOfBomberRun() { amountOfBomberRun++; };

	// Возращение количества "Авиаударов" в системе.
	int returnAmountOfGunRun() { return amountOfGunRun; };

	// Возращение количества "Бомбардировок" в системе.
	int returnAmountOfBomberRun() { return amountOfBomberRun; };

};

