#pragma once
#include "torso.h"
#include "arm.h"
#include "forearm.h"
#include "point.h"
#include <vector>
class Human
{
public:
	Human(point torso_start, int canvas_height, int canvas_width);
	void walk(double step);
	void grab();
	double get_head_radius();
	std::vector<std::vector<point>> get_body_points();

private:
	friend class Memento;
	double symmetry_unit;
	int bound_x;
	int bound_y;
	std::unique_ptr<torso> _torso;
	std::unique_ptr<arm> left_arm;
	std::unique_ptr<arm> right_arm;
	std::unique_ptr<forearm> left_forearm;
	std::unique_ptr<forearm> right_forearm;
	std::vector<std::vector<point>> body_points;
	void update_body_points();
};

