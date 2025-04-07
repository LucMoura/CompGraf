#include <GL/glut.h>

float x_offset = 0.0f;
float direcao = 1.0f;

void desenhaQuadrado() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(x_offset, 0.0f, 0.0f);

    glColor3f(0.5f, 0.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(280, 280);
    glVertex2f(360, 280);
    glVertex2f(360, 360);
    glVertex2f(280, 360);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void atualiza(int valor) {
    x_offset += 2.0f * direcao;

    if (x_offset > 200 || x_offset < -200) {
        direcao = -direcao;
    }

    glutPostRedisplay();
    glutTimerFunc(16, atualiza, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadrado Roxo em Movimento");

    gluOrtho2D(0, 640, 0, 640);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutDisplayFunc(desenhaQuadrado);
    glutTimerFunc(0, atualiza, 0);

    glutMainLoop();
    return 0;
}
