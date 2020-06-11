#include<Torus.h>
#include<GL/glut.h>
#include<math.h>
#include<Coord.h>
#include<iostream>

// private

void Torus::draw_cross_section(Coord position, double angle, double offset_angle, int num_of_points){
    angle = -angle;
    std::vector<Coord> new_vec;
    glBegin(GL_LINE_STRIP);
    for(double i = 0; i <= 2 * M_PI; i += 2 * M_PI / num_of_points){
        Coord point(
                cos(i + offset_angle) * smaller_radius,
                0,
                sin(i + offset_angle) * smaller_radius + position.z
                );
        double newx = point.x * cos(angle) + point.y * sin(angle) + position.x;
        double newy = point.x * -sin(angle) + point.y * cos(angle) + position.y;
        point.x = newx;
        point.y = newy;
        glVertex3d(point.x, point.y, point.z);
        new_vec.push_back(point);
    }
    glEnd();
    points.push_back(new_vec);
}

// public

Torus::Torus(){
    radius = 40;
    smaller_radius = 10;
    rotation_speed = 0.1;
    num_of_cross_sections = 30;
}

void Torus::draw(){
    for(double i = 0; i < 2 * M_PI; i += 2 * M_PI / num_of_cross_sections){
        Coord point(
                cos(i) * radius, 
                sin(i) * radius,
                0
                );
        draw_cross_section(point, i, i, 3);
    }
    for(int i = 0; i < points[0].size(); i++){
        glBegin(GL_LINE_STRIP);
        for(auto v: points){
            glVertex3d(v[i].x, v[i].y, v[i].z);
        }
        std::vector<Coord> v = points[0];
        glVertex3d(v[i].x, v[i].y, v[i].z);
        glEnd();
    }
    points.clear();
}
