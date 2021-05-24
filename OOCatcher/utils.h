#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <iostream>
typedef struct
{
    double torso_startX, torso_startY;
    double object_top_leftX, object_top_leftY;
    int object_width, object_height;
    int canvas_width, canvas_height;
}input_params;

//int check_params(char* argv[], input_params& i_params)
//{
//    //Messages
//    std::string error_message("");
//    i_params.canvas_width = atof(argv[0]);
//    if (i_params.canvas_width<0 && i_params.canvas_width>5000)
//        error_message += "Wrong canvas width";
//    i_params.canvas_height = atof(argv[1]);
//    if (i_params.canvas_height < 0 && i_params.canvas_height>5000)
//        error_message += "Wrong canvas height";
//    i_params.torso_startX = atof(argv[2]);
//    if (i_params.torso_startX > 0 && i_params.canvas_width/2)
//        error_message += "Man is outside canvas";
//    i_params.torso_startY = atof(argv[3]);
//    if (i_params.torso_startY > 0 && i_params.torso_startY<i_params.canvas_height/2)
//        error_message += "Man is outside canvas";
//    i_params.object_top_leftX = atof(argv[4]);
//    if (i_params.object_top_leftX < i_params.torso_startX+50 && i_params.object_top_leftX > i_params.torso_startX - 50)
//        error_message += "Bad alignment for object";
//    i_params.object_top_leftY = atof(argv[5]);
//    if (i_params.object_top_leftY < i_params.torso_startY - 50 && i_params.object_top_leftY > i_params.torso_startY + 50)
//        error_message += "Bad alignment for object";
//    i_params.object_width = atof(argv[6]);
//    if (i_params.object_width > i_params.canvas_width/10 )
//        error_message += "Object is too wide";
//    i_params.object_height = atof(argv[7]);
//    if (i_params.object_height > i_params.canvas_height/10 )
//        error_message += "Object is too long";
//   
//    if (error_message.length() > 0)
//    {
//        std::cout << error_message;
//        return -1;
//    }
//    return 0;
//}

inline bool hasOverlap(double r, double c_centerX, double c_centerY, double top_leftX, double top_leftY, double w, double h)
{

    double dist_x = abs(c_centerX - top_leftX - w / 2);
    double dist_y = abs(c_centerY - top_leftY - h / 2);


    if ((dist_x > (w / 2 + r)) || (dist_y > (h / 2 + r)))
    {
        return 0; 
    }
    if ((dist_x <= w/2) || (dist_y <= h / 2))
    {
        return 1;
    }
    double dx = dist_x - w / 2;
    double dy = dist_y - h / 2;
    return dx * dx + dy * dy <= (r * r);
}

inline int min_steps(double step_size, double rect_centerX, double circ_centerX, double r)
{
    std::cout << "Min steps to be able to grab the object::" << (int)((rect_centerX - circ_centerX - r) / step_size + 0.5) << std::endl;
    return (rect_centerX - circ_centerX-r)/step_size+0.5;
}

inline bool inRectanle(double x1, double y1, double x2, double y2, double x, double y)
{
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
        return 1;
    return 0;
}
#endif