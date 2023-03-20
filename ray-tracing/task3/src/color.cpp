#include "color.hpp"

void writeColor(ofstream& stream, Color color) {
	stream << '\t' << color[0] << ' ' << color[1] << ' ' << color[2];
}