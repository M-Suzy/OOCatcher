#pragma once
#include "body_parts.h"
#include "line_segment.h"
class forearm :public body_parts, public line_segment
{
public:
    forearm(point& fresh_start, point& fresh_end, body_parts::Side s):line_segment(fresh_start, fresh_end)
    {
        side = s;
    }
private:
    void move(double deg, double step) override;
    void checkConnectivity(line_segment* fingers);
    
};

