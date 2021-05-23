#include "arm.h"

body_parts::Side arm::get_side()
{
	return side;
}

void arm::move(double deg, double step)
{
	this->rotate(deg);
}


