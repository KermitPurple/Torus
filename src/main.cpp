#include<iostream>
#include<GL/glut.h>
#include<Torus.h>

Torus torus;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    torus.draw();
    torus.update();
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(650, 650);
    glutCreateWindow("Torus");
    glOrtho(-100, 100, -100, 100, -100, 100);
    glRotatef(60, 1, 0, 0);

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc([](unsigned char key, int x, int y){
            torus.kbin(key, x, y);
            });

    glutMainLoop();
	return 0;
}
