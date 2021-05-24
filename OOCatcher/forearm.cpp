
#include "forearm.h"

void forearm::init_fingers(point st, int symmetry_unit)
{
    fingers.resize(5);
    point end_pnt(st.get_x()+symmetry_unit/3, st.get_y());
    line_segment f(st, end_pnt);
    double deg = 90;
        for (int i = 0; i < 5; i++) {
            f.rotate_start(deg);
            fingers[i] = f;
            deg-=16;
        }
}

void forearm::move(double deg, double dx, double dy, bool rot)
{
    if (dx || dy) {
        this->shift(dx, dy);
    }
    if (deg)
    {
        if (rot)
        {
            this->rotate_start(deg);
        }
        else {
            this->rotate_end(deg);
        }
    }
        adjust_fingers();
}

void forearm::adjust_fingers()
{
    for (int i = 0; i < 5; i++) {
        fingers[i].shift(this->end_x() - fingers[i].get_x(), this->end_y() - fingers[i].get_y());
    }
}

