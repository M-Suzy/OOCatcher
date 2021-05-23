#pragma once
#include "body_parts.h"
#include "line_segment.h"
class forearm :public body_parts, public line_segment
{
public:
   
    forearm(point fresh_start, point fresh_end, int symmetry_unit, body_parts::Side s) :line_segment(fresh_start, fresh_end)
    {
        side = s;
        init_fingers(fresh_end, symmetry_unit);
    }
private:
    friend class Human;
    line_segment fingers[5];
    void init_fingers(point st, int symmetry_unit);
    void move(double deg, double step) override;
    void adjust_fingers();
    
};

