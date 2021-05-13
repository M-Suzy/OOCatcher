#pragma once
#include "point.h"
class Target_object
{
public:
	Target_object(point top_left);
	double get_topX();
	double get_topY();
	double get_width();
	double get_height();
	double get_area();
private:
	const point top_left;
	const point bottom_right;
};

