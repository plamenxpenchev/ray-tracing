#pragma once

#include "ratio.hpp"
#include "vector_3d.hpp"

#include <fstream>
#include <sstream>

using std::string;
using std::ofstream;
using std::stringstream;

void writeColor(ofstream& stream, Color color);

const int MinColor = 0;
const int MaxColor = 255;