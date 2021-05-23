#pragma once
#include "body_parts.h"
#include "line_segment.h"
#include "forearm.h"
class arm : public body_parts, public line_segment
{
public:
	arm(point start, point end, body_parts::Side s) :line_segment(start, end) { side = s; }
	body_parts::Side get_side();
	//void checkConnectivity(line_segment torso);
private:
	friend class Human;
	body_parts::Side side;
	void move(double deg, double step) override;
	//void notify_connectedPart(std::shared_ptr<body_parts> part) override;
	
};

