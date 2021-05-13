#pragma once
#include "torso.h"
#include "arm.h"
#include "forearm.h"
#include "point.h"
class Human
{
public:
	Human(point* torso_start);
	void walk(double step);
	void grab();
private:
	friend class Memento;
	const double head_radius;
	torso* _torso;
	arm* left_arm, *right_arm;
	forearm* left_forearm, *right_forearm;
};

