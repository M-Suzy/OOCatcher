#pragma once
#include "point.h"
#include <vector>
class Target_object
{
public:
	Target_object() {};
	Target_object(point top_left, double width, double height);
	double get_topX();
	double get_topY();
	double get_bottomX();
	double get_bottomY();
	double get_width();
	double get_height();
	double get_area();
	double get_centerX();
	double get_centerY();
	point get_center();
private:
	point top_left;
	point bottom_right;
};

