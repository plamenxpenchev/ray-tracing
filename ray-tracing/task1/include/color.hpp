#pragma once

#include "rng.hpp"
#include "ratio.hpp"

#include <fstream>
#include <sstream>

using std::string;
using std::ofstream;
using std::stringstream;

void writeColor(ofstream& stream, RandomNumberGenerator& generator, const int& width, const int& height);

const int MinColor = 0;
const int MaxColor = 255;