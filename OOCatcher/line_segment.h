#pragma once
#include "point.h"
#include <memory>
class line_segment:public point
{
public:
	line_segment(point& fresh_start, point& fresh_end);
	line_segment(double start_x, double start_y, double end_x, double end_y);
	line_segment(const line_segment& that);
protected:
	virtual void shift(double dx, double dy);
	virtual void rotate(double da);
	std::unique_ptr<point> start_ptr, end_ptr;
	double get_x() {
		return start_ptr->get_x();
	}
	double get_y() {
		return start_ptr->get_y();
	}
	int int_x() {
		return start_ptr->int_x();
	}
	int int_y() {
		return start_ptr->int_y();
	}
	double end_x() {
		return end_ptr->get_x();
	}
	double end_y(){
		return end_ptr->get_y();
	}
	int int_end_x() {
		return end_ptr->int_x();
	}
	int int_end_y() {
		return end_ptr->int_y();
	}

	double length() {
		return start_ptr->dist(*end_ptr);
	}
	double dir() {
		return start_ptr->dir(*end_ptr);
	}
	

};

