#ifndef TORUS_H
#define TORUS_H

#include<Coord.h>
#include<vector>

class Torus{
private:
    double radius;
    double smaller_radius;
    double rotation_speed;
    double current_offset;
    int num_of_cross_sections;
    int num_of_points;
    void draw_cross_section(Coord position, double angle, double offset_angle);
    std::vector<std::vector<Coord>> points;
public:
    Torus();
    void draw();
    void update();
    void kbin(unsigned char key, int x, int y);
};

#endif
