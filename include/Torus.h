#ifndef TORUS_H
#define TORUS_H

#include<Coord.h>

class Torus{
private:
    double radius;
    double smaller_radius;
    double rotation_speed;
    double num_of_cross_sections;
    void draw_cross_section(Coord position, double angle, double offset_angle, int num_of_points);
public:
    Torus();
    void draw();
};

#endif
