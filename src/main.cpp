#include<iostream>
#include<GL/glut.h>
#include<Torus.h>

Torus torus;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void kbin(unsigned char key, int x, int y){
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(650, 650);
    glutCreateWindow("Torus");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(kbin);

    glutMainLoop();
	return 0;
}
