#include <iostream>
#include <fstream>

#include "ratio.hpp"
#include "color.hpp"
#include "vector_2d.hpp"

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
	ofstream outputFileStream{ filename };

	if (!outputFileStream) {

		throw runtime_error("Can't open file with name " + filename);
	}

	outputFileStream << "P3\n";
	outputFileStream << Width << ' ' << Height << '\n';
	outputFileStream << MaxColor;

	// Since we fill the file from top to bottom and we want to stay 
	// in the first quadrant of the Cartesian plane (positive x and y), 
	// we decrement the y values and we increment the x to properly 
	// compare against the shape equation.
	for (int y = Height - 1; y >= 0; y--) {

		outputFileStream << '\n';

		for (int x = 0; x < Width; x++) {

			Vector2D point = Vector2D(x,y);
			writeColor(outputFileStream, point);
		}
	}
}