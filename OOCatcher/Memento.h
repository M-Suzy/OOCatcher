#pragma once
#include <vector>
#include "line_segment.h"
#include "Human.h"
class Memento {
private:
	friend class Human;
	Memento(Human dancer) {
		bodyLines.push_back(*dancer._torso);
		bodyLines.push_back(*dancer.left_arm);
		bodyLines.push_back(*dancer.right_arm);
		bodyLines.push_back(*dancer.right_forearm);
		bodyLines.push_back(*dancer.left_forearm);
	}
private:
	std::vector<line_segment> bodyLines;
};