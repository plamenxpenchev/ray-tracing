#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include <string>

#include "ratio.hpp"
#include "color.hpp"
#include "vector_3d.hpp"
#include "ray.hpp"

using std::set;
using std::string;
using std::ofstream;
using std::abs;
using std::cin;
using std::cout;
using std::runtime_error;

Ray createRay(const Point3D& origin, float x, float y, float width, float height) {
	// Find center based on raster coordinates
	x += 0.5f;
	y += 0.5f;

	// Convert raster coordinates to NDC space [0.0, 1.0]
	x /= width;
	y /= height;

	// Convert NDC coordinates to Screen space [-1.0, 1.0]
	x = (2.0f * x) - 1.0f;
	y = 1.0f - (2.0f * y);

	// Consider the aspect ratio
	float aspectRatio = width / height;
	x *= aspectRatio;

	Vector3D direction = Vector3D{x, y, -1.0f};
	direction.normalize();

	return Ray{origin, direction};
}

int main() {
	set<string> supportedResolutions = { "4K", "1080p", "720p" };
	cout << "Please enter one of 4K, 1080p and 720p to select the resolution of the produced image: \n";
	string res;
	bool validRes = false;
	while (!validRes && cin >> res) {
		auto search = supportedResolutions.find(res);
		validRes = search != supportedResolutions.end();
	}
	
	float width = 0.0f;
	float height = 0.0f;

	if (res == "4K") {
		width = Width4K;
		height = Height4K;
	} else if (res == "1080p") {
		width = Width1080p;
		height = Height1080p;
	} else if (res == "720p") {
		width = Width720p;
		height = Height720p;
	} else {
		throw runtime_error("unexpected resolution");
	}

	cout << "Enter the file name where you want to store the image: \n";
	string filename;
	cin >> filename;

	// implicitly closed file when out of scope
	ofstream outputFileStream{ filename };

	if (!outputFileStream) {

		throw runtime_error("Can't open file with name " + filename);
	}

	outputFileStream << "P3\n";
	outputFileStream << width << ' ' << height << '\n';
	outputFileStream << MaxColor;

	const Point3D worldOrigin = Point3D{};

	for (int y = 0; y < height; y++) {
		outputFileStream << '\n';
		for (int x = 0; x < width; x++) {
			Ray ray = createRay(worldOrigin, x, y, width, height);
			Color color = Color{
				abs(ray.getDirection().x() * 255),
				abs(ray.getDirection().y() * 255),
				abs(ray.getDirection().z() * 255)
			};
			writeColor(outputFileStream, color);
		}
	}
}