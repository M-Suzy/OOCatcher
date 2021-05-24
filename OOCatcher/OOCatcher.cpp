// OOCatcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Drawer.h"
#include "Human.h"
#include "Target_object.h"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Target_object obj(point(1200, 500), 200, 150);
	Human h(150, 1080 - 450, obj, 1920, 1080);
	Drawer drawer(1080, 1920, obj);
	drawer.draw(h);
	drawer.save("initial.png");
}

