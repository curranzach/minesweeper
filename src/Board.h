#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include "TextureManager.h"
#include "Tile.h"

class Board {
	Tile* board[25][16];
	int mineLocations[25][16];
	int numMines;
	int startingMines;
	int numTiles;
	bool win = false;
	bool lose = false;
	bool debugMode = false;
	//=== Sprites ===
	sf::Sprite happyFace;
	sf::Sprite winFace;
	sf::Sprite loseFace;
	sf::Sprite digit0, digit1, digit2, digit3, digit4, digit5;
	sf::Sprite digit6, digit7, digit8, digit9, digitMinus;
	sf::Sprite debug;
	sf::Sprite test1;
	sf::Sprite test2;
	sf::Sprite test3;
	// ==================================== 
public:
	// Constructors
	Board();
	// Functions
	void Display(sf::RenderWindow& window);
	void DisplayDigits(sf::RenderWindow& window);
	void LeftClick(float xPos, float yPos);
	void IntializeButtons();
	void ToggleDebug();
	void Restart();
	void Restart(int testNum);
	void RightClick(float xPos, float yPos);
	void Update();

};

