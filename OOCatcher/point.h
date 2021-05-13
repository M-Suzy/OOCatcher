#pragma once
#include <cmath>
class point
{
public:
	point();
	point(double fresh_x, double fresh_y);

	double get_x() const;
	double get_y() const;
	int int_x() const;
	int int_y() const;

	void shift(double dx, double dy);

	double dist(const point& that) const;
	double dir(const point& that) const;

protected:
	double x, y;

};

