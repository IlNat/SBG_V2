#include "ScoreStreak.h"

// Констуктор класса.
ScoreStreak::ScoreStreak(Field& settingEnemyField) : enemyField{settingEnemyField}
{
	amountOfGunRun = 0;
	amountOfBomberRun = 0;
}

// Атака "Авиаудара". По вертикали или горизонтали в ряду выставляются противоположные знаки.
void ScoreStreak::gunRunAttack(int Cord, bool isVertical)
{
	if (!isVertical)
	{
		for (int i = 0; i < 10; i++)
		{
			if (enemyField.returnSign(Cord, i) == SHIP || enemyField.returnSign(Cord, i) == HIT)
				enemyField.setUnit(HIT, Cord, i);
			else 
				enemyField.setUnit(MISS, Cord, i);
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (enemyField.returnSign(i, Cord) == SHIP || enemyField.returnSign(i, Cord) == HIT)
				enemyField.setUnit(HIT, i, Cord);
			else
				enemyField.setUnit(MISS, i, Cord);
		}
	}
	amountOfGunRun--;
}

// Атака "Бомбардировки". На площади в 3*3 выставляются противоположные знаки.
void ScoreStreak::bomberRunAttack(int XCord, int YCord)
{
	for (int i = -1; i < 2; i++)
	{
		if (enemyField.returnSign(XCord + i, YCord) == SHIP || enemyField.returnSign(XCord + i, YCord) == HIT)
			enemyField.setUnit(HIT, XCord + i, YCord);
		else 
			enemyField.setUnit(MISS, XCord + i, YCord);

		if (enemyField.returnSign(XCord + i, YCord - 1) == SHIP || enemyField.returnSign(XCord + i, YCord - 1) == HIT)
			enemyField.setUnit(HIT, XCord + i, YCord - 1);
		else
			enemyField.setUnit(MISS, XCord + i, YCord - 1);

		if (enemyField.returnSign(XCord + i, YCord + 1) == SHIP || enemyField.returnSign(XCord + i, YCord + 1) == HIT)
			enemyField.setUnit(HIT, XCord + i, YCord + 1);
		else
			enemyField.setUnit(MISS, XCord + i, YCord + 1);
	}
	amountOfBomberRun--;
}


