#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>

// Variáveis de rotação
GLfloat rotateX = 0.0f;
GLfloat rotateY = 0.0f;

// Função para calcular a transposta de uma matriz 4x4
void Transposta(float matriz[4][4])
{
    float aux;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }
    }
}

// Função para realizar uma translação usando uma matriz 4x4
void Translate(float dx, float dy, float dz)
{
    float matriz[4][4] = {{1, 0, 0, 0},
                          {0, 1, 0, 0},
                          {0, 0, 1, 0},
                          {0, 0, 0, 1}};
    matriz[0][3] = dx;
    matriz[1][3] = dy;
    matriz[2][3] = dz;
    Transposta(matriz);
    glMultMatrixf((float *)matriz);
}

// Função para desenhar um retângulo
void retangulo(float x, float y, float z, float largura, float altura)
{
    Translate(x, y, z);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glVertex3f(-largura / 2, -altura / 2, 0);
    glVertex3f(largura / 2, -altura / 2, 0);
    glVertex3f(largura / 2, altura / 2, 0);
    glVertex3f(-largura / 2, altura / 2, 0);
    glEnd();
    glPopAttrib();
}

// Função para desenhar um semicírculo
void desenharSemiCirculo(float x, float y, float z, float raio, float anguloInicial, float anguloFinal)
{
    int numSegmentos = 100;

    glPushMatrix();
    glTranslatef(x, y, z);

    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.0f, 0.5f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(x, y, z);

    for (int i = 0; i <= numSegmentos; ++i)
    {
        float angulo = anguloInicial + (i * (anguloFinal - anguloInicial) / numSegmentos);
        float xBorda = x + (raio / 0.9) * cos(angulo);
        float yBorda = y + (raio / 2) * sin(angulo);
        glVertex3f(xBorda, yBorda, z);
    }

    glEnd();
    glPopAttrib();
    glPopMatrix();
}

// Função para desenhar um semicírculo à direita
void desenharSemiCirculoDireita(float x, float y, float z, float raio, float anguloInicial, float anguloFinal)
{
    int numSegmentos = 100;

    glPushMatrix();
    glTranslatef(x, y, z);

    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(x, y - raio, z);

    for (int i = 0; i <= numSegmentos; ++i)
    {
        float angulo = anguloInicial + (i * (anguloFinal - anguloInicial) / numSegmentos);
        float xBorda = x + (raio / 0.9) * cos(angulo);
        float yBorda = (y - raio) + (raio / 2) * sin(angulo);
        glVertex3f(xBorda, yBorda, z);
    }

    glEnd();
    glPopMatrix();
}

// Função para desenhar um semicírculo abaixo
void desenharSemiCirculoEmbaixo(float x, float y, float z, float raio, float anguloInicial, float anguloFinal)
{
    int numSegmentos = 100;

    glPushMatrix();
    glTranslatef(x, y, z);

    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.0f, 0.5f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(x, y - raio, z);

    for (int i = 0; i <= numSegmentos; ++i)
    {
        float angulo = anguloInicial + (i * (anguloFinal - anguloInicial) / numSegmentos);
        float xBorda = x + (raio / 0.9) * cos(angulo);
        float yBorda = (y - raio) + (raio / 2) * sin(angulo);
        glVertex3f(xBorda, yBorda, z);
    }

    glEnd();
    glPopAttrib();
    glPopMatrix();
}

// Função para desenhar um semicírculo acima
void desenharSemiCirculoCima(float x, float y, float z, float raio, float anguloInicial, float anguloFinal, GLfloat cor[3])
{
    int numSegmentos = 100;

    glPushMatrix();
    glTranslatef(x, y, z);

    glColor3fv(cor);

    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(x, y - raio, z);

    for (int i = 0; i <= numSegmentos; ++i)
    {
        float angulo = anguloInicial + (i * (anguloFinal - anguloInicial) / numSegmentos);
        float xBorda = x + (raio / 0.9) * cos(angulo);
        float yBorda = (y - raio) + (raio / 2) * sin(angulo);
        glVertex3f(xBorda, yBorda, z);
    }

    glEnd();
    glPopAttrib();
    glPopMatrix();
}

// Função para desenhar um triângulo retângulo
void desenharTrianguloRetangulo(float x, float y, float z, float largura, float altura, GLfloat cor[3])
{
    glPushMatrix();
    glTranslatef(x, y, z);

    glColor3fv(cor);

    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0);
    glVertex3f(largura, 0, 0);
    glVertex3f(largura, altura, 0);
    glEnd();

    glPopMatrix();
}

// Função para desenhar um triângulo retângulo invertido
void desenharTrianguloRetanguloInvertido(float x, float y, float z, float largura, float altura, GLfloat cor[3])
{
    glPushMatrix();
    glTranslatef(x, y, z);

    glColor3fv(cor);

    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0);
    glVertex3f(largura, 0, 0);
    glVertex3f(0, altura, 0);
    glEnd();

    glPopMatrix();
}

// Função para desenhar um retângulo
void desenharRetangulo(float x, float y, float z, float largura, float altura, GLfloat cor[3])
{
    glPushMatrix();
    glTranslatef(x, y, z);

    glColor3fv(cor);

    glBegin(GL_QUADS);
    glVertex3f(0, 0, 0);
    glVertex3f(largura, 0, 0);
    glVertex3f(largura, altura, 0);
    glVertex3f(0, altura, 0);
    glEnd();

    glPopMatrix();
}

// Função para desenhar a logo
void furgLogo(void)
{
    GLfloat corAmarela[] = {1.0f, 1.0f, 0.0f};
    GLfloat corVermelha[] = {1.0f, 0.0f, 0.0f};
    GLfloat corLaranja[] = {0.8f, 0.5f, 0.0f};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    glLoadIdentity();
    gluLookAt(0, 80, 250, 0, 0, 0, 0, 1, 0);

    glScalef(0.2f, 0.2f, 0.2f); // Reduz o tamanho do logo em 50%

    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    retangulo(0, 0, 0, 50, 150);

    glColor3f(1.0f, 0.5f, 0.0f);
    glPushMatrix();
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    desenharSemiCirculo(4, 18, 0.1, 31, 3.13, 0);
    glPopMatrix();

    glColor3f(1.0f, 0.5f, 0.0f);
    glPushMatrix();

    glTranslatef(110, 0, 0);
    glRotatef(90, 0.0f, 0.0f, -1.0f);

    desenharSemiCirculoDireita(-4, -21, 0.1, 31, 3.13, 0);
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(-179, 0.0f, 0.0f, 1.0f);
    desenharSemiCirculoEmbaixo(0, 31, 0.1, 27, 3.13, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
    desenharSemiCirculoCima(0, 33, 0.1, 13, 3.13, 0, corAmarela);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    desenharTrianguloRetangulo(-30, 45, 0.1, 10, 5, corVermelha);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
    desenharTrianguloRetanguloInvertido(20, 45, 0.1, 10, 5, corVermelha);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, -30, 0);
    desenharRetangulo(0, 0, 0.1, 60, 10, corVermelha);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -30, 0);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    desenharRetangulo(0, 0, 0.1, 75, 10, corVermelha);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, -30, 0);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    desenharRetangulo(0, 0, 0.1, 75, 10, corVermelha);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15, -15, 0);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    desenharRetangulo(0, 0, 0.1, 70, 30, corAmarela);
    glPopMatrix();

    glutSwapBuffers();
}