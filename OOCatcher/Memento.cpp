#include "Memento.h"

Memento::Memento(std::vector<std::shared_ptr<line_segment>> body_pnts, line_segment* left_f, line_segment* right_f, double unit)
{
	body_state = body_pnts;
	memcpy(left_fingers, left_f, sizeof(left_fingers));
	memcpy(right_fingers, right_f, sizeof(right_fingers));
	unit_size = unit;
}

std::vector<std::shared_ptr<line_segment>> Memento::get_state()
{
	return body_state;
}

line_segment* Memento::get_fingers_left()
{
	return left_fingers;
}

line_segment* Memento::get_fingers_right()
{
	return right_fingers;
}

double Memento::get_unit_size()
{
	return unit_size;
}
