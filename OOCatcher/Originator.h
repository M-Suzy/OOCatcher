#pragma once
#include "Memento.h"
class Originator
{
    public:
        void setState(std::vector<std::shared_ptr<line_segment>> body_pnts, line_segment& left_f, line_segment& right_f, double unit);
        void setMemento(Memento* const m);
        std::vector<std::shared_ptr<line_segment>> get_state();
        line_segment get_fingers_left();

        line_segment get_fingers_right();

        double get_unit_size();
        Memento* createMemento();

    private:
        std::vector<std::shared_ptr<line_segment>> body_state;
        line_segment* left_fingers, *right_fingers;
        double unit_size;
};

