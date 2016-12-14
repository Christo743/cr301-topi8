#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	this->id = 0;
	this->country = "";
	this->email = "";
	this->dateOfBirth = "";
	this->name = "";

	this->gameData = GameData();
	this->preference = Preference();
}


Player::~Player()
{
}
