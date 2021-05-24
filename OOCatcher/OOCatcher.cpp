// OOCatcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Drawer.h"
#include "Human.h"
#include <iostream>

using namespace cv;
using namespace std;

int check_params(char* argv[], input_params& i_params)
{
    //Messages
    std::string error_message("");
    i_params.canvas_width = atof(argv[0]);
    if (i_params.canvas_width<0 && i_params.canvas_width>5000)
        error_message += "Wrong canvas width";
    i_params.canvas_height = atof(argv[1]);
    if (i_params.canvas_height < 0 && i_params.canvas_height>5000)
        error_message += "Wrong canvas height";
    i_params.torso_startX = atof(argv[2]);
    if (i_params.torso_startX > 0 && i_params.canvas_width/2)
        error_message += "Man is outside canvas";
    i_params.torso_startY = atof(argv[3]);
    if (i_params.torso_startY > 0 && i_params.torso_startY<i_params.canvas_height/2)
        error_message += "Man is outside canvas";
    i_params.object_top_leftX = atof(argv[4]);
    if (i_params.object_top_leftX < i_params.torso_startX+50 && i_params.object_top_leftX > i_params.torso_startX - 50)
        error_message += "Bad alignment for object";
    i_params.object_top_leftY = atof(argv[5]);
    if (i_params.object_top_leftY < i_params.torso_startY - 50 && i_params.object_top_leftY > i_params.torso_startY + 50)
        error_message += "Bad alignment for object";
    i_params.object_width = atof(argv[6]);
    if (i_params.object_width > i_params.canvas_width/10 )
        error_message += "Object is too wide";
    i_params.object_height = atof(argv[7]);
    if (i_params.object_height > i_params.canvas_height/10 )
        error_message += "Object is too long";
   
    if (error_message.length() > 0)
    {
        std::cout << error_message;
        return -1;
    }
    return 0;
}
//////////////////////////////


int main(int argc, char* argv[])
{
	if (argc == 8) {
		input_params i_params;
		if (check_params(argv, i_params) > -1) {
			Target_object obj(point(i_params.object_top_leftX, i_params.object_top_leftY), i_params.object_width, i_params.object_height);
			Human h(i_params.torso_startX, i_params.torso_startY, obj, i_params.canvas_width, i_params.canvas_height);
			Drawer drawer(i_params.canvas_width, i_params.canvas_height, obj);
			h.grab();
			drawer.illustrate_scenario(h.get_history());
		}
	}
	else {
	Target_object obj(point(1200, 500), 200, 150);
	Human h(150, 1080 - 450, obj, 1920, 1080);
	Drawer drawer(1080, 1920, obj);
	h.grab();
	drawer.illustrate_scenario(h.get_history());
    }
	
}

