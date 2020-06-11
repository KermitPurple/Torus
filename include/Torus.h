#ifndef TORUS_H
#define TORUS_H

#include<Coord.h>
#include<vector>

class Torus{
private:
    double radius;
    double smaller_radius;
    double rotation_speed;
    double num_of_cross_sections;
    double current_offset;
    double num_of_points;
    void draw_cross_section(Coord position, double angle, double offset_angle);
    std::vector<std::vector<Coord>> points;
public:
    Torus();
    void draw();
    void update();
};

#endif
