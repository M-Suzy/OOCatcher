#include "Originator.h"

void Originator::setState(std::vector<std::shared_ptr<line_segment>> body_pnts, line_segment& left_f, line_segment& right_f, double unit)
{
    body_state = body_pnts;
    left_fingers = new line_segment(left_f);
    right_fingers = new line_segment(right_f);
    unit_size = unit;
}

void Originator::setMemento(Memento* const m)
{
    body_state = m->get_state();
    left_fingers = m->get_fingers_left();
    right_fingers = m->get_fingers_right();
    unit_size = m->get_unit_size();
}

std::vector<std::shared_ptr<line_segment>> Originator::get_state()
{
    return body_state;
}

line_segment Originator::get_fingers_left() 
{
    return *left_fingers;
}

line_segment Originator::get_fingers_right() 
{
    return *right_fingers;
}

double Originator::get_unit_size()
{
    return unit_size;
}

Memento* Originator::createMemento()
{
    return new Memento(body_state, left_fingers, right_fingers, unit_size);
}
