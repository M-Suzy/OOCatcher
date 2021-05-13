#pragma once
#include "body_parts.h"
#include "line_segment.h"
class forearm :
    public body_parts, public line_segment
{
private:
    forearm(point& fresh_start, point& fresh_end, body_parts::Side s):line_segment(fresh_start, fresh_end)
    {
        side = s;
    }
    forearm(double start_x, double start_y, double end_x, double end_y, body_parts::Side s):line_segment(start_x, start_y, end_x, end_y)
    {
        side = s;
    }

    void move(double deg, double step);
    void checkConnectivity(line_segment* fingers);
    
};

