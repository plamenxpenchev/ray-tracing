#pragma once

#include <cstdlib>
#include <random>

using std::string;
using std::random_device;
using std::mt19937;  // the Mersenne Twister RNG
using std::uniform_int_distribution;

class RandomNumberGenerator {
private:
	mt19937 generator;
	uniform_int_distribution<int> distribution;
public:
	RandomNumberGenerator(int low, int high);
	int generateNumber();
};