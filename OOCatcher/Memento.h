#ifndef MEMENTO_HEADER
#define MEMENTO_HEADER
#include "line_segment.h"
#include <vector>

class Memento {
private:
	friend class Originator;
	friend class Drawer;
	Memento(std::vector<std::shared_ptr<line_segment>> body_pnts, line_segment* left_f, line_segment* right_f, double unit);
	std::vector<std::shared_ptr<line_segment>> get_state();
	line_segment* get_fingers_left();
	line_segment* get_fingers_right();
	double get_unit_size();
	std::vector<std::shared_ptr<line_segment>> body_state;
    line_segment left_fingers[5], right_fingers[5];
	double unit_size;
};
#endif