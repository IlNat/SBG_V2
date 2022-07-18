#include <iostream>
#include "Field.h"
#pragma once

using namespace std;

class ScoreStreak
{
private:
	int amountOfGunRun;
	int amountOfBomberRun;
	Field& enemyField;
	enum { SHIP = '*', NOTHING = '#', HIT = '+', MISS = '-' };
public: 

	ScoreStreak(Field& settingEnemyField);

	void gunRunAttack(int Cord, bool isVertical);

	void bomberRunAttack(int XCord, int YCord);

	void increaseAmountOfGunRun() { amountOfGunRun++; };

	void increaseAmountOfBomberRun() { amountOfBomberRun++; };

	int returnAmountOfGunRun() { return amountOfGunRun; };

	int returnAmountOfBomberRun() { return amountOfBomberRun; };

};

