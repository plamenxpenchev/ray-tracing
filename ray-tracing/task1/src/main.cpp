#include <iostream>
#include <fstream>

#include "ratio.hpp"
#include "rng.hpp"
#include "color.hpp"

using std::string;
using std::ofstream;
using std::cin;
using std::cout;
using std::runtime_error;

int main() {

	cout << "Enter the file name where you want to store the image: ";
	string filename;
	cin >> filename;

	// implicitly closed file when out of scope
	ofstream outputFileStream{filename};

	if (!outputFileStream) {

		throw runtime_error("Can't open file with name " + filename);
	}

	RandomNumberGenerator rng = RandomNumberGenerator(MinColor, MaxColor);

	outputFileStream << "P3\n";
	outputFileStream << Width << ' ' << Height << '\n';
	outputFileStream << MaxColor;

	for (int i = 0; i < Height; i++) {

		outputFileStream << '\n';

		for (int j = 0; j < Width; j++) {

			writeColor(outputFileStream, rng, j, i);
		}
	}
}