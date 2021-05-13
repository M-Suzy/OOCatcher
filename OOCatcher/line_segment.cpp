#include "line_segment.h"

line_segment::line_segment(point& fresh_start, point& fresh_end)
{
	start_ptr = std::make_unique<point>(fresh_start);
	end_ptr = std::make_unique<point>(fresh_end);
}

line_segment::line_segment(double start_x, double start_y, double end_x, double end_y)
{
	start_ptr = std::make_unique<point>(start_x, start_y);
	end_ptr = std::make_unique<point>(end_x, end_y);
}

line_segment::line_segment(const line_segment& that)
{
	start_ptr = std::make_unique<point>(that.get_x(), that.get_y());
	end_ptr = std::make_unique<point>(that.end_x(), that.end_y());
}

void line_segment::shift(double dx, double dy)
{
	start_ptr->shift(dx, dy);
	end_ptr->shift(dx, dy);
}

void line_segment::rotate(double da)
{
	double a = dir() + da, r = length();
	end_ptr->shift(start_ptr->get_x() - end_ptr->get_x() + r * cos(a), start_ptr->get_y() - end_ptr->get_y() + r * sin(a));
}
