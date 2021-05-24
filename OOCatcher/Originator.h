#pragma once
#include "Memento.h"
class Originator
{
    public:
        void setState(std::vector<line_segment> body_pnts, std::vector<line_segment> left_f, std::vector<line_segment> right_f, double unit);
        void setMemento(Memento* const m);
        std::vector<line_segment> get_state();
        std::vector<line_segment> get_fingers_left();

        std::vector<line_segment> get_fingers_right();

        double get_unit_size();
        Memento* createMemento();

    private:
        std::vector<line_segment> body_state;
        std::vector<line_segment> left_fingers, right_fingers;
        double unit_size;
};

