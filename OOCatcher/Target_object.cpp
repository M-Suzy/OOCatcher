#include "Target_object.h"

Target_object::Target_object(point top_left, double width, double height)
{
    this->top_left = top_left;
    bottom_right = point(top_left.get_x() + width, top_left.get_y() + height);
}

double Target_object::get_topX()
{
    return top_left.get_x()
}

double Target_object::get_topY()
{
    return top_left.get_y();
}

double Target_object::get_width()
{
    return bottom_right.get_x()-top_left.get_x();
}

double Target_object::get_height()
{
    return bottom_right.get_y()-top_left.get_y();
}

double Target_object::get_area()
{
    return (bottom_right.get_x() - top_left.get_x())* (bottom_right.get_y() - top_left.get_y());
}
