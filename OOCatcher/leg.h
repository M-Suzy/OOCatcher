#pragma once
#include "body_parts.h"
#include "line_segment.h"
class leg : public body_parts, public line_segment
{
public:
    leg(point& fresh_start, point& fresh_end, body_parts::Side s) :line_segment(fresh_start, fresh_end)
    {
        side = s;
    }
    leg(double start_x, double start_y, double end_x, double end_y, body_parts::Side s) :line_segment(start_x, start_y, end_x, end_y) { side = s; }
private:
    friend class Human;
    void move(double deg, double dx, double dy, bool rot) override;
};

