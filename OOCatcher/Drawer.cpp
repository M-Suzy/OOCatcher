#include "Drawer.h"


Drawer::Drawer(int canvas_height, int canvas_width, Target_object &obj)
{
	canvas = Mat(canvas_height, canvas_width, CV_8UC3, Scalar(250, 250, 250));
	rectangle(canvas, Point(obj.get_topX(), obj.get_topY()), Point(obj.get_topX() + obj.get_width(), obj.get_topY() + obj.get_height()),Scalar(0, 0, 250), 3);
}

void Drawer::illustrate_scenario(std::vector<Memento*> history)
{
    for (int i = 0; i < history.size(); i++) {
        draw(*history[i], i);
    }
}

void Drawer::draw(Memento human, int num)
{ 
    std::vector<line_segment> body = human.get_state();
    Mat canvas_cp;
    canvas.copyTo(canvas_cp);
    for (int i = 0; i < body.size(); i++) {
        line(canvas_cp,
            Point(body[i].int_x(), body[i].int_y()),
            Point(body[i].end_x(), body[i].end_y()),
            Scalar(0, 0, 0),
            2.5,
            LINE_8);
    } 
    std::vector<line_segment> left_f = human.get_fingers_left();
    std::vector<line_segment> right_f = human.get_fingers_right();

    for (int i = 0; i < 5; i++) {
        line(canvas_cp,
            Point(left_f[i].int_x(), left_f[i].int_y()),
            Point(left_f[i].end_x(), left_f[i].end_y()),
            Scalar(0, 0, 0),
            1,
            LINE_8);
        line(canvas_cp,
            Point(right_f[i].int_x(), right_f[i].int_y()),
            Point(right_f[i].end_x(), right_f[i].end_y()),
            Scalar(0, 0, 0),
            1,
            LINE_8);
    }
    circle(canvas_cp, Point(body[0].int_x(), body[0].int_y() - human.get_unit_size()/2), human.get_unit_size()/2, Scalar(0, 0, 0), 4);
    save(std::to_string(num).append(".jpg"), canvas_cp);
}

void Drawer::save(std::string name, Mat img)
{
    imwrite(name, img);
}
