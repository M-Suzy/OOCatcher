#include "Human.h"

Human::Human(point torso_start, int canvas_height, int canvas_width)
{
    symmetry_unit = (canvas_height - torso_start.get_y())/ 7;
    bound_x = canvas_width;
    bound_y = canvas_height;
    _torso = std::make_unique<torso>(torso_start, point(torso_start.get_x(), canvas_height));
    left_arm = std::make_unique<arm>(torso_start, point(torso_start.get_x(), canvas_height-5*symmetry_unit), body_parts::Side::LEFT);
    right_arm = std::make_unique<arm>(torso_start, point(torso_start.get_x(), canvas_height - 5 * symmetry_unit), body_parts::Side::RIGHT);
    left_forearm = std::make_unique<forearm>(point(left_arm->end_x(),left_arm->end_y()),
                                             point(torso_start.get_x(), canvas_height - 5 * symmetry_unit), body_parts::Side::LEFT);
    right_forearm = std::make_unique<forearm>(torso_start, point(torso_start.get_x(), canvas_height - 5 * symmetry_unit), body_parts::Side::RIGHT);

}

void Human::walk(double step)
{
}

void Human::grab()
{
}

double Human::get_head_radius()
{
    return 0.0;
}

std::vector<std::vector<point>> Human::get_body_points()
{
    return std::vector<std::vector<point>>();
}

void Human::update_body_points()
{
}
