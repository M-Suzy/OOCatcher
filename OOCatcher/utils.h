#pragma once
#include <string>

typedef struct
{
    point torso_start;
    point object_top_left;
    int object_width, object_height;
    int canvas_width, canvas_height;
    std::string output_name;
}input_params;


inline bool hasOverlap(double r, point c_center, point top_left, double w, double h)
{

    double dist_x = abs(c_center.get_x() - top_left.get_x() - w / 2);
    double dist_y = abs(c_center.get_y() - top_left.get_y() - h / 2);


    if ((dist_x > (w / 2 + r)) || (dist_y > (h / 2 + r)))
    {
        return 0; 
    }
    if ((dist_x <= w/2) || (dist_y <= h / 2))
    {
        return 1;
    }
    double dx = dist_x - w / 2;
    double dy = dist_y - h / 2;
    return dx * dx + dy * dy <= (r * r);
}

inline int min_steps(double step_size, double rect_centerX, double circ_centerX, double r)
{
   
        return (rect_centerX - circ_centerX-r)/step_size+0.5;

}
