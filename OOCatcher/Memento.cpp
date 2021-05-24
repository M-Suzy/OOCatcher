#include "Memento.h"
#include <iostream>

Memento::Memento(std::vector<line_segment> body_pnts, std::vector<line_segment> left_f, std::vector<line_segment> right_f, double unit)
{
	body_state = body_pnts;
	left_fingers = left_f;
	right_fingers = right_f;
	//std::cout << body_state[]->get_x() << std::endl;
	unit_size = unit;
}

std::vector<line_segment> Memento::get_state()
{	
	return body_state;
}

std::vector<line_segment> Memento::get_fingers_left()
{
	//std::cout<<left_fingers[4].get_x()<<std::endl;
	return left_fingers;
}

std::vector<line_segment> Memento::get_fingers_right()
{
	return right_fingers;
}

double Memento::get_unit_size()
{
	return unit_size;
}
