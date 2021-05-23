#include "Human.h"
#include <iostream>

Human::Human(point torso_start, Target_object& obj, int canvas_width, int canvas_height)
{
    symmetry_unit = (canvas_height - torso_start.get_y())/ 7;
    bound_x = canvas_width;
    bound_y = canvas_height;
    this->obj = obj;
    _torso = std::make_shared<torso>(torso_start, point(torso_start.get_x(), canvas_height-4*symmetry_unit));
    body_points.push_back(_torso);
    left_arm = std::make_shared<arm>(torso_start, point(torso_start.get_x(), torso_start.get_y()+2*symmetry_unit), body_parts::Side::LEFT);
    left_arm->rotate(20);
    body_points.push_back(left_arm);
    right_arm = std::make_shared<arm>(torso_start, point(torso_start.get_x(), torso_start.get_y() + 2*symmetry_unit), body_parts::Side::RIGHT);
    right_arm->rotate(-20);
    body_points.push_back(right_arm);
    left_forearm = std::make_shared<forearm>(point(left_arm->end_x(),left_arm->end_y()),
                                             point(left_arm->end_x(), left_arm->end_y() + symmetry_unit), symmetry_unit, body_parts::Side::LEFT);
    left_forearm->rotate(17);
    body_points.push_back(left_forearm);
    right_forearm = std::make_shared<forearm>(point(right_arm->end_x(), right_arm->end_y()),
                                          point(right_arm->end_x(), right_arm->end_y() + symmetry_unit), symmetry_unit, body_parts::Side::RIGHT);
    right_forearm->rotate(-17);
    body_points.push_back(right_forearm);
    left_leg = std::make_shared<leg>(point(_torso->end_x(), _torso->end_y()), point(_torso->end_x(), canvas_height), body_parts::Side::LEFT);
    body_points.push_back(left_leg);
    right_leg = std::make_shared<leg>(point(_torso->end_x(), _torso->end_y()), point(_torso->end_x(), canvas_height), body_parts::Side::RIGHT);
    body_points.push_back(right_leg);
    right_foot = std::make_shared<foot>(point(_torso->end_x(), canvas_height), point(_torso->end_x()+symmetry_unit/2, canvas_height), body_parts::Side::RIGHT);
    body_points.push_back(right_foot);
    left_foot = std::make_shared<foot>(point(_torso->end_x(), canvas_height), point(_torso->end_x() - symmetry_unit / 2, canvas_height), body_parts::Side::LEFT);
    body_points.push_back(left_foot); 
    
}

void Human::walk(int step)
{
    //while(){}
}

bool Human::grab()
{
    if (!is_capable()) {
        std::cout << "Not tall enough to reach the object!" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if (!hasOverlap(6.33 * symmetry_unit, point(_torso->end_x(), _torso->end_y()), point(obj.get_topX(), obj.get_topY()), obj.get_width(), obj.get_height()))
    {
        walk(min_steps(2*symmetry_unit, obj.get_centerX(), _torso->end_x(), 6.33 * symmetry_unit));
    }
    double angle = _torso->get_start()->dir(obj.get_center());
    if (obj.get_centerX() < _torso->get_x()) {
        left_forearm->move(angle, 0);
    }
    else {
        right_forearm->move(angle, 0);
    }
    
    
}

double Human::get_head_radius()
{
    return symmetry_unit;
}

std::vector<std::shared_ptr<line_segment>> Human::get_body_points()
{
    return body_points;
}

bool Human::is_capable()
{
    return (bound_y-10*symmetry_unit < obj.get_topY()+obj.get_height());
}

