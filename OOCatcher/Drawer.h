#pragma once
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "Memento.h"
#include "Target_object.h"
#include <vector>

using namespace cv;

class Drawer
{
public:
	Drawer(int canvas_height, int canvas_width, Target_object &obj);
	void draw(Human human);
	void save(std::string name);

private:
	Mat canvas;
	Rect obj;
};

