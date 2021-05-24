#ifndef HUMAN_HEADER
#define HUMAN_HEADER
#include "torso.h"
#include "arm.h"
#include "forearm.h"
#include "leg.h"
#include "foot.h"

#include "Target_object.h"
#include "utils.h"
#include "CareTaker.h"

class Human
{
public:
	Human(){}
	~Human();
	Human(double torso_startX, double torso_startY, Target_object &obj, int canvas_width, int canvas_height);
	void walk(int step);
	bool grab();
	double get_head_radius();
	bool hasTouched(std::vector<line_segment>);
	std::vector<line_segment> get_body_points();
	std::vector<line_segment> get_fingers_left();
	std::vector<line_segment> get_fingers_right();
	std::vector<Memento*> get_history();

private:
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
	CareTaker* history_adder;
	Originator* history_maker;
	std::vector<std::shared_ptr<line_segment>> body_points;
	bool is_capable();
	

};
#endif
