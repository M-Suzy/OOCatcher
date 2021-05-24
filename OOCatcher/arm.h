#pragma once
#include "body_parts.h"
#include "line_segment.h"
#include "forearm.h"
class arm : public body_parts, public line_segment
{
public:
	arm(point& start, point& end, body_parts::Side s) :line_segment(start, end) { side = s; }
	arm(double start_x, double start_y, double end_x, double end_y, body_parts::Side s) :line_segment(start_x, start_y, end_x, end_y) { side = s; }
	body_parts::Side get_side();
	//void checkConnectivity(line_segment torso);
private:
	friend class Human;
	body_parts::Side side;
	void move(double deg, double dx, double dy, bool rot) override;
	//void notify_connectedPart(std::shared_ptr<body_parts> part) override;
	
};

