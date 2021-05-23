#include "foot.h"

bool foot::on_ground(int canvas_height)
{
    return (this->end_y() == canvas_height);
}

void foot::move(double deg, double step)
{
}
