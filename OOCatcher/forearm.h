#pragma once
#include "body_parts.h"
#include "line_segment.h"
class forearm :public body_parts, public line_segment
{
public:
   
    forearm(point& fresh_start, point& fresh_end, int symmetry_unit, body_parts::Side s) :line_segment(fresh_start, fresh_end)
    {
        side = s;
        init_fingers(fresh_end, symmetry_unit);
    }
    forearm(double start_x, double start_y, double end_x, double end_y, int symmetry_unit, body_parts::Side s) : line_segment(start_x, start_y, end_x, end_y) {
        side = s;
        init_fingers(point(end_x, end_y), symmetry_unit);
    }
private:
    friend class Human;
    line_segment fingers[5];
    void init_fingers(point st, int symmetry_unit);
    void move(double deg, double dx, double dy, bool rot) override;
    void adjust_fingers();
    
};

