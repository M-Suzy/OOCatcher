#include "Originator.h"

void Originator::setState(std::vector<line_segment> body_pnts, std::vector<line_segment> left_f, 
                           std::vector<line_segment> right_f, double unit)
{
    body_state = body_pnts;
    left_fingers = left_f;
    right_fingers = right_f;
    unit_size = unit;
}

void Originator::setMemento(Memento* const m)
{
    body_state = m->get_state();
    left_fingers = m->get_fingers_left();
    right_fingers = m->get_fingers_right();
    unit_size = m->get_unit_size();
}

std::vector<line_segment> Originator::get_state()
{
    return body_state;
}

std::vector<line_segment> Originator::get_fingers_left()
{
    return left_fingers;
}

std::vector<line_segment> Originator::get_fingers_right() 
{
    return right_fingers;
}

double Originator::get_unit_size()
{
    return unit_size;
}

Memento* Originator::createMemento()
{
    return new Memento(body_state, left_fingers, right_fingers, unit_size);
}
