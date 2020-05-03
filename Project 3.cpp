#include <SFML/Graphics.hpp>
#include <iostream>
#include<unordered_map>
#include <string>
#include <vector>
#include <random>
#include "TextureManager.h"
#include "Board.h"
#include "Tile.h"
#include "Random.h"
using namespace std;

void LoadTextures(){
    TextureManager::LoadTexture("mine");
    TextureManager::LoadTexture("tile_hidden");
    TextureManager::LoadTexture("tile_revealed");
    TextureManager::LoadTexture("number_1");  TextureManager::LoadTexture("number_2");  TextureManager::LoadTexture("number_3");  TextureManager::LoadTexture("number_4");
    TextureManager::LoadTexture("number_5");  TextureManager::LoadTexture("number_6");  TextureManager::LoadTexture("number_7");  TextureManager::LoadTexture("number_8");
    TextureManager::LoadTexture("flag");
    TextureManager::LoadTexture("face_happy");
    TextureManager::LoadTexture("face_win");
    TextureManager::LoadTexture("face_lose");
    TextureManager::LoadTexture("digits");
    TextureManager::LoadTexture("debug");
    TextureManager::LoadTexture("test_1");
    TextureManager::LoadTexture("test_2");
    TextureManager::LoadTexture("test_3");
}

int main()
{
    // === Load all textures from file ===
    LoadTextures();
    // ================================================== 

    // === Create window===
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
    // ================================================== 

    // === Initialize board ===
    Board gameBoard;
    // ================================================== 

    // === While game is running ===
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                // LMB
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Get mouse position
                    auto pos = sf::Mouse::getPosition(window);
                    gameBoard.LeftClick(pos.x, pos.y);
                }
                // RMB
                if (event.mouseButton.button == sf::Mouse::Right) {
                    // Get mouse position
                    auto pos = sf::Mouse::getPosition(window);
                    gameBoard.RightClick(pos.x, pos.y);
                }
            }
        }

        // Display on window (refreshes every frame)
        window.clear();
        gameBoard.Display(window);
        window.display();
    }
    // ================================================== 

    return 0;
}