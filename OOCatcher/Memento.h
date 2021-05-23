#pragma once
#include <vector>
#include "line_segment.h"
#include "Human.h"
class Memento {
public:
	Memento(Human dancer) {
		state = dancer.body_points;
	}
	std::vector<std::shared_ptr<line_segment>> getState() {
		return state;
	}
private:
	std::vector<std::shared_ptr<line_segment>> state;
};