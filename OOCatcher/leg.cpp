#include "leg.h"

void leg::move(double deg, double dx, double dy, bool rot)
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
