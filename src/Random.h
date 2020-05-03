#pragma once
#include <random>
#include <ctime>
#include "TextureManager.h"

class Random {
	static std::mt19937 random;
public:
	static int Number(int min, int max);
};

