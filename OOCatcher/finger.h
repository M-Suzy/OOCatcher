#pragma once
#include "body_parts.h"
#include "line_segment.h"
class finger :
    public body_parts, public line_segment
{
public:
    finger(point&& fresh_start, point&& fresh_end, body_parts::Side s):line_segment(fresh_start, fresh_end)
    {
        side = s;
        // init_fingers(fresh_end, symmetry_unit);
    }
private:
    friend class Human;
    //void init_fingers(point st, int symmetry_unit);
    void move(double deg, double step) override;
    void checkConnectivity(line_segment* fingers);
};

