#pragma once

#include "ratio.hpp"
#include "vector_2d.hpp"
#include "shape.hpp"

#include <fstream>
#include <sstream>

using std::string;
using std::ofstream;
using std::stringstream;

void writeColor(ofstream& stream, Vector2D point);

const int MinColor = 0;
const int MaxColor = 255;