#include "color.hpp"

enum class Color {
	white, black, blue, yellow
};

Color getColor(Vector2D point) {

	if (in_earth(point)) {

		return Color::blue;
	}

	if (in_sun(point)) {

		return Color::yellow;
	}

	if (in_planetary_ellipse(point)) {

		return Color::white;
	}

	// space
	return Color::black;
}

void writeColor(ofstream& stream, Vector2D point) {

	Color color = getColor(point);

	switch (color) {

		case Color::white:

			stream << "\t255 255 255";
			break;

		case Color::black:

			stream << "\t0 0 0";
			break;

		case Color::blue:

			stream << "\t0 0 255";
			break;

		case Color::yellow:

			stream << "\t255 255 0";
			break;

		default:

			break;
	}
}