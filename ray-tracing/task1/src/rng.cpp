#include "rng.hpp"

RandomNumberGenerator::RandomNumberGenerator(int low, int high) {

	random_device dev;
	generator = mt19937(dev());
	distribution = uniform_int_distribution<int>(low, high); // inclusive range of distribution
}

int RandomNumberGenerator::generateNumber() {

	return distribution(generator);
}