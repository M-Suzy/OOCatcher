
#include "forearm.h"

void forearm::init_fingers(point st, int symmetry_unit)
{
    fingers.resize(5);
    point end_pnt(st.get_x(), st.get_y() + symmetry_unit / 3);
    double deg = 30;
    if (side == Side::LEFT) {
        deg *= -1;
    }
     for (int i = 0; i < 5; i++) {
         fingers[i] = line_segment(st, end_pnt);;
         fingers[i].rotate_start(deg);
            if (side == Side::LEFT) {
                deg += 30;
            }
            else {
                deg -= 30;
            }
            
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

