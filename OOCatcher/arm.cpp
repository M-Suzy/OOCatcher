#include "arm.h"

body_parts::Side arm::get_side()
{
	return side;
}

void arm::move(double deg, double dx, double dy, bool rot)
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




