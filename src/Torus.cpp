#include<Torus.h>
#include<GL/glut.h>
#include<math.h>
#include<Coord.h>
#include<iostream>

// private

Torus* Torus::current_instance;

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

void Torus::reset(){
    radius = 75;
    smaller_radius = 25;
    rotation_speed = 0.003;
    current_offset = 0;
    num_of_cross_sections = 30;
    num_of_points = 4;
}

// public

Torus::Torus(){
    current_instance = this;
    reset();
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
            glRotatef(2, 1, 0, 0);
            break;
        case 'a':
            glRotatef(2, 0, 0, -1);
            break;
        case 's':
            glRotatef(2, -1, 0, 0);
            break;
        case 'd':
            glRotatef(2, 0, 0, 1);
            break;
        case 'q':
            glRotatef(2, 0, 1, 0);
            break;
        case 'e':
            glRotatef(2, 0, -1, 0);
            break;
        case 'n':
            current_instance->num_of_points--;
            if(current_instance->num_of_points < 1){
                current_instance->num_of_points = 1;
            }
            break;
        case 'm':
            current_instance->num_of_points++;
            break;
        case '-':
            current_instance->rotation_speed -= 0.0005;
            break;
        case '+':
            current_instance->rotation_speed += 0.0005;
            break;
        case '<':
            current_instance->num_of_cross_sections--;
            if(current_instance->num_of_cross_sections < 1){
                current_instance->num_of_cross_sections = 1;
            }
            break;
        case '>':
            current_instance->num_of_cross_sections++;
            break;
        case ',':
            current_instance->radius--;
            break;
        case '.':
            current_instance->radius++;
            break;
        case 'k':
            current_instance->smaller_radius--;
            break;
        case 'l':
            current_instance->smaller_radius++;
            break;
        case 'r':
            current_instance->reset();
            break;
        case '\033':
            exit(0);
    }
}

void Torus::print_controls(){
    std::cout << "w, a, s, d, q, e : rotate" << std::endl;
    std::cout << "n : reduce number of points per section" << std::endl;
    std::cout << "m : increase number of points per section" << std::endl;
    std::cout << "- : reduce rotation speed" << std::endl;
    std::cout << "+ : increase rotation speed" << std::endl;
    std::cout << "< : decrease number of cross sections" << std::endl;
    std::cout << "> : increase number of cross sections" << std::endl;
    std::cout << ", : decrease radius" << std::endl;
    std::cout << ". : increase radius" << std::endl;
    std::cout << "k : decrease inner radius" << std::endl;
    std::cout << "l : increase inner radius" << std::endl;
    std::cout << "r : reset" << std::endl;
    std::cout << "esc : quit" << std::endl;
}

void Torus::display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    current_instance->draw();
    current_instance->update();
    glutSwapBuffers();
}
