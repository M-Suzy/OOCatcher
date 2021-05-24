#include "foot.h"

bool foot::on_ground(int canvas_height)
{
    return (this->end_y() == canvas_height);
}
void foot::move(double deg, double dx, double dy, bool rot)
{
	if (dx || dy) {
		this->shift(dx, dy);
	}
	if (deg)
	{
		if (rot)
		{
			this->rotate_start(deg);
		}
		else {
			this->rotate_end(deg);
		}
	}
}
