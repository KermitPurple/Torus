#include<Torus.h>
#include<GL/glut.h>
#include<math.h>
#include<Coord.h>
#include<iostream>

// private

void Torus::draw_cross_section(Coord position, double angle, double offset_angle){
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
    radius = 75;
    smaller_radius = 25;
    rotation_speed = 0.003;
    num_of_cross_sections = 30;
    current_offset = 0;
    num_of_points = 4;
}

void Torus::draw(){
    for(double i = 0; i < 2 * M_PI; i += 2 * M_PI / num_of_cross_sections){
        Coord point(
                cos(i) * radius, 
                sin(i) * radius,
                0
                );
        draw_cross_section(point, -i, i + current_offset);
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

void Torus::update(){
    current_offset += rotation_speed;
    if(current_offset > 2 * M_PI){
        current_offset = 0;
    }
}

void Torus::kbin(unsigned char key, int x, int y){
    switch(key){
        case 'w':
            glRotatef(1, 1, 0, 0);
            break;
        case 'a':
            glRotatef(1, 0, 0, -1);
            break;
        case 's':
            glRotatef(1, -1, 0, 0);
            break;
        case 'd':
            glRotatef(1, 0, 0, 1);
            break;
        case 'q':
            glRotatef(1, 0, 1, 0);
            break;
        case 'e':
            glRotatef(1, 0, -1, 0);
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            num_of_points = static_cast<int>(key) - 48;
            break;
        case '-':
            rotation_speed -= 0.0005;
            break;
        case '+':
            rotation_speed += 0.0005;
            break;
        case '<':
            num_of_cross_sections -= 1;
            if(num_of_cross_sections < 1){
                num_of_cross_sections = 1;
            }
            break;
        case '>':
            num_of_cross_sections += 1;
            break;
        case ',':
            radius--;
            break;
        case '.':
            radius++;
            break;
        case 'k':
            smaller_radius--;
            break;
        case 'l':
            smaller_radius++;
            break;
    }
}
