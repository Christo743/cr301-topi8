#include "stdafx.h"
#include "GameData.h"


GameData::GameData()
{
	this->bulletCount = 0;
	this->currentLevel = 0;
	this->levelScore = { 0 };
	this->maxLevelReached = 0;
	this->remainingLives = 0;

}


GameData::~GameData()
{
}
