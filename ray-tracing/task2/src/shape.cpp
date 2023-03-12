#include "shape.hpp"

// Let our sunOrigin vector vo = [xo, yo] be in the center of the image.
// We take the ellipse formula and we use the parameters for Earth's real path around the Sun.
// r^2 <= (x-xo)^2/150 + (y-yo)^2/149.9783 <= R^2
// The planetary ellipse equation parameters were derived from the paper https://www.ijsrp.org/research-paper-0516/ijsrp-p5328.pdf
const int xo = Width / 2;
const int yo = Height / 2;
const Vector2D sunOrigin = Vector2D(xo, yo);

const int rSquared = 28 * 28;
const int RSquared = 30 * 30;

// To visualize the Earth we place it at the top of the ellipse,
// so for earthOrigin we choose the grid location where x=xo.
// We pick a radius r < 29 < R, so that we visualize Earth within the ellipse.
// (y-yo)^2/149.9783 = 29^2, where yo is known.
// We simplify to a quadratic equation with a=1, b=-1080, c=165468.2497
// The resulting roots lying on the ellipse are y1 = 895.15, y2=184.85
// We round y1 down to 895.
const Vector2D earthOrigin = Vector2D(xo, 895);

bool in_planetary_ellipse(Vector2D point) {

	const int xOffset = point.x() - sunOrigin.x();
	const int yOffset = point.y() - sunOrigin.y();

	double ellipse = (xOffset * xOffset) / 150 + (yOffset * yOffset) / 149.9783;
	return ellipse <= RSquared && ellipse >= rSquared;
}

bool in_sun(Vector2D point) {

	const int xOffset = point.x() - sunOrigin.x();
	const int yOffset = point.y() - sunOrigin.y();

	return (xOffset * xOffset) + (yOffset * yOffset) <= 40*40;
}

bool in_earth(Vector2D point) {

	const int xOffset = point.x() - earthOrigin.x();
	const int yOffset = point.y() - earthOrigin.y();

	return (xOffset * xOffset) + (yOffset * yOffset) <= 25*25;
}