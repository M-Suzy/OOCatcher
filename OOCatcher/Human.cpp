#include "Human.h"
#include <iostream>

Human::~Human()
{
   delete history_adder;
   delete history_maker;
}

Human::Human(double torso_startX, double torso_startY, Target_object& obj, int canvas_width, int canvas_height)
{
    symmetry_unit = (canvas_height - torso_startY)/ 7;
    bound_x = canvas_width;
    bound_y = canvas_height;
    this->obj = obj;
    _torso = std::make_shared<torso>(torso_startX, torso_startY, torso_startX, canvas_height-4*symmetry_unit);
    left_arm = std::make_shared<arm>(_torso->get_x(), _torso->get_y(), _torso->get_x(), _torso->get_y()+2*symmetry_unit, body_parts::Side::LEFT);
    left_arm->move(15, 0, 0, 1);
    
    right_arm = std::make_shared<arm>(_torso->get_x(), _torso->get_y(), _torso->get_x(), _torso->get_y() + 2*symmetry_unit, body_parts::Side::RIGHT);
    right_arm->move(-15, 0, 0, 1);
    
    left_forearm = std::make_shared<forearm>(left_arm->end_x(), left_arm->end_y(),
                                             left_arm->end_x(), left_arm->end_y() + symmetry_unit, symmetry_unit, body_parts::Side::LEFT);
    left_forearm->move(10, 0, 0, 1);
    
    right_forearm = std::make_shared<forearm>(right_arm->end_x(), right_arm->end_y(),
                                             right_arm->end_x(), right_arm->end_y() + symmetry_unit, symmetry_unit, body_parts::Side::RIGHT);
    right_forearm->move(-10,0, 0, 1);
    
    left_leg = std::make_shared<leg>(_torso->end_x(),_torso->end_y(), _torso->end_x(), canvas_height, body_parts::Side::LEFT);
   
    right_leg = std::make_shared<leg>(_torso->end_x(), _torso->end_y(), _torso->end_x(), canvas_height, body_parts::Side::RIGHT);
    left_foot = std::make_shared<foot>(left_leg->end_x(), left_leg->end_y(), left_leg->end_x() - symmetry_unit / 2, canvas_height, body_parts::Side::LEFT);
    right_foot = std::make_shared<foot>(right_leg->end_x(), right_leg->end_y(), 
                                        right_leg->end_x()+symmetry_unit/2, canvas_height, body_parts::Side::RIGHT);
    
    body_points.push_back(_torso);
    body_points.push_back(left_arm);
    body_points.push_back(right_arm);
    body_points.push_back(left_forearm);
    body_points.push_back(right_forearm);
    body_points.push_back(left_leg);
    body_points.push_back(right_leg);
    body_points.push_back(right_foot);
    body_points.push_back(left_foot); 
    history_maker = new Originator();
    history_adder = new CareTaker(history_maker);
    history_maker->setState(get_body_points(), get_fingers_left(), get_fingers_right(), symmetry_unit);
    history_adder->save();
}

#define STEP_SIZE 2*symmetry_unit
void Human::walk(int step)
{
    bool dir = 1;
    if (step < 0) { 
        bool dir = -1;
        step *= -1;
    }
    while (step > 0) {
        right_foot->move(0, STEP_SIZE, 0, 1);
        right_leg->move(30, STEP_SIZE, 0, 0);
        _torso->move(0, 0, right_leg->get_y() - _torso->end_y(), 0);
        left_leg->move(-30, -STEP_SIZE, 0, 0);
        left_foot->move(0, -STEP_SIZE, 0, 1);
        left_arm->move(0, 0, _torso->get_y() - left_arm->get_y(), 1);
        left_forearm->move(0, 0, left_arm->end_y() - left_forearm->get_y(), 1);
        right_arm->move(0, 0, _torso->get_y() - right_arm->get_y(), 1);
        right_forearm->move(0, 0, right_arm->end_y() - right_forearm->get_y(), 1);
        history_maker->setState(get_body_points(), get_fingers_left(), get_fingers_right(), symmetry_unit);
        history_adder->save();
        if (dir < 0) {
            left_leg->move(-30, 0, 0, 0);
            _torso->move(0, left_leg->get_x() - _torso->get_x(), left_leg->get_y() - _torso->end_y(), 0);
            right_leg->move(30, _torso->get_x() - right_leg->end_x(), 0, 0);
            left_arm->move(0, 0, _torso->get_y() - left_arm->get_y(), 1);
            left_forearm->move(0, 0, left_arm->end_y() - left_forearm->get_y(), 1);
            right_arm->move(0, 0, _torso->get_y() - right_arm->get_y(), 1);
            right_forearm->move(0, 0, right_arm->end_y() - right_forearm->get_y(), 1);
        }
        else {
            right_leg->move(30, 0, 0, 0);
            _torso->move(0, right_leg->get_x() - _torso->get_x(), right_leg->get_y() - _torso->end_y(), 0);
            left_leg->move(-30, _torso->get_x() - left_leg->end_x(), 0, 0);
            left_foot->move(0, left_leg->end_x() - left_foot->get_x(), 0, 1);
            left_arm->move(0, _torso->get_x() - left_arm->get_x(), _torso->get_y() - left_arm->get_y(), 1);
            left_forearm->move(0, left_arm->end_x() - left_forearm->get_x(), left_arm->end_y() - left_forearm->get_y(), 1);
            right_arm->move(0, _torso->get_x() - right_arm->get_x(), _torso->get_y() - right_arm->get_y(), 1);
            right_forearm->move(0, right_arm->end_x() - right_forearm->get_x(), right_arm->end_y() - right_forearm->get_y(), 1);
        }
        step--;
        history_maker->setState(get_body_points(), get_fingers_left(), get_fingers_right(), symmetry_unit);
        history_adder->save();
    }
}

bool Human::grab()
{
    if (!is_capable()) {
        std::cout << "Not tall enough to reach the object!" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if(!hasOverlap(6.33 * symmetry_unit, _torso->end_x(), _torso->end_y(), obj.get_topX(), obj.get_topY(), obj.get_width(), obj.get_height()))
    {
        walk(min_steps(STEP_SIZE, obj.get_centerX(), _torso->end_x(), 6.33 * symmetry_unit));
    }
    
    //double angle = _torso->get_start()->dir(obj.get_center());
   // if (obj.get_centerX() < _torso->get_x()) {
   //     left_forearm->move(angle, 0);
   // }
   // else {
   //     right_forearm->move(angle, 0);
   // }
    
    
}

double Human::get_head_radius()
{
    return symmetry_unit;
}

std::vector<line_segment> Human::get_body_points()
{
    std::vector<line_segment> cp(body_points.size());
    for (int i = 0; i < cp.size(); i++) {
        cp[i] = *body_points[i];
    }
    return cp;
}

std::vector<line_segment> Human::get_fingers_left()
{
    return left_forearm->fingers;
}

std::vector<line_segment> Human::get_fingers_right()
{
    return right_forearm->fingers;
}

std::vector<Memento*> Human::get_history()
{
    return history_adder->get_history();
}

bool Human::is_capable()
{
    return (bound_y-10*symmetry_unit < obj.get_topY()+obj.get_height());
}

