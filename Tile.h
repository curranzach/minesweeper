#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
#include <string>
#include "TextureManager.h"
#include "Random.h"

using std::vector;

class Tile {
	static int numRemoved;
	sf::Sprite revealedTileSprite;
	sf::Sprite mineSprite;
	sf::Sprite numberSprite;
	sf::Sprite flagSprite;
	sf::Sprite digitsSprite;
public:
	vector<Tile*> adjacentTiles; // Vector storing pointers of all adjacent tiles
	sf::Sprite hiddenTileSprite;
	bool revealed = false;
	bool winCondition = false;
	bool lose = false;
	bool flagged = false;
	bool mine;
	bool debugMode;
	int numAdjacentMines = 0;
	float xPos;
	float yPos;
	// Constructors
	Tile(bool mine);
	// Functions
	void Display(sf::RenderWindow& window, float xPos, float yPos);
	void LeftClick();
	bool RightClick();
	void SetPosition(float xPos, float yPos);
	void Reset();
	static int GetNumRemoved();
	bool CheckLoss();
	void ToggleDebug();

};

