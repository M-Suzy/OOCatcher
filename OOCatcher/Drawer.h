#pragma once
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "Target_object.h"
#include "Memento.h"

using namespace cv;

class Drawer
{
public:
	Drawer(int canvas_height, int canvas_width, Target_object &obj);
	void illustrate_scenario(std::vector<Memento*> history);
	void save(std::string name);

private:
	Mat canvas;
	Rect obj;
	void draw(Memento human, int num);
};

