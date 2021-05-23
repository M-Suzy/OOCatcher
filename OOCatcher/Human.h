#pragma once
#include "torso.h"
#include "arm.h"
#include "forearm.h"
#include <vector>
#include "leg.h"
#include "foot.h"
#include "finger.h"
#include "Target_object.h"
#include "utils.h"


class Human
{
public:
	Human(point torso_start, Target_object &obj, int canvas_width, int canvas_height);
	void walk(int step);
	bool grab();
	double get_head_radius();
	std::vector<std::shared_ptr<line_segment>> get_body_points();

private:
	friend class Memento;
	double symmetry_unit;
	int bound_x;
	int bound_y;
	std::shared_ptr<torso> _torso;
	std::shared_ptr<arm> left_arm;
	std::shared_ptr<arm> right_arm;
	std::shared_ptr<forearm> left_forearm;
	std::shared_ptr<forearm> right_forearm;
	std::shared_ptr<leg> right_leg;
	std::shared_ptr<leg> left_leg;
	std::shared_ptr<foot> right_foot;
	std::shared_ptr<foot> left_foot;
	Target_object obj;
	std::vector<std::shared_ptr<line_segment>> body_points;
	bool is_capable();

};

