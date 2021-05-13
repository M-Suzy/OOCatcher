#pragma once
#include "point.h"
class body_parts 
{
public:
	enum Side { LEFT, RIGHT };
	Side side;
protected:
	virtual void move(double deg, double step) = 0;
	virtual void checkConnectivity(line_segment* part);
	void adjustConnectedPart(body_parts* part);
	friend class Human;
};