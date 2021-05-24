#include "Drawer.h"

Drawer::Drawer(int canvas_height, int canvas_width, Target_object &obj)
{
	canvas = Mat(canvas_height, canvas_width, CV_8UC3, Scalar(250, 250, 250));
	rectangle(canvas, Point(obj.get_topX(), obj.get_topY()), Point(obj.get_topX() + obj.get_width(), obj.get_topY() + obj.get_height()),Scalar(0, 0, 250), 3);
}

void Drawer::draw(Human human)
{ 
    std::vector<std::shared_ptr<line_segment>> body = human.get_body_points();
    for (int i = 0; i < body.size(); i++) {

        line(canvas,
            Point(body[i]->int_x(), body[i]->int_y()),
            Point(body[i]->end_x(), body[i]->end_y()),
            Scalar(0, 0, 0),
            3,
            LINE_8);
    } 
    /*for (int i = 0; i < 5; i++) {
        line(canvas,
            Point(human->int_x(), body[i]->int_y()),
            Point(body[i]->end_x(), body[i]->end_y()),
            Scalar(0, 0, 0),
            3,
            LINE_8);
    }*/
    circle(canvas, Point(body[0]->int_x(), body[0]->int_y() - human.get_head_radius()/2), human.get_head_radius()/2, Scalar(0, 0, 0), 4);

}

void Drawer::save(std::string name)
{
    imwrite(name, canvas);
}
