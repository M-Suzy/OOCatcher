#pragma once
#include <memory>
#
class body_parts
{
public:
	enum class Side { LEFT, RIGHT };
	Side get_Side() {
		return side;
	}
protected:
	friend class Human;
	Side side;
	virtual void move(double deg, double dx, double dy, bool rot)=0;
	//virtual void update(body_parts part);
	
};