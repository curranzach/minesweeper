#include "Tile.h"
int Tile::numRemoved = 0;

//=== Constructors ===
Tile::Tile(bool mine) {
	this->mine = mine;
	revealedTileSprite.setTexture(TextureManager::GetTexture("tile_revealed"));
	hiddenTileSprite.setTexture(TextureManager::GetTexture("tile_hidden"));
	flagSprite.setTexture(TextureManager::GetTexture("flag"));
	if (mine) {
		mineSprite.setTexture(TextureManager::GetTexture("mine"));
	}
}

//=== Functions ===
void Tile::Display(sf::RenderWindow& window, float xPos, float yPos) {
	if (revealed) { // Shows revealed tile if clicked
		revealedTileSprite.setPosition(sf::Vector2f(xPos, yPos)); // Sets sprites position, staggered 32 pixels in x and 34 in y
		window.draw(revealedTileSprite);
	}
	numAdjacentMines = 0;
	for (int i = 0; i < adjacentTiles.size(); i++) {
		if (adjacentTiles[i]->mine)
			numAdjacentMines++;
	}
	if (numAdjacentMines != 0 && !mine) { // Displays numbers for adjacent mines
		switch (numAdjacentMines) {
		case 1:
			numberSprite.setTexture(TextureManager::GetTexture("number_1"));
			break;
		case 2:
			numberSprite.setTexture(TextureManager::GetTexture("number_2"));
			break;
		case 3:
			numberSprite.setTexture(TextureManager::GetTexture("number_3"));
			break;
		case 4:
			numberSprite.setTexture(TextureManager::GetTexture("number_4"));
			break;
		case 5:
			numberSprite.setTexture(TextureManager::GetTexture("number_5"));
			break;
		case 6:
			numberSprite.setTexture(TextureManager::GetTexture("number_6"));
			break;
		case 7:
			numberSprite.setTexture(TextureManager::GetTexture("number_7"));
			break;
		case 8:
			numberSprite.setTexture(TextureManager::GetTexture("number_8"));
			break;
		}
		numberSprite.setPosition(sf::Vector2f(xPos, yPos));
		window.draw(numberSprite);
	}
	if (!revealed) { // Shows hidden tile if not clicked
		hiddenTileSprite.setPosition(sf::Vector2f(xPos, yPos)); // Sets sprites position, staggered 32 pixels in x and 34 in y
		window.draw(hiddenTileSprite);
	}
	if (flagged) {
		flagSprite.setPosition(sf::Vector2f(xPos, yPos));
		window.draw(flagSprite);
	}
	if (mine && revealed) { // Displays mines if revealed
		mineSprite.setPosition(sf::Vector2f(xPos, yPos)); // Sets sprites position, staggered 32 pixels in x and 34 in y
		window.draw(mineSprite);
	}
}

void Tile::LeftClick() {
	// Check to see if mouse pos is inside any of sprites
	if (mine && !flagged) {
		revealed = true;
		lose = true;
	} // if not revealed and no adjacent mines, reveal
	if (!revealed && !mine && numAdjacentMines == 0 && !flagged) {
		revealed = true;
		numRemoved++;
		for (int i = 0; i < adjacentTiles.size(); i++) { // for each adjacent tile, check adjacent tiles
			if (adjacentTiles[i]->numAdjacentMines > 0 && adjacentTiles[i]->flagged == false) {
				if (adjacentTiles[i]->revealed != true) { numRemoved++; }
				adjacentTiles[i]->revealed = true;
			}
			else {
				adjacentTiles[i]->LeftClick();
			}
		}
	}
	if (!revealed && !mine && numAdjacentMines > 0 && !flagged) {
		revealed = true;
		numRemoved++;
	}
}

bool Tile::RightClick() {
	// Returns true if flag placed and false if flag removed
	if (!flagged && !revealed) {
		flagged = true;
		return true;
	}
	else {
		flagged = false;
		return false;
	}
}

void Tile::SetPosition(float xPos, float yPos) {
	this->xPos = xPos;
	this->yPos = yPos;
}

void Tile::Reset() {
	mine = false;
	revealed = false;
	flagged = false;
	winCondition = false;
	numAdjacentMines = 0;
	numRemoved = 0;
	adjacentTiles.clear();
	xPos = 0;
	yPos = 0;
}

void Tile::ToggleDebug() {
	if (!debugMode) {
		debugMode = true;
	}
	else {
		debugMode = false;
	}
}

bool Tile::CheckLoss() {
	return lose;
}

int Tile::GetNumRemoved() {
	return numRemoved;
}
