#pragma once
#include <memory>
#include "point.h"

class line_segment
{
public:
	line_segment(){}
	line_segment(double start_x, double start_y, double end_x, double end_y);
	line_segment(point& fresh_start, point& fresh_end);
	line_segment(const line_segment& that);
	double get_x() const;
	double get_y() const;
	int int_x() const;
	int int_y() const;
	double end_x() const;
	double end_y() const;
	int int_end_x() const;
	int int_end_y() const;

	double length() const;
	double dir() const;

	void shift(double dx, double dy);
	void rotate_start(double da);
	void rotate_end(double da);
	//void rotate(double da);

private:
	std::shared_ptr<point> start_ptr, end_ptr;
};