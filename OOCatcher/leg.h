#pragma once
#include "body_parts.h"
#include "line_segment.h"
class leg : public body_parts, public line_segment
{
public:
    leg(point&& fresh_start, point&& fresh_end, body_parts::Side s) :line_segment(fresh_start, fresh_end)
    {
        side = s;
    }
private:
    friend class Human;
    void move(double deg, double step) override;
};

