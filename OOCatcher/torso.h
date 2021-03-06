#pragma once
#include "body_parts.h"
#include "point.h"
#include "line_segment.h"
class torso : public body_parts, public line_segment
{
public:
    torso(point& fresh_start, point fresh_end):line_segment(fresh_start, fresh_end) {}
    torso(double start_x, double start_y, double end_x, double end_y) :line_segment(start_x, start_y, end_x, end_y) {}
private:
    friend class Human;
    void move(double deg, double dx, double dy, bool rot) override;

   
};

