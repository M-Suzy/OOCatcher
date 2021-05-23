#pragma once
#include "body_parts.h"
#include "line_segment.h"
class foot :
    public body_parts, public line_segment
{
public:
 foot(point&& fresh_start, point&& fresh_end, body_parts::Side s) :line_segment(fresh_start, fresh_end)
    {
        side = s;
    }
private:
    friend class Human;
    body_parts::Side side;
    bool on_ground(int canvas_height);
    void move(double deg, double step) override;
};

