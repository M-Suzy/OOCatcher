#include "point.h"
#include "point.h"

point::point()
{
	x = 0;
	y = 0;
}

point::point(double fresh_x, double fresh_y)
{
	x = fresh_x;
	y = fresh_y;
}

double point::get_x() const
{
	return x;
}

double point::get_y() const
{
	return y;
}

int point::int_x() const
{
	return x + (x > 0 ? 0.5 : -0.5);
}

int point::int_y() const
{
	return y + (y > 0 ? 0.5 : -0.5);
}

void point::shift(double dx, double dy)
{
	x += dx;
	y += dy;
}

double point::dist(const point& that) const
{
	return sqrt((x - that.x) * (x - that.x) + (y - that.y) * (y - that.y));
}

double point::dir(const point& that) const
{
	return atan2(that.y - y, that.x - x);
}