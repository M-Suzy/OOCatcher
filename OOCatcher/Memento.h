#ifndef MEMENTO_HEADER
#define MEMENTO_HEADER
#include "line_segment.h"
#include <vector>

class Memento {
private:
	friend class Originator;
	friend class Drawer;
	Memento(std::vector<line_segment> body_pnts, std::vector<line_segment> left_f, std::vector<line_segment> right_f, double unit);
	std::vector<line_segment> get_state();
	std::vector<line_segment> get_fingers_left();
	std::vector<line_segment> get_fingers_right();
	double get_unit_size();
	std::vector<line_segment> body_state;
	std::vector<line_segment> left_fingers, right_fingers;
	double unit_size;
};
#endif