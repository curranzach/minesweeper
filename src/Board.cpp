#include "Board.h"

void Board::Display(sf::RenderWindow& window) {
	Update();
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 16; j++) {
			board[i][j]->Display(window, (float)i * 32, (float)j * 32); // Sets sprites position, staggered 32 pixels in x and 34 in y
		}
	}
	if ((!lose && !win)) {
		window.draw(happyFace);
	}
	else if (lose) {
		window.draw(loseFace);
	}
	else if (win) {
		window.draw(winFace);
	}
	window.draw(debug);
	window.draw(test1);
	window.draw(test2);
	window.draw(test3);
	DisplayDigits(window);
}

void Board::LeftClick(float xPos, float yPos) {
	// Check if click is on a tile
	if (yPos <= 512) {
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 16; j++) {
				if (board[i][j]->hiddenTileSprite.getGlobalBounds().contains(sf::Vector2f(xPos, yPos)) && !lose) {
					board[i][j]->LeftClick();
					// After each click, check for win or loss and update board accordingly
					lose = board[i][j]->CheckLoss();
					Update();
				}
			}
		}
	} // If not on tile, check click if on debug button
	else if (debug.getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		ToggleDebug();
	} // Check if click on restart button
	else if (happyFace.getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		Restart();
	}
	else if (test1.getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		Restart(1);
	}
	else if (test2.getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		Restart(2);
	}
	else if (test3.getGlobalBounds().contains(sf::Vector2f(xPos, yPos))) {
		Restart(3);
	}
}

void Board::RightClick(float xPos, float yPos) {
	if (yPos <= 512) {
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 16; j++) {
				if (board[i][j]->hiddenTileSprite.getGlobalBounds().contains(sf::Vector2f(xPos, yPos)) && !lose) {
					bool toCheck = board[i][j]->RightClick();
					if (toCheck) {
						numMines--;
					}
					else if (!toCheck && board[i][j]->revealed!=true) {
						numMines++;
					}
				}
			}
		}
	}
}

void Board::IntializeButtons() {
	// Initialize buttons
	happyFace.setTexture(TextureManager::GetTexture("face_happy"));
	happyFace.setPosition(415, 510);
	winFace.setTexture(TextureManager::GetTexture("face_win"));;
	winFace.setPosition(415, 510);
	loseFace.setTexture(TextureManager::GetTexture("face_lose"));
	loseFace.setPosition(415, 510);
	debug.setTexture(TextureManager::GetTexture("debug"));;
	debug.setPosition(540, 510);
	test1.setTexture(TextureManager::GetTexture("test_1"));;
	test1.setPosition(605, 510);
	test2.setTexture(TextureManager::GetTexture("test_2"));
	test2.setPosition(670, 510);
	test3.setTexture(TextureManager::GetTexture("test_3"));
	test3.setPosition(735, 510);
	digit0.setTexture(TextureManager::GetTexture("digits"));
	digit1.setTexture(TextureManager::GetTexture("digits"));
	digit2.setTexture(TextureManager::GetTexture("digits"));
	digit3.setTexture(TextureManager::GetTexture("digits"));
	digit4.setTexture(TextureManager::GetTexture("digits"));
	digit5.setTexture(TextureManager::GetTexture("digits"));
	digit6.setTexture(TextureManager::GetTexture("digits"));
	digit7.setTexture(TextureManager::GetTexture("digits"));
	digit8.setTexture(TextureManager::GetTexture("digits"));
	digit9.setTexture(TextureManager::GetTexture("digits"));
	digitMinus.setTexture(TextureManager::GetTexture("digits"));

}

void Board::DisplayDigits(sf::RenderWindow& window) {
	string temp = std::to_string(numMines);
	char digitArray[] = { 'a', 'a', 'a', 'a' };
	for (int i = 0; i < temp.size(); i++) {
		digitArray[i] = temp[i];
	}
	for (int i = 0; i < temp.size(); i++) {
		if (i == 0) {
			if (digitArray[i] == '0') {
				digit0.setTextureRect(sf::IntRect(0, 0, 21, 32));
				digit0.setPosition(0, 520);
				window.draw(digit0);
			}
			if (digitArray[i] == '1') {
				digit1.setTextureRect(sf::IntRect(21, 0, 21, 32));
				digit1.setPosition(0, 520);
				window.draw(digit1);
			}
			if (digitArray[i] == '2') {
				digit2.setTextureRect(sf::IntRect(42, 0, 21, 32));
				digit2.setPosition(0, 520);
				window.draw(digit2);
			}
			if (digitArray[i] == '3') {
				digit3.setTextureRect(sf::IntRect(63, 0, 21, 32));
				digit3.setPosition(0, 520);
				window.draw(digit3);
			}
			if (digitArray[i] == '4') {
				digit4.setTextureRect(sf::IntRect(84, 0, 21, 32));
				digit4.setPosition(0, 520);
				window.draw(digit4);
			}
			if (digitArray[i] == '5') {
				digit5.setTextureRect(sf::IntRect(105, 0, 21, 32));
				digit5.setPosition(0, 520);
				window.draw(digit5);
			}
			if (digitArray[i] == '6') {
				digit6.setTextureRect(sf::IntRect(126, 0, 21, 32));
				digit6.setPosition(0, 520);
				window.draw(digit6);
			}
			if (digitArray[i] == '7') {
				digit7.setTextureRect(sf::IntRect(147, 0, 21, 32));
				digit7.setPosition(0, 520);
				window.draw(digit7);
			}
			if (digitArray[i] == '8') {
				digit8.setTextureRect(sf::IntRect(168, 0, 21, 32));
				digit8.setPosition(0, 520);
				window.draw(digit8);
			}
			if (digitArray[i] == '9') {
				digit9.setTextureRect(sf::IntRect(189, 0, 21, 32));
				digit9.setPosition(0, 520);
				window.draw(digit9);
			}
			if (digitArray[i] == '-') {
				digitMinus.setTextureRect(sf::IntRect(210, 0, 21, 32));
				digitMinus.setPosition(0, 520);
				window.draw(digitMinus);
			}
		}
		if (i == 1) {
			if (digitArray[i] == '0') {
				digit0.setTextureRect(sf::IntRect(0, 0, 21, 32));
				digit0.setPosition(21, 520);
				window.draw(digit0);
			}
			if (digitArray[i] == '1') {
				digit1.setTextureRect(sf::IntRect(21, 0, 21, 32));
				digit1.setPosition(21, 520);
				window.draw(digit1);
			}
			if (digitArray[i] == '2') {
				digit2.setTextureRect(sf::IntRect(42, 0, 21, 32));
				digit2.setPosition(21, 520);
				window.draw(digit2);
			}
			if (digitArray[i] == '3') {
				digit3.setTextureRect(sf::IntRect(63, 0, 21, 32));
				digit3.setPosition(21, 520);
				window.draw(digit3);
			}
			if (digitArray[i] == '4') {
				digit4.setTextureRect(sf::IntRect(84, 0, 21, 32));
				digit4.setPosition(21, 520);
				window.draw(digit4);
			}
			if (digitArray[i] == '5') {
				digit5.setTextureRect(sf::IntRect(105, 0, 21, 32));
				digit5.setPosition(21, 520);
				window.draw(digit5);
			}
			if (digitArray[i] == '6') {
				digit6.setTextureRect(sf::IntRect(126, 0, 21, 32));
				digit6.setPosition(21, 520);
				window.draw(digit6);
			}
			if (digitArray[i] == '7') {
				digit7.setTextureRect(sf::IntRect(147, 0, 21, 32));
				digit7.setPosition(21, 520);
				window.draw(digit7);
			}
			if (digitArray[i] == '8') {
				digit8.setTextureRect(sf::IntRect(168, 0, 21, 32));
				digit8.setPosition(21, 520);
				window.draw(digit8);
			}
			if (digitArray[i] == '9') {
				digit9.setTextureRect(sf::IntRect(189, 0, 21, 32));
				digit9.setPosition(21, 520);
				window.draw(digit9);
			}
			if (digitArray[i] == '-') {
				digitMinus.setTextureRect(sf::IntRect(210, 0, 21, 32));
				digitMinus.setPosition(21, 520);
				window.draw(digitMinus);
			}
		}
		if (i == 2) {
			if (digitArray[i] == '0') {
				digit0.setTextureRect(sf::IntRect(0, 0, 21, 32));
				digit0.setPosition(42, 520);
				window.draw(digit0);
			}
			if (digitArray[i] == '1') {
				digit1.setTextureRect(sf::IntRect(21, 0, 21, 32));
				digit1.setPosition(42, 520);
				window.draw(digit1);
			}
			if (digitArray[i] == '2') {
				digit2.setTextureRect(sf::IntRect(42, 0, 21, 32));
				digit2.setPosition(42, 520);
				window.draw(digit2);
			}
			if (digitArray[i] == '3') {
				digit3.setTextureRect(sf::IntRect(63, 0, 21, 32));
				digit3.setPosition(42, 520);
				window.draw(digit3);
			}
			if (digitArray[i] == '4') {
				digit4.setTextureRect(sf::IntRect(84, 0, 21, 32));
				digit4.setPosition(42, 520);
				window.draw(digit4);
			}
			if (digitArray[i] == '5') {
				digit5.setTextureRect(sf::IntRect(105, 0, 21, 32));
				digit5.setPosition(42, 520);
				window.draw(digit5);
			}
			if (digitArray[i] == '6') {
				digit6.setTextureRect(sf::IntRect(126, 0, 21, 32));
				digit6.setPosition(42, 520);
				window.draw(digit6);
			}
			if (digitArray[i] == '7') {
				digit7.setTextureRect(sf::IntRect(147, 0, 21, 32));
				digit7.setPosition(42, 520);
				window.draw(digit7);
			}
			if (digitArray[i] == '8') {
				digit8.setTextureRect(sf::IntRect(168, 0, 21, 32));
				digit8.setPosition(42, 520);
				window.draw(digit8);
			}
			if (digitArray[i] == '9') {
				digit9.setTextureRect(sf::IntRect(189, 0, 21, 32));
				digit9.setPosition(42, 520);
				window.draw(digit9);
			}
			if (digitArray[i] == '-') {
				digitMinus.setTextureRect(sf::IntRect(210, 0, 21, 32));
				digitMinus.setPosition(42, 520);
				window.draw(digitMinus);
			}
		}
		if (i == 3) {
			if (digitArray[i] == '0') {
				digit0.setTextureRect(sf::IntRect(0, 0, 21, 32));
				digit0.setPosition(63, 520);
				window.draw(digit0);
			}
			if (digitArray[i] == '1') {
				digit1.setTextureRect(sf::IntRect(21, 0, 21, 32));
				digit1.setPosition(63, 520);
				window.draw(digit1);
			}
			if (digitArray[i] == '2') {
				digit2.setTextureRect(sf::IntRect(42, 0, 21, 32));
				digit2.setPosition(63, 520);
				window.draw(digit2);
			}
			if (digitArray[i] == '3') {
				digit3.setTextureRect(sf::IntRect(63, 0, 21, 32));
				digit3.setPosition(63, 520);
				window.draw(digit3);
			}
			if (digitArray[i] == '4') {
				digit4.setTextureRect(sf::IntRect(84, 0, 21, 32));
				digit4.setPosition(63, 520);
				window.draw(digit4);
			}
			if (digitArray[i] == '5') {
				digit5.setTextureRect(sf::IntRect(105, 0, 21, 32));
				digit5.setPosition(63, 520);
				window.draw(digit5);
			}
			if (digitArray[i] == '6') {
				digit6.setTextureRect(sf::IntRect(126, 0, 21, 32));
				digit6.setPosition(63, 520);
				window.draw(digit6);
			}
			if (digitArray[i] == '7') {
				digit7.setTextureRect(sf::IntRect(147, 0, 21, 32));
				digit7.setPosition(63, 520);
				window.draw(digit7);
			}
			if (digitArray[i] == '8') {
				digit8.setTextureRect(sf::IntRect(168, 0, 21, 32));
				digit8.setPosition(63, 520);
				window.draw(digit8);
			}
			if (digitArray[i] == '9') {
				digit9.setTextureRect(sf::IntRect(189, 0, 21, 32));
				digit9.setPosition(63, 520);
				window.draw(digit9);
			}
			if (digitArray[i] == '-') {
				digitMinus.setTextureRect(sf::IntRect(210, 0, 21, 32));
				digitMinus.setPosition(63, 520);
				window.draw(digitMinus);
			}
		}
	}
}

void Board::Update() {
	// If loss, make all mines show
	numTiles = Tile::GetNumRemoved();
	if (lose) {
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 16; j++) {
				if (board[i][j]->mine) {
					board[i][j]->revealed = true;
				}
			}
		}
	}
	if (numTiles == (400 - startingMines) && numMines == 0) {
		win = true;
	}
}

void Board::ToggleDebug() {
	// If you haven't lost, make all tiles show bombs or turn off showing bombs
	if (!debugMode && !lose) {
		debugMode = true;
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 16; j++) {
				if (board[i][j]->mine) {
					board[i][j]->revealed = true;
				}
			}
		}
	}
	else if (debugMode) {
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 16; j++) {
				if (board[i][j]->mine) {
					board[i][j]->revealed = false;
				}
			}
		}
		if(!lose)
			debugMode = false;
	}
	
}

void Board::Restart() {
	lose = false;
	win = false;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 16; j++) {
			mineLocations[i][j] = 0;
			board[i][j]->Reset();
			delete board[i][j];
		}
	}

	numMines = 0;
	// While less than 50 mines, choose a random spot on the board to place a mine
	int randomX = Random::Number(0, 24);
	int randomY = Random::Number(0, 15);
	while (numMines < 50) {
		if (mineLocations[randomX][randomY] == 1) { // If there is already a mine, continue
			randomX = Random::Number(0, 24);
			randomY = Random::Number(0, 15);
		}
		else { // If there is not a mine, place it and create a tile with mine bool = true
			mineLocations[randomX][randomY] = 1;
			numMines++;
			board[randomX][randomY] = new Tile(true);
			randomX = Random::Number(0, 24);
			randomY = Random::Number(0, 15);
		}
	}

	// Fill each slot in the board with corresponding tiles
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 16; j++) {
			if (mineLocations[i][j] == 0) {
				Tile* newTile = new Tile(false);
				board[i][j] = newTile;
			}
		}
	}

	// Determine adjacent mines
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 16; j++) {
			// Check x - 1
			if (i - 1 > -1) {
				board[i][j]->adjacentTiles.push_back(board[i - 1][j]);
			}
			// Check x + 1
			if (i + 1 < 25) {
				board[i][j]->adjacentTiles.push_back(board[i + 1][j]);
			}
			// Check y - 1
			if (j - 1 > -1) {
				board[i][j]->adjacentTiles.push_back(board[i][j - 1]);
			}
			// Check y + 1
			if (j + 1 < 16) {
				board[i][j]->adjacentTiles.push_back(board[i][j + 1]);
			}
		}
	}
	startingMines = numMines;
}

void Board::Restart(int testNum) {
	lose = false;
	win = false;
	numMines = 0;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 16; j++) {
			mineLocations[i][j] = 0;
			board[i][j]->Reset();
			delete board[i][j];
		}
	}

	//=== Load board ===
	string filename = "boards/testboard" + std::to_string(testNum);
	filename += ".brd";
	std::ifstream file(filename);
	int lineCount = 0;
	string line;
	if (file.is_open()){
		// Count number of lines
		while (std::getline(file, line)) { lineCount++; }
		// Reset getLine to beginning of file
		file.clear();
		file.seekg(0);
		vector<string> vec;
		// Loop numLines times
		for (int i = 0; i < lineCount ; i++) {
			std::getline(file, line);
			vec.push_back(line);
		}
		string temp;
		for (int i = 0; i < vec.size(); i++) {
			temp = vec[i];
			for (int j = 0; j < temp.size(); j++) {
				if(temp[j] == '1') {
					mineLocations[j][i] = 1;
					Tile* newTile = new Tile(true);
					board[j][i] = newTile;
					numMines++;
				}
				else {
					mineLocations[j][i] = 0;
					Tile* newTile = new Tile(false);
					board[j][i] = newTile;
				}
			}
		}	
	}

	// Determine adjacent tiles
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 16; j++) {
			// Check x - 1
			if (i - 1 > -1) {
				board[i][j]->adjacentTiles.push_back(board[i - 1][j]);
				if (j - 1 > -1) {
					board[i][j]->adjacentTiles.push_back(board[i - 1][j - 1]);
				}
				if (j + 1 < 16) {
					board[i][j]->adjacentTiles.push_back(board[i - 1][j + 1]);
				}
			}
			// Check x + 1
			if (i + 1 < 25) {
				board[i][j]->adjacentTiles.push_back(board[i + 1][j]);
				if (j - 1 > -1) {
					board[i][j]->adjacentTiles.push_back(board[i + 1][j - 1]);
				}
				if (j + 1 < 16) {
					board[i][j]->adjacentTiles.push_back(board[i + 1][j + 1]);
				}
			}
			// Check y - 1
			if (j - 1 > -1) {
				board[i][j]->adjacentTiles.push_back(board[i][j - 1]);
			}
			// Check y + 1
			if (j + 1 < 16) {
				board[i][j]->adjacentTiles.push_back(board[i][j + 1]);
			}
		}
	}
	startingMines = numMines;
}

Board::Board() { // Initializes board

	// Create 2D int array and fill all slots with 0 (no mine)
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 16; j++) {
			mineLocations[i][j] = 0;
		}
	}

	numMines = 0;
	// While less than 50 mines, choose a random spot on the board to place a mine
	int randomX = Random::Number(0, 24);
	int randomY = Random::Number(0, 15);
	while (numMines < 50) {
		if (mineLocations[randomX][randomY] == 1) { // If there is already a mine, continue
			randomX = Random::Number(0, 24);
			randomY = Random::Number(0, 15);
		}
		else { // If there is not a mine, place it and create a tile with mine bool = true
			mineLocations[randomX][randomY] = 1;
			numMines++;
			board[randomX][randomY] = new Tile(true);
			randomX = Random::Number(0, 24);
			randomY = Random::Number(0, 15);
		}
	}

	// Fill each slot in the board with corresponding tiles
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 16; j++) {
			if (mineLocations[i][j] == 0) {
				Tile* newTile = new Tile(false);
				board[i][j] = newTile;
			}
		}
	}

	// Determine adjacent mines
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 16; j++) {
			// Check x - 1
			if (i - 1 > -1) {
				board[i][j]->adjacentTiles.push_back(board[i - 1][j]);
			}
			// Check x + 1
			if (i + 1 < 25) {
				board[i][j]->adjacentTiles.push_back(board[i + 1][j]);
			}
			// Check y - 1
			if (j - 1 > -1) {
				board[i][j]->adjacentTiles.push_back(board[i][j-1]);
			}
			// Check y + 1
			if (j + 1 < 16) {
				board[i][j]->adjacentTiles.push_back(board[i][j+1]);
			}
		}
	}
	this->IntializeButtons();
	startingMines = numMines;
}
