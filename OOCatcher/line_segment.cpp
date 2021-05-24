#include "line_segment.h"

line_segment::line_segment(double start_x, double start_y, double end_x, double end_y)
{
	start_ptr = std::make_shared<point>(start_x, start_y);
	end_ptr = std::make_shared<point>(end_x, end_y);
}

line_segment::line_segment(point& fresh_start, point& fresh_end)
{
	start_ptr = std::make_shared<point>(fresh_start);
	end_ptr = std::make_shared<point>(fresh_end);
}

line_segment::line_segment(const line_segment& that)
{
	start_ptr = std::make_shared<point>(that.get_x(), that.get_y());
	end_ptr = std::make_shared<point>(that.end_x(), that.end_y());
}


double line_segment::get_x() const
{
	return start_ptr->get_x();
}

double line_segment::get_y() const
{
	return start_ptr->get_y();
}

int line_segment::int_x() const
{
	return start_ptr->int_x();
}

int line_segment::int_y() const
{
	return start_ptr->int_y();
}

double line_segment::end_x() const
{
	return end_ptr->get_x();
}

double line_segment::end_y() const
{
	return end_ptr->get_y();
}

int line_segment::int_end_x() const
{
	return end_ptr->int_x();
}

int line_segment::int_end_y() const
{
	return end_ptr->int_y();
}

double line_segment::length() const
{
	return start_ptr->dist(*end_ptr);
}

double line_segment::dir() const
{
	return start_ptr->dir(*end_ptr);
}

void line_segment::shift(double dx, double dy)
{
	start_ptr->shift(dx, dy);
	end_ptr->shift(dx, dy);
}

void line_segment::rotate_start(double da)
{
	da = da * 3.14 / 180;
	double a = dir() + da, r = length();
	end_ptr->shift(start_ptr->get_x() - end_ptr->get_x() + r * cos(a), start_ptr->get_y() - end_ptr->get_y() + r * sin(a));
}
void line_segment::rotate_end(double da) {
	da = da * 3.14 / 180;
	double a = dir() + da, r = length();
	start_ptr->shift(end_ptr->get_x() - start_ptr->get_x() + r * cos(a), end_ptr->get_y() - start_ptr->get_y() - r * sin(a));
}