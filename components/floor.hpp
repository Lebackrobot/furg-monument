#include <stdlib.h>
#include <GL/glut.h>

void floorComponent(float compxz, float alty) {
    glColor3f(0.1f, 0.4f, 0.1f);

    // Desenha varios retangulos formando uma 'parede'
    glBegin(GL_QUADS);         // Face frontal
    glNormal3f(0.0, 0.0, 1.0); // Normal da face
    glVertex3f(compxz / 2, 0, compxz / 2);
    glVertex3f(-compxz / 2, 0, compxz / 2);
    glVertex3f(-compxz / 2, -alty, compxz / 2);
    glVertex3f(compxz / 2, -alty, compxz / 2);
    glEnd();
    glBegin(GL_QUADS);          // Face traseira
    glNormal3f(0.0, 0.0, -1.0); // Normal da face
    glVertex3f(compxz / 2, 0, -compxz / 2);
    glVertex3f(compxz / 2, -alty, -compxz / 2);
    glVertex3f(-compxz / 2, -alty, -compxz / 2);
    glVertex3f(-compxz / 2, 0, -compxz / 2);
    glEnd();
    glBegin(GL_QUADS);          // Face lateral esquerda
    glNormal3f(-1.0, 0.0, 0.0); // Normal da face
    glVertex3f(-compxz / 2, 0, compxz / 2);
    glVertex3f(-compxz / 2, 0, -compxz / 2);
    glVertex3f(-compxz / 2, -alty, -compxz / 2);
    glVertex3f(-compxz / 2, -alty, compxz / 2);
    glEnd();
    glBegin(GL_QUADS);         // Face lateral direita
    glNormal3f(1.0, 0.0, 0.0); // Normal da face
    glVertex3f(compxz / 2, 0, compxz / 2);
    glVertex3f(compxz / 2, -alty, compxz / 2);
    glVertex3f(compxz / 2, -alty, -compxz / 2);
    glVertex3f(compxz / 2, 0, -compxz / 2);
    glEnd();
    glBegin(GL_QUADS);         // Face superior
    glNormal3f(0.0, 1.0, 0.0); // Normal da face
    glVertex3f(-compxz / 2, 0, -compxz / 2);
    glVertex3f(-compxz / 2, 0, compxz / 2);
    glVertex3f(compxz / 2, 0, compxz / 2);
    glVertex3f(compxz / 2, 0, -compxz / 2);
    glEnd();
    glBegin(GL_QUADS);          // Face inferior
    glNormal3f(0.0, -1.0, 0.0); // Normal da face
    glVertex3f(-compxz / 2, -alty, -compxz / 2);
    glVertex3f(compxz / 2, -alty, -compxz / 2);
    glVertex3f(compxz / 2, -alty, compxz / 2);
    glVertex3f(-compxz / 2, -alty, compxz / 2);
    glEnd();
}
