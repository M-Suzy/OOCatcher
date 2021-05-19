#pragma once
#include "point.h"
class Target_object
{
public:
	Target_object(point top_left, double width, double height);
	double get_topX();
	double get_topY();
	double get_width();
	double get_height();
	double get_area();
private:
	point top_left;
	point bottom_right;
};

