
#include "forearm.h"

void forearm::init_fingers(point st, int symmetry_unit)
{
    point end_pnt(st.get_x()+symmetry_unit/3, st.get_y());
    line_segment f(st, end_pnt);
    double deg = -10;
        for (int i = 0; i < 5; i++) {
            f.rotate(deg);
            fingers[i] = f;
            deg+=5;
        }
}

void forearm::move(double deg, double step)
{
    this->rotate(deg);
    adjust_fingers();
}

void forearm::adjust_fingers()
{
    for (int i = 0; i < 5; i++) {
        fingers[i].shift(this->end_x() - fingers[i].get_x(), this->end_y() - fingers[i].get_y());
    }
}

