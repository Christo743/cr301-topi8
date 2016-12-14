#include "stdafx.h"
#include "JsonHelper.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "GameData.h"
#include "Preference.h"
#include <array>

namespace pt = boost::property_tree;


JsonHelper::JsonHelper()
{
}

void JsonHelper::SaveToFile(string filename, Player player)
{
	pt::ptree root;

	root.put("id", player.id);
	root.put("name", player.name);
	root.put("dateOfBirth", player.dateOfBirth);
	root.put("country", player.country);
	root.put("email", player.email);

	GameData gameData = player.gameData;
	pt::ptree playerGameData;

	playerGameData.put("currentLevel", gameData.currentLevel);
	playerGameData.put("remainingLives", gameData.remainingLives);
	playerGameData.put("bulletCount", gameData.bulletCount);
	playerGameData.put("maxLevelReached", gameData.maxLevelReached);

	// Create the level score array
	pt::ptree levelScores;
	for (auto &score : gameData.levelScore)
	{
		// Create an unnamed node containing the value
		pt::ptree score_node;
		score_node.put("", score);

		// Add this node to the list.
		levelScores.push_back(std::make_pair("", score_node));
	}
	playerGameData.add_child("levelScore", levelScores);
	root.add_child("gameData", playerGameData);

	Preference preference = player.preference;
	pt::ptree playerPreference;

	playerPreference.put("language", preference.language);
	playerPreference.put("volumelevel", preference.volumelevel);
	playerPreference.put("graphic", preference.graphic);
	playerPreference.put("difficulty", preference.difficulty);
	root.add_child("preference", playerPreference);

	// Once our ptree was constructed, we can generate JSON on standard output
	pt::write_json(std::cout, root);
	pt::write_json(filename, root);
}

Player JsonHelper::ReadFromFile(string filename)
{
	Player thePlayer = Player();
	pt::ptree root;

	// Load the json file in this ptree
	pt::read_json(filename, root);
	thePlayer.id = root.get<int>("id", 0);
	thePlayer.name = root.get<string>("name", "");
	thePlayer.dateOfBirth = root.get<string>("dateOfBirth", "");
	thePlayer.country = root.get<string>("country", "");
	thePlayer.email = root.get<string>("email", "");

	GameData theGameData = GameData();

	std::vector<std::string> scores;
	for (pt::ptree::value_type &levelScore : root.get_child("gameData.levelScore"))
	{
		theGameData.levelScore.push_back(stoi(levelScore.second.data()));
			scores.push_back(levelScore.second.data());
	}
	theGameData.currentLevel = root.get<int>("gameData.currentLevel", 0);
	theGameData.remainingLives = root.get<int>("gameData.remainingLives", 0);
	theGameData.bulletCount = root.get<int>("gameData.bulletCount", 0);
	theGameData.maxLevelReached = root.get<int>("gameData.maxLevelReached", 0);
	thePlayer.gameData = theGameData;

	Preference thePreference = Preference();
	
	thePreference.difficulty = root.get<int>("preference.difficulty", 0);
	thePreference.graphic = root.get<string>("preference.graphic", "");
	thePreference.language = root.get<string>("preference.language", "");
	thePreference.volumelevel = root.get<int>("preference.volumelevel", 0);
	thePlayer.preference = thePreference;

	return thePlayer;

}


JsonHelper::~JsonHelper()
{
}
