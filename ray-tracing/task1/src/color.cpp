#include "color.hpp"

const int Width1 = Width / 4;
const int Width2 = 2 * (Width1);
const int Width3 = 3 * (Width1);

const int Height1 = Height / 4;
const int Height2 = 2 * (Height1);
const int Height3 = 3 * (Height1);

enum class Color {
	red, green, blue, yellow, purple, cyan
};

Color getColor(int width, int height) {

	if (height < Height1 || height >= Height3) {

		if (width < Width1) return Color::red;
		else if (width < Width2) return Color::green;
		else if (width < Width3) return Color::yellow;
		else return Color::blue;

	} else if (height < Height2) {

		if (width < Width1) return Color::purple;
		else if (width < Width2) return Color::cyan;
		else if (width < Width3) return Color::red;
		else return Color::green;

	} else {

		if (width < Width1) return Color::yellow;
		else if (width < Width2) return Color::blue;
		else if (width < Width3) return Color::purple;
		else return Color::cyan;
	}
}

void writeColor(ofstream& stream, RandomNumberGenerator& rng, const int& width, const int& height) {

	Color color = getColor(width, height);

	switch (color) {

		case Color::red:

			stream << '\t' << rng.generateNumber() << ' ' << 0 << ' ' << 0;
			break;

		case Color::green:

			stream << '\t' << 0 << ' ' << rng.generateNumber() << ' ' << 0;
			break;

		case Color::blue:

			stream << '\t' << 0 << ' ' << 0 << ' ' << rng.generateNumber();
			break;

		case Color::yellow:

			stream << '\t' << rng.generateNumber() << ' ' << rng.generateNumber() << ' ' << 0;
			break;

		case Color::purple:

			stream << '\t' << rng.generateNumber() << ' ' << 0 << ' ' << rng.generateNumber();
			break;

		case Color::cyan:

			stream << '\t' << 0 << ' ' << rng.generateNumber() << ' ' << rng.generateNumber();
			break;

		default:

			break;
		}
}