#include<Torus.h>
#include<GL/glut.h>
#include<math.h>
#include<Coord.h>
#include<iostream>

// private

void Torus::draw_cross_section(Coord position, double angle, double offset_angle, int num_of_points){
}

// public

Torus::Torus(){
    radius = 40;
    smaller_radius = 10;
    rotation_speed = 0.1;
    num_of_cross_sections = 10;
}

void Torus::draw(){
    glBegin(GL_POINTS);
    for(double i = 0; i < 2 * M_PI; i += 2 * M_PI / num_of_cross_sections){
        glVertex3d(
                cos(i) * radius, 
                sin(i) * radius,
                0
                );
    }
    glEnd();
}
