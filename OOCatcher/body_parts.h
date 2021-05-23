#pragma once
#include <memory>

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
	virtual void move(double deg, double step) = 0;
	//virtual void update(std::shared_ptr<body_parts> part);
	
};