#ifndef TORUS_H
#define TORUS_H

#include<Coord.h>
#include<vector>

class Torus{
private:
    static Torus* current_instance;
    double radius;
    double smaller_radius;
    double rotation_speed;
    double current_offset;
    int num_of_cross_sections;
    int num_of_points;
    std::vector<std::vector<Coord>> points;
    void draw_cross_section(Coord position, double angle, double offset_angle);
    void reset();
public:
    Torus();
    void draw();
    void update();
    static void kbin(unsigned char key, int x, int y);
    static void print_controls();
    static void display();
};

#endif
