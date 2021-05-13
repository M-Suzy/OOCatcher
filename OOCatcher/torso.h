#pragma once
#include "body_parts.h"
#include "line_segment.h"
class torso : public body_parts, public line_segment
{
public:
    torso(point& fresh_start, point& fresh_end) :line_segment(fresh_start, fresh_end) {}
    torso(double start_x, double start_y, double end_x, double end_y, body_parts::Side s) :line_segment(start_x, start_y, end_x, end_y) {}
    void move(double deg, double step);
   
};

