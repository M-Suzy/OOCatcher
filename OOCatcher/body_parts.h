#pragma once
#include "point.h"
class body_parts 
{
public:
	enum Side { LEFT, RIGHT };
	Side side;
protected:
	virtual void move(double deg, double step) = 0;
	virtual void checkConnectivity(body_parts* part);
	virtual void adjustConnectedPart(body_parts* part);
	friend class Human;
};