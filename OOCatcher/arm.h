#pragma once
#include "body_parts.h"
#include "line_segment.h"
#include "forearm.h"
class arm : public body_parts,  public line_segment
{
private:
	forearm f_arm;
	void move(double deg, double step);
	void checkConnectivity(line_segment* torso);
};

