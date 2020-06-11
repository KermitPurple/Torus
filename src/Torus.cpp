#include<Torus.h>
#include<GL/glut.h>
#include<math.h>
#include<Coord.h>
#include<iostream>

// private

void Torus::draw_cross_section(Coord position, double angle, double offset_angle, int num_of_points){
    glBegin(GL_LINES);
    glVertex3d(position.x, position.y, position.z);
    for(double i = 0; i < 2 * M_PI; i += 2 * M_PI / num_of_points){
        Coord point(
                cos(i + offset_angle) * smaller_radius + position.x, 
                0 + position.y,
                sin(i + offset_angle) * smaller_radius + position.z
                );
        glVertex3d(point.x, point.y, point.z);
        glVertex3d(point.x, point.y, point.z);
    }
    glEnd();
}

// public

Torus::Torus(){
    radius = 40;
    smaller_radius = 10;
    rotation_speed = 0.1;
    num_of_cross_sections = 10;
}

void Torus::draw(){
    for(double i = 0; i < 2 * M_PI; i += 2 * M_PI / num_of_cross_sections){
        glBegin(GL_POINTS);
        Coord point(
                cos(i) * radius, 
                sin(i) * radius,
                0
                );
        glVertex3d(point.x, point.y, point.z);
        glEnd();
        draw_cross_section(point, i, i, 4);
    }
}
