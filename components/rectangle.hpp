#include <GL/glut.h>
#include <string>
#include "furg.hpp"

// Função para desenhar texto em uma posição específica
void drawText(float x, float y, const std::string &text, float r, float g, float b)
{
    glColor3f(r, g, b); // Define a cor do texto
    glRasterPos2f(x, y);
    for (char c : text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void rectangleComponent()
{
    glPushMatrix();

    // Definindo cores para as faces
    GLfloat frontColor[] = {0.9f, 0.9f, 0.9f};  // Cor da face frontal (Cinza Muito Claro)
    GLfloat backColor[] = {0.7f, 0.7f, 0.7f};   // Cor da face traseira (Cinza Médio)
    GLfloat sideColor[] = {0.5f, 0.5f, 0.5f};   // Cor das faces laterais (Cinza Escuro)
    GLfloat topColor[] = {0.5f, 0.5f, 0.5f};    // Cor da face superior (Cinza)
    GLfloat bottomColor[] = {0.2f, 0.8f, 0.2f}; // Cor da face inferior (Verde)

    float xFront = 25.0f;  // Largura da face frontal
    float xSide = 20.0f;   // Largura das faces laterais
    float y = 0.0f;        // Altura inferior
    float y2 = 65.0f;      // Altura superior
    float zFront = -10.0f; // Profundidade da face frontal
    float zBack = -50.0f;  // Profundidade da face traseira

    // Rotaciona o monumento em torno do eixo Y
    glRotatef(30.0f, 0.0f, 1.0f, 0.0f); // 30 graus em torno do eixo Y

    // Desenha a face frontal
    glBegin(GL_QUADS);
    glColor3fv(frontColor);
    glVertex3f(xFront, y, zFront);
    glVertex3f(-xFront, y, zFront);
    glVertex3f(-xFront, y2, zFront);
    glVertex3f(xFront, y2, zFront);
    glEnd();

    // Desenha o texto "FURG" na face frontal com efeito de relevo
    glPushMatrix();
    glTranslatef(-10.0f, 30.0f, 0.0f); // Ajusta a posição do texto


    //furgLogo();

    // Efeito de relevo: desenha sombra
    drawText(5.4f, 10.0f, "F", 0.3f, 0.3f, 0.3f);  // Sombra cinza escuro
    drawText(5.4f, 0.0f, "U", 0.3f, 0.3f, 0.3f);   // Sombra cinza escuro
    drawText(5.4f, -10.0f, "R", 0.3f, 0.3f, 0.3f); // Sombra cinza escuro
    drawText(5.4f, -20.0f, "G", 0.3f, 0.3f, 0.3f); // Sombra cinza escuro

    // Desenha o texto com a cor principal
    glColor3f(0.0f, 0.0f, 0.0f); // Cor do texto (preto)
    drawText(5.0f, 10.0f, "F", 0.0f, 0.0f, 0.0f);
    drawText(5.0f, 0.0f, "U", 0.0f, 0.0f, 0.0f);
    drawText(5.0f, -10.0f, "R", 0.0f, 0.0f, 0.0f);
    drawText(5.0f, -20.0f, "G", 0.0f, 0.0f, 0.0f);

    glPopMatrix();

    // Desenha a face traseira
    glBegin(GL_QUADS);
    glColor3fv(backColor);
    glVertex3f(xSide, y, zBack);
    glVertex3f(-xSide, y, zBack);
    glVertex3f(-xSide, y2, zBack);
    glVertex3f(xSide, y2, zBack);
    glEnd();

    // Desenha as faces laterais
    glBegin(GL_QUADS);
    glColor3fv(sideColor);
    glVertex3f(xFront, y, zFront);
    glVertex3f(xSide, y, zBack);
    glVertex3f(xSide, y2, zBack);
    glVertex3f(xFront, y2, zFront);
    glEnd();

    glBegin(GL_QUADS);
    glColor3fv(sideColor);
    glVertex3f(-xFront, y, zFront);
    glVertex3f(-xSide, y, zBack);
    glVertex3f(-xSide, y2, zBack);
    glVertex3f(-xFront, y2, zFront);
    glEnd();

    // Desenha a face superior
    glBegin(GL_QUADS);
    glColor3fv(topColor);
    glVertex3f(xFront, y2, zFront);
    glVertex3f(-xFront, y2, zFront);
    glVertex3f(-xSide, y2, zBack);
    glVertex3f(xSide, y2, zBack);
    glEnd();

    // Desenha a face inferior
    glBegin(GL_QUADS);
    glColor3fv(bottomColor);
    glVertex3f(xFront, y, zFront);
    glVertex3f(-xFront, y, zFront);
    glVertex3f(-xSide, y, zBack);
    glVertex3f(xSide, y, zBack);
    glEnd();

    glPopMatrix();
}
