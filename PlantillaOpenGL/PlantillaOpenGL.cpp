#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <winml.h>

#pragma comment(lib, "Winmm.lib")

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <math.h>

using namespace std;
//COMANTARIOS EXTRA
//La Matrix sirve para cambiar de lugar el origen (0,0) a otra coordenada y el PopMatrix sirve para destruir a la matriz para que sea el origen originalmente (0,0)

GLfloat xCuadrado = -0.8;
GLfloat yCuadrado = 0.0;

GLfloat xCuadrado2 = 0.8;
GLfloat yCuadrado2 = 0.0;

GLfloat xBolita = 0.0;
GLfloat yBolita = 0.0;

GLdouble velocidad = 1.8;
GLdouble velocidadBolita = 1;

GLdouble tiempoAnterior = 0.0;
GLdouble tiempoActual = 0.0;
GLdouble tiempoDiferencial = 0.0;

GLfloat xCelebracion = 0.0;
GLfloat yCelebracion = 1.0;

GLfloat xConfetti1 = 0.0;
GLfloat yConfetti1 = 0.0;
GLfloat zConfetti1 = 0.0;
GLdouble velocidadAngular = 8;

GLfloat rBolita = 1.0;
GLfloat gBolita = 1.0;
GLfloat bBolita = 1.0;


GLint contadorIzq = 0;
GLint contadorDer = 0;

bool reinicio = false;

enum Direccion { Izquierda, Derecha, Arriba, Abajo };
Direccion direccionBolita = Direccion::Izquierda;
Direccion direccionBolita2 = Direccion::Arriba;

//Declaramos
GLFWwindow * window;

void celebracion(){
	glPushMatrix();
	if (yCelebracion > -2.8) {
		yCelebracion -= 0.7 * tiempoDiferencial;
		zConfetti1 -= velocidadAngular * tiempoDiferencial;
		glTranslatef(xCelebracion, yCelebracion, 0);
		glRotatef(zConfetti1, 0, 0, 1);
		glPointSize((rand() % 2) * 8);
		glBegin(GL_POINTS);

		glColor3f(1, 0, 0);
		glVertex2f((rand() % 2) - 0.8, (rand() % 2) - 0.8);

		glColor3f(0, 1, 0);
		glVertex2f((rand() % 2) - 0.5, (rand() % 2) - 0.7);

		glColor3f(0, 0, 1);
		glVertex2f((rand() % 2) - 0.2, (rand() % 2) - 0.1);

		glColor3f(1, 0, 0);
		glVertex2f((rand() % 2) - 1, (rand() % 2) - 0.7);

		glColor3f(0, 1, 0);
		glVertex2f((rand() % 2) - 0.54, (rand() % 2) - 0.8);

		glColor3f(0, 0, 1);
		glVertex2f((rand() % 2) - 0.23, (rand() % 2) - 0.12);

		glColor3f(1, 0, 0);
		glVertex2f((rand() % 2) - 0.6, (rand() % 2) - 0.9);

		glColor3f(0, 1, 0);
		glVertex2f((rand() % 2) - 0.45, (rand() % 2) - 0.8);

		glColor3f(0, 0, 1);
		glVertex2f((rand() % 2) - 0.82, (rand() % 2) - 0.8);

		glColor3f(1, 0, 0);
		glVertex2f((rand() % 2) - 0.2, (rand() % 2) - 0.4);

		glColor3f(0, 1, 0);
		glVertex2f((rand() % 2) - 0.8, (rand() % 2) - 0.8);

		glColor3f(0, 0, 1);
		glVertex2f((rand() % 2) - 0.8, (rand() % 2) - 0.8);

		glColor3f(1, 0, 0);
		glVertex2f((rand() % 2) - 0.19, (rand() % 2) - 0.3);

		glColor3f(0, 1, 0);
		glVertex2f((rand() % 2) - 0.3, (rand() % 2) - 0.74);

		glColor3f(0, 0, 1);
		glVertex2f((rand() % 2) - 0.74, (rand() % 2) - 0.6);

		glColor3f(1, 0, 0);
		glVertex2f((rand() % 2), (rand() % 2));

		glColor3f(0, 1, 0);
		glVertex2f((rand() % 2) - 0.03, (rand() % 2) - 0.03);

		glColor3f(0, 0, 1);
		glVertex2f((rand() % 2) - 0.09, (rand() % 2) - 0.02);

		glColor3f(0, 0, 1);
		glVertex2f((rand() % 2) - 0.01, (rand() % 2) - 0.02);

		glEnd();

	}
	glPopMatrix();
}

void marcadorIzqierdo() {
	glPushMatrix();
	glPointSize(8);
	glTranslatef(0, 0.75,0);
	if (contadorIzq == 0) {
		glBegin(GL_POINTS);
		glColor3f(0.33, 0.33, 0.33);
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(-0.5f, -0.01f);
		glVertex2f(-0.5f, -0.02f);
		glVertex2f(-0.5f, -0.03f);
		glVertex2f(-0.5f, -0.04f);
		glVertex2f(-0.5f, -0.05f);
		glVertex2f(-0.5f, -0.06f);
		glVertex2f(-0.5f, -0.07f);
		glVertex2f(-0.5f, -0.08f);
		glVertex2f(-0.5f, -0.09f);

		glVertex2f(-0.49f, -0.09f);
		glVertex2f(-0.48f, -0.09f);
		glVertex2f(-0.47f, -0.09f);
		glVertex2f(-0.46f, -0.09f);

		glVertex2f(-0.46f, -0.08f);
		glVertex2f(-0.46f, -0.07f);
		glVertex2f(-0.46f, -0.06f);
		glVertex2f(-0.46f, -0.05f);
		glVertex2f(-0.46f, -0.04f);
		glVertex2f(-0.46f, -0.03f);
		glVertex2f(-0.46f, -0.02f);
		glVertex2f(-0.46f, -0.01f);
		glVertex2f(-0.46f, -0.0f);

		glVertex2f(-0.47f, -0.0f);
		glVertex2f(-0.48f, -0.0f);
		glVertex2f(-0.49f, -0.0f);
		glVertex2f(-0.5f, -0.0f);
		glEnd();
	}

	if (contadorIzq == 1) {
		//1
		glBegin(GL_POINTS);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(-0.5f, -0.01f);
		glVertex2f(-0.5f, -0.02f);
		glVertex2f(-0.5f, -0.03f);
		glVertex2f(-0.5f, -0.04f);
		glVertex2f(-0.5f, -0.05f);
		glVertex2f(-0.5f, -0.06f);
		glVertex2f(-0.5f, -0.07f);
		glVertex2f(-0.5f, -0.08f);
		glVertex2f(-0.5f, -0.09f);
		glEnd();
	}

	if (contadorIzq == 2) {
		glBegin(GL_POINTS);		
		glColor3f(0.5, 0.5, 0.5);
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(-0.49f, 0.0f);
		glVertex2f(-0.48f, 0.0f);
		glVertex2f(-0.47f, 0.0f);
		glVertex2f(-0.46f, 0.0f);

		glVertex2f(-0.46f, -0.01f);
		glVertex2f(-0.46f, -0.02f);
		glVertex2f(-0.46f, -0.03f);
		glVertex2f(-0.46f, -0.04f);
		glVertex2f(-0.46f, -0.05f);

		glVertex2f(-0.47f, -0.05f);
		glVertex2f(-0.48f, -0.05f);
		glVertex2f(-0.49f, -0.05f);
		glVertex2f(-0.5f, -0.05f);

		glVertex2f(-0.5f, -0.06f);
		glVertex2f(-0.5f, -0.07f);
		glVertex2f(-0.5f, -0.08f);
		glVertex2f(-0.5f, -0.09f);
		glVertex2f(-0.5f, -0.1f);

		glVertex2f(-0.49f, -0.1f);
		glVertex2f(-0.48f, -0.1f);
		glVertex2f(-0.47f, -0.1f);
		glVertex2f(-0.46f, -0.1f);
		glEnd();

	}

	glPopMatrix();
}

void marcadorDerecho() {
	glPushMatrix();
	glPointSize(8);
	glTranslatef(0, 0.75, 0);
	if (contadorDer == 0) {
		glBegin(GL_POINTS);
		glColor3f(0.33, 0.33, 0.33);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(0.5f, -0.01f);
		glVertex2f(0.5f, -0.02f);
		glVertex2f(0.5f, -0.03f);
		glVertex2f(0.5f, -0.04f);
		glVertex2f(0.5f, -0.05f);
		glVertex2f(0.5f, -0.06f);
		glVertex2f(0.5f, -0.07f);
		glVertex2f(0.5f, -0.08f);
		glVertex2f(0.5f, -0.09f);

		glVertex2f(0.51f, -0.09f);
		glVertex2f(0.52f, -0.09f);
		glVertex2f(0.53f, -0.09f);
		glVertex2f(0.54f, -0.09f);

		glVertex2f(0.54f, -0.08f);
		glVertex2f(0.54f, -0.07f);
		glVertex2f(0.54f, -0.06f);
		glVertex2f(0.54f, -0.05f);
		glVertex2f(0.54f, -0.04f);
		glVertex2f(0.54f, -0.03f);
		glVertex2f(0.54f, -0.02f);
		glVertex2f(0.54f, -0.01f);
		glVertex2f(0.54f, 0.0f);

		glVertex2f(0.53f, 0.0f);
		glVertex2f(0.52f, 0.0f);
		glVertex2f(0.51f, 0.0f);
		glVertex2f(0.5f, 0.0f);
		glEnd();
	}

	if (contadorDer == 1) {
		glBegin(GL_POINTS);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(0.5f, -0.01f);
		glVertex2f(0.5f, -0.02f);
		glVertex2f(0.5f, -0.03f);
		glVertex2f(0.5f, -0.04f);
		glVertex2f(0.5f, -0.05f);
		glVertex2f(0.5f, -0.06f);
		glVertex2f(0.5f, -0.07f);
		glVertex2f(0.5f, -0.08f);
		glVertex2f(0.5f, -0.09f);
		glEnd();
	}

	if (contadorDer == 2) {
		glBegin(GL_POINTS);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(0.51f, 0.0f);
		glVertex2f(0.52f, 0.0f);
		glVertex2f(0.53f, 0.0f);
		glVertex2f(0.54f, 0.0f);

		glVertex2f(0.54f, -0.01f);
		glVertex2f(0.54f, -0.02f);
		glVertex2f(0.54f, -0.03f);
		glVertex2f(0.54f, -0.04f);
		glVertex2f(0.54f, -0.05f);

		glVertex2f(0.53f, -0.05f);
		glVertex2f(0.52f, -0.05f);
		glVertex2f(0.51f, -0.05f);
		glVertex2f(0.5f, -0.05f);

		glVertex2f(0.5f, -0.06f);
		glVertex2f(0.5f, -0.07f);
		glVertex2f(0.5f, -0.08f);
		glVertex2f(0.5f, -0.09f);
		glVertex2f(0.5f, -0.1f);

		glVertex2f(0.51f, -0.1f);
		glVertex2f(0.52f, -0.1f);
		glVertex2f(0.53f, -0.1f);
		glVertex2f(0.54f, -0.1f);
		glEnd();
	}


	glPopMatrix();
}

void dibujarBarras() {
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
	
	//RECTANGULO IZQUIERDO
	glPushMatrix(); //Esto sirve para empujar a la matriz, donde se inicia
	glTranslatef(xCuadrado, yCuadrado, 0); //Transladar la matriz

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS); //Creas la figura
	glColor4f(0, 0, 0, 0.5);
	glVertex2f(-.03, .18);
	glVertex2f(-.03, -.21);
	glVertex2f(.01, -.21);
	glVertex2f(.01, .18);
	glEnd();

	glBegin(GL_QUADS); //Creas la figura
	glColor3f(1, 1, 1);
	glVertex2f(.015, .2);
	glVertex2f(.015, -.2);
	glVertex2f(-.015, -.2);
	glVertex2f(-.015, .2);
	glEnd();
	glPopMatrix();

	//RECTANGULO DERECHO
	glPushMatrix(); //Esto sirve para empujar a la matriz, donde se inicia
	glTranslatef(xCuadrado2, yCuadrado2, 0); //Transladar la matriz
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS); //Creas la figura
	glColor4f(0, 0, 0, 0.5);
	glVertex2f(.03, -.21);
	glVertex2f(.03, .18);
	glVertex2f(-.01, .18);
	glVertex2f(-.01, -.21);
	glEnd();


	glBegin(GL_QUADS); //Creas la figura
	glColor3f(1, 1, 1);
	glVertex2f(.015, .2);
	glVertex2f(.015, -.2);
	glVertex2f(-.015, -.2);
	glVertex2f(-.015, .2);
	glEnd();
	glPopMatrix(); //Para regresar a su punto original, se destruye
}

void dibujarBolita() {
	//BOLITA
	glPushMatrix();
	glTranslatef(xBolita, yBolita, 0);
	glBegin(GL_QUADS);
	glColor3f(rBolita, gBolita, bBolita);
	glVertex2f(0.015, 0.02);
	glVertex2f(0.015, -0.02);
	glVertex2f(-0.015, -0.02);
	glVertex2f(-0.015, 0.02);
	glEnd();
	glPopMatrix();
}

void dibujarFondo() {

	glPushMatrix();
	glLineWidth(4);
	glTranslatef(0, 0, 0);
	glBegin(GL_LINES);
	glColor3f(0.12, 0.12, 0.12);

	/*VERTICAL*/
	glVertex2f(0, 1);
	glVertex2f(0, -1);

	glVertex2f(-0.2, 1);
	glVertex2f(-0.2, -1);

	glVertex2f(-0.4, 1);
	glVertex2f(-0.4, -1);

	glVertex2f(-0.6, 1);
	glVertex2f(-0.6, -1);

	glVertex2f(-0.8, 1);
	glVertex2f(-0.8, -1);

	glVertex2f(-1, 1);
	glVertex2f(-1, -1);
	
	glVertex2f(0.2, 1);
	glVertex2f(0.2, -1);

	glVertex2f(0.4, 1);
	glVertex2f(0.4, -1);

	glVertex2f(0.6, 1);
	glVertex2f(0.6, -1);

	glVertex2f(0.8, 1);
	glVertex2f(0.8, -1);

	glVertex2f(1, 1);
	glVertex2f(1, -1);
	
	

	/*HORIZONTAL*/
	glVertex2f(1, 0);
	glVertex2f(-1, 0);

	glVertex2f(1, 0.2);
	glVertex2f(-1, 0.2);

	glVertex2f(1, 0.4);
	glVertex2f(-1, 0.4);

	glVertex2f(1, 0.6);
	glVertex2f(-1, 0.6);

	glVertex2f(1, 0.8);
	glVertex2f(-1, 0.8);

	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	/*-------------------------*/

	glVertex2f(1, 0);
	glVertex2f(-1, 0);

	glVertex2f(1, -0.2);
	glVertex2f(-1, -0.2);

	glVertex2f(1, -0.4);
	glVertex2f(-1, -0.4);

	glVertex2f(1, -0.6);
	glVertex2f(-1, -0.6);

	glVertex2f(1, -0.8);
	glVertex2f(-1, -0.8);

	glVertex2f(1, -1);
	glVertex2f(-1, -1);

	glEnd();
	glPopMatrix();
}

void dibujarParedes() {
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glVertex2f(1, .9);
	glVertex2f(-1, .9);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, -.9);
	glVertex2f(-1, -.9);
	glEnd();

	glPushMatrix();
	glTranslatef(-1, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0.0, 1);
	glVertex2f(0.0, -1);
	glVertex2f(0.1, -0.9);
	glVertex2f(0.1, 0.9);
	glVertex2f(0.0, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(0.02, 0.93);
	glVertex2f(0.02, -0.93);
	glColor3f(0.14, 0.14, 0.14);
	glVertex2f(0.1, -0.85);
	glVertex2f(0.1, 0.85);
	glVertex2f(0.02, 0.93);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0.0, 0.0);


	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0.0, 1);
	glVertex2f(0.0, -1);
	glVertex2f(-0.1, -0.9);
	glVertex2f(-0.1, 0.9);
	glVertex2f(0.0, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(-0.02, 0.93);
	glVertex2f(-0.02, -0.93);
	glColor3f(0.14, 0.14, 0.14);
	glVertex2f(-0.1, -0.85);
	glVertex2f(-0.1, 0.85);
	glVertex2f(-0.02, 0.93);
	glEnd();

	glPopMatrix();


}

void dibujarFondo2() {
	
	glPushMatrix();
	glLineWidth(4);
	glTranslatef(0, 0, 0);
	glBegin(GL_LINES);
	glColor3f(0.235, 0.235, 0.235);
	glVertex2f(1, 0.194);
	glVertex2f(-1, 0.194);

	glVertex2f(1, 0.394);
	glVertex2f(-1, 0.394);

	glVertex2f(1, 0.594);
	glVertex2f(-1, 0.594);

	glVertex2f(1, 0.794);
	glVertex2f(-1, 0.794);

	glVertex2f(1, -0.008);
	glVertex2f(-1, -0.008);

	glVertex2f(1, -0.208);
	glVertex2f(-1, -0.208);

	glVertex2f(1, -0.408);
	glVertex2f(-1, -0.408);

	glVertex2f(1, -0.608);
	glVertex2f(-1, -0.608);

	glVertex2f(1, -0.808);
	glVertex2f(-1, -0.808);
	glEnd();
	glPopMatrix();
}

void dibujarLineaCentral() {
	glLineWidth(6);
	glPushAttrib(GL_ENABLE_BIT);
	glLineStipple(2, 0x00FF);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	
		glColor3f(0.6, 0.6, 0.6);
		glVertex3f(0, 1, 0);
		glVertex3f(0, -1, 0);
	glEnd();
	glPopAttrib();
}

void moverCuadros() {
	int estadoTeclaDerecha = glfwGetKey(window, GLFW_KEY_W);
	if (estadoTeclaDerecha == GLFW_PRESS) {
		yCuadrado += velocidad * tiempoDiferencial;
	}

	int estadoTeclaIzquierda = glfwGetKey(window, GLFW_KEY_S);
	if (estadoTeclaIzquierda == GLFW_PRESS) {
		yCuadrado -= velocidad * tiempoDiferencial;
	}

	int estadoTeclaArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoTeclaArriba == GLFW_PRESS) {
		yCuadrado2 += velocidad * tiempoDiferencial;
	}
	int estadoTeclaAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoTeclaAbajo == GLFW_PRESS) {
		yCuadrado2 -= velocidad * tiempoDiferencial;
	}
}

void ganador() {

	if (contadorDer == 3) {
		glPushMatrix();
		glTranslatef(0.5, 0, 0);
		glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 0.0f);

		glVertex2f(-0.4f, 0.0f);
		glVertex2f(-0.4f, -0.2f);
		glVertex2f(0.0f, -0.2f);
		glVertex2f(0.0f, 0.0f);
		
		glEnd();

		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 1.0f, 0.0f);

		glVertex2f(-0.4f, 0.0f);
		glVertex2f(-0.4f, 0.2f);
		glVertex2f(-0.3f, 0.0f);

		glVertex2f(-0.27f, 0.0f);
		glVertex2f(-0.20f, 0.2f);
		glVertex2f(-0.13f, 0.0f);

		glVertex2f(-0.1f, 0.0f);
		glVertex2f(0.0f, 0.2f);
		glVertex2f(0.0f, 0.0f);

		glEnd();

		glPopMatrix();


		yCuadrado = 0.0;
		yCuadrado2 = 0.0;
		xBolita = 0.0;
		yBolita = 0.0;

		

		cout << "\n PRESIONA R PARA CERRAR EL JUEGO" << endl;
		int estadoTeclaReinicio = glfwGetKey(window, GLFW_KEY_R);
		if (estadoTeclaReinicio == GLFW_PRESS) {
			exit(EXIT_FAILURE);
			
		}
	}

	if (contadorIzq == 3)
	{

		/*Carita triste*/
		glPushMatrix();
		glTranslatef(-0.1, 0, 0);

		glBegin(GL_QUADS);
		
		glColor3f(1.0f, 1.0f, 0.0f);

		glVertex2f(-0.4f, 0.0f);
		glVertex2f(-0.4f, -0.2f);
		glVertex2f(0.0f, -0.2f);
		glVertex2f(0.0f, 0.0f);

		glEnd();

		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 1.0f, 0.0f);

		glVertex2f(-0.4f, 0.0f);
		glVertex2f(-0.4f, 0.2f);
		glVertex2f(-0.3f, 0.0f);

		glVertex2f(-0.27f, 0.0f);
		glVertex2f(-0.20f, 0.2f);
		glVertex2f(-0.13f, 0.0f);

		glVertex2f(-0.1f, 0.0f);
		glVertex2f(0.0f, 0.2f);
		glVertex2f(0.0f, 0.0f);

		glEnd();

		glPopMatrix();

		yCuadrado = 0.0;
		yCuadrado2 = 0.0;
		xBolita = 0.0;
		yBolita = 0.0;


		cout << "\n PRESIONA R PARA CERRAR EL JUEGO" << endl;
	
		int estadoTeclaReinicio = glfwGetKey(window, GLFW_KEY_R);
		if (estadoTeclaReinicio == GLFW_PRESS) {
			exit(EXIT_FAILURE);

		}
	}
	
}

void dibujar() {
	marcadorDerecho();
	marcadorIzqierdo();
	dibujarFondo2();
	dibujarFondo();
	dibujarLineaCentral();
	dibujarParedes();
	dibujarBarras();
	dibujarBolita();
	ganador();

	if (contadorDer == 3 || contadorIzq == 3) {
		celebracion();
	}
}

void checarColision() {

	if (xBolita < xCuadrado + 0.0075 && yBolita < yCuadrado + 0.2 && yBolita > yCuadrado - 0.2) {
		direccionBolita = Direccion::Derecha;
		velocidadBolita += 0.08;
	}

	if (xBolita > xCuadrado2 - 0.0075 && yBolita > yCuadrado2 - 0.2 && yBolita < yCuadrado2 + 0.2) {
		direccionBolita = Direccion::Izquierda;
		velocidadBolita += 0.08;
	}

	if (velocidadBolita > 1.8) {
		rBolita = (rand() % 2);
		gBolita = (rand() % 2);
		bBolita = (rand() % 2);
	}

	else {
		rBolita = 1.0;
		gBolita = 1.0;
		bBolita = 1.0;
	}
}

void limitarBarras() {
	if (yCuadrado > 0.68) {
		yCuadrado = 0.68;
	}

	if (yCuadrado < -0.68) {
		yCuadrado = -0.68;
	}

	if (yCuadrado2 > 0.68) {
		yCuadrado2 = 0.68;
	}

	if (yCuadrado2 < -0.68) {
		yCuadrado2 = -0.68;
	}
}

void respawnBolita() {
	int botonReinicio = glfwGetKey(window, GLFW_KEY_SPACE);
	if (botonReinicio == GLFW_PRESS) {
		reinicio = true;
	}

	if (xBolita >= 0.9) {
		contadorIzq += 1;
	

		xBolita = 0.0;
		yBolita = 0.0;
		reinicio = false;
		velocidadBolita = 1;


	}

	if (xBolita <= -0.9) {
		contadorDer += 1;
		xBolita = 0.0;
		yBolita = 0.0;
		reinicio = false;
		velocidadBolita = 1;
	}
}

void actualizar() {

	tiempoActual = glfwGetTime();
	tiempoDiferencial = tiempoActual - tiempoAnterior;

	moverCuadros();
	limitarBarras();
	checarColision();
	tiempoAnterior = tiempoActual;
	respawnBolita();




	if (reinicio) {

		if (direccionBolita == Direccion::Izquierda) {
			if (xBolita > -1) {
				xBolita -= velocidadBolita * tiempoDiferencial;
			}

			else {
				direccionBolita = Direccion::Derecha;
			}
		}


		if (direccionBolita == Direccion::Derecha) {
			if (xBolita < 1) {
				xBolita += velocidadBolita * tiempoDiferencial;
			}

			else {
				direccionBolita = Direccion::Izquierda;
			}
		}

		if (direccionBolita2 == Direccion::Arriba) {
			if (yBolita < 0.87) {
				yBolita += velocidadBolita * tiempoDiferencial;
			}

			else {
				direccionBolita2 = Direccion::Abajo;
			}
		}

		if (direccionBolita2 == Direccion::Abajo) {
			if (yBolita > -0.87) {
				yBolita -= velocidadBolita * tiempoDiferencial;
			}

			else {
				direccionBolita2 = Direccion::Arriba;
			}
		}
	}

}

void teclado_callback(GLFWwindow * window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W && (action == GLFW_REPEAT || action == GLFW_PRESS)) {
		yCuadrado += velocidad * tiempoDiferencial;
	}

	if (key == GLFW_KEY_S && (action == GLFW_REPEAT || action == GLFW_PRESS)) {
		yCuadrado -= velocidad * tiempoDiferencial;
	}

	if (key == GLFW_KEY_UP && (action == GLFW_REPEAT || action == GLFW_PRESS)) {
		yCuadrado2 += velocidad * tiempoDiferencial;
	}

	if (key == GLFW_KEY_DOWN && (action == GLFW_REPEAT || action == GLFW_PRESS)) {
		yCuadrado2 -= velocidad * tiempoDiferencial;
	}

}

int main() {

	LPCWSTR archivo = L"C:\\Users\\Eliud\\source\\repos\\Helliud\\THEGAME\\musica\\MusicaFondo.wav";
	
	PlaySound(archivo, NULL, SND_ASYNC | SND_FILENAME | SND_LOOP  );


	// Si no se pudo iniciar GLFW terminamos la ejecucion
	if (!glfwInit()) { exit(EXIT_FAILURE); } // Si se pudo iniciar GLFW entonces inicializamos la ventana

	window = glfwCreateWindow(1280, 720, "PONG", NULL, NULL);

	//SI no pudimos iniciar la ventana, entonces terminamos la ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto, activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		std::cout << glewGetErrorString(errorGlew);
	}

	cout << "\t\t\t ######  ####### #     #  #####" << endl;
	cout << "\t\t\t #     # #     # ##    # #     #" << endl;
	cout << "\t\t\t #     # #     # # #   # #" << endl;
	cout << "\t\t\t ######  #     # #  #  # #  ####" << endl;
	cout << "\t\t\t #       #     # #   # # #     #" << endl;
	cout << "\t\t\t #       #     # #    ## #     #" << endl;
	cout << "\t\t\t #       ####### #     #  #####" << endl;
	cout << "\n\n Equipo: \n Araceli Arizmendi Leon \n Joel Alejandro De Labra Valenzuela \n Jesus Antonio Escobedo Cota \n Javier Eliud Lizarraga Martin del Campo \n\n" << endl;
	
	glfwSetKeyCallback(window, teclado_callback);
	tiempoAnterior = glfwGetTime();

	//ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1280, 720);
		//Establece el color de borrado
		glClearColor(0.14, 0.14, 0.14, 0);
		//Clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		dibujar();
		actualizar();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

