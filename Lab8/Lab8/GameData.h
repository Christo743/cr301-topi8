#pragma once
#include <iostream>
#include <list>

using namespace std;

class GameData
{
public:

	GameData();

	int currentLevel;
	int remainingLives;
	int bulletCount;
	int maxLevelReached;
	list<int> levelScore;

	~GameData();

};

