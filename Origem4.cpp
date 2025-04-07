#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

float angulo = 0.0f;

void desenhaCirculoMulticolorido(float raio, int segmentos) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= segmentos; i++) {
        float t = (float)i / segmentos;
        float a = 2 * PI * t;
        float x = raio * cos(a);
        float y = raio * sin(a);
        glColor3f(cos(a) * 0.5f + 0.5f, sin(a) * 0.5f + 0.5f, 0.5f);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(320, 320, 0.0f);
    glRotatef(angulo, 0.0f, 0.0f, -1.0f);
    desenhaCirculoMulticolorido(100.0f, 100);
    glPopMatrix();

    glutSwapBuffers();
}

void atualiza(int valor) {
    angulo += 2.0f;
    if (angulo >= 360.0f) angulo -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(16, atualiza, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Círculo Multicolorido Girando");

    gluOrtho2D(0, 640, 0, 640);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutDisplayFunc(display);
    glutTimerFunc(0, atualiza, 0);

    glutMainLoop();
    return 0;
}
