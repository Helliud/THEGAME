#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GL/glut.h"

#include <iostream>
#include <math.h>

using namespace std;
//COMANTARIOS EXTRA
//La Matrix sirve para cambiar de lugar el origen (0,0) a otra coordenada y el PopMatrix sirve para destruir a la matriz para que sea el origen originalmente (0,0)

double xCuadrado = -0.8;
double yCuadrado = 0.0;

double xCuadrado2 = 0.8;
double yCuadrado2 = 0.0;

double xBolita = 0.0;
double yBolita = 0.0;

double velocidad = 0.01;

void iniciar() {
	glClearColor(0, 0, 0, 1); //Color con el que se va a limpiar
	glPointSize(10); //Tamano del punto, en caso de que haya
	glOrtho(800, 0, 600, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW); //Inicializas la matriz 
	glLoadIdentity(); //Inicias la matriz
}


void dibujar() {
	//RECTANGULO IZQUIERDO
	glClear(GL_COLOR_BUFFER_BIT); // Se limpia la pantalla
	glPushMatrix(); //Esto sirve para empujar a la matriz, donde se inicia
	glTranslatef(xCuadrado, yCuadrado, 0); //Transladar la matriz
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

	glBegin(GL_QUADS); //Creas la figura
	glColor3f(1, 1, 1);
	glVertex2f(.015, .2);
	glVertex2f(.015, -.2);
	glVertex2f(-.015, -.2);
	glVertex2f(-.015, .2);
	glEnd();
	glPopMatrix(); //Para regresar a su punto original, se destruye

	//BOLITA
	glPushMatrix();
	glTranslatef(xBolita, yBolita, 0);
	glBegin(GL_QUADS);
	glColor4f(1, 1, 1, 0);
	glVertex2f(0.015, 0.02);
	glVertex2f(0.015, -0.02);
	glVertex2f(-0.015, -0.02);
	glVertex2f(-0.015, 0.02);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.95, 0);
	glBegin(GL_QUADS);
	glColor3f(0.25, 0.28, 0.28);
	glVertex2f(1, 0.07);
	glVertex2f(1, -0.07);
	glVertex2f(-1, -0.07);
	glVertex2f(-1, 0.07);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.95, 0);
	glBegin(GL_QUADS);
	glColor3f(0.25, 0.28, 0.28);
	glVertex2f(1, -0.07);
	glVertex2f(1, 0.07);
	glVertex2f(-1, 0.07);
	glVertex2f(-1, -0.07);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();// Aqui termina la limpieza, este mejora el cambio de imagen, mejor que el FlushBuffer


}

bool puntoIzq;
bool puntoDer;
int contador = 0;

void puntos() {

	if (xBolita == 0.88) {
		contador = contador + 1;
		cout << contador << endl;
	}
}

enum Direccion { Izquierda, Derecha, Arriba, Abajo };
Direccion direccionBolita = Direccion::Izquierda;
Direccion direccionBolita2 = Direccion::Arriba;

void checarColision() {

	if (xBolita < xCuadrado + 0.0075 && yBolita < yCuadrado + 0.2 && yBolita > yCuadrado - 0.2) {
		cout << "Colision" << endl;
		direccionBolita = Direccion::Derecha;
		velocidad += 0.001;
	}



	if (xBolita > xCuadrado2 - 0.0075 && yBolita > yCuadrado2 - 0.2 && yBolita < yCuadrado2 + 0.2) {
		cout << "Colision2" << endl;
		direccionBolita = Direccion::Izquierda;
		velocidad += 0.001;
	}


}


void actualizar() {
	glutPostRedisplay();

	if (direccionBolita == Direccion::Izquierda) {
		if (xBolita > -0.9) {
			xBolita -= velocidad;
		}

		else {
			direccionBolita = Direccion::Derecha;
		}
	}


	if (direccionBolita == Direccion::Derecha) {
		if (xBolita < 0.9) {
			xBolita += velocidad;
		}

		else {
			direccionBolita = Direccion::Izquierda;
		}
	}

	if (direccionBolita2 == Direccion::Arriba) {
		if (yBolita < 0.88) {
			yBolita += velocidad;
		}

		else {
			direccionBolita2 = Direccion::Abajo;
		}
	}

	if (direccionBolita2 == Direccion::Abajo) {
		if (yBolita > -0.88) {
			yBolita -= velocidad;
		}

		else {
			direccionBolita2 = Direccion::Arriba;
		}
	}

	checarColision();
	puntos();


}

void teclado(unsigned char tecla, int x, int y) {
	switch (tecla)
	{
	case GLFW_KEY_W:
		yCuadrado += 0.1;
		break;


	case GLFW_KEY_S:
		yCuadrado -= 0.1;
		break;

	case GLFW_KEY_L:
		yCuadrado2 -= 0.1;
		break;


	case GLFW_KEY_O:
		yCuadrado2 += 0.1;
		break;


	}

	if (yCuadrado > 0.8) {
		yCuadrado = 0.8;
	}

	if (yCuadrado < -0.8) {
		yCuadrado = -0.8;
	}

	if (yCuadrado2 > 0.8) {
		yCuadrado2 = 0.8;
	}

	if (yCuadrado2 < -0.8) {
		yCuadrado2 = -0.8;
	}
}


int main(int argc, char* argv[]) {
	//Iniciar la libreria GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //Tipo de color y donde se guardaran las imagenes
	//Fija tamaño y posición inicial de las ventanas
	glutInitWindowSize(800, 600); //Tamaño de la ventana
	glutInitWindowPosition(50, 50); //Posicion en donde va a iniciar la ventana
	glutCreateWindow("Ventana"); //Crea la ventana y titulo de la ventana
	//Declara los callbacks
	iniciar();
	glutDisplayFunc(dibujar); //Le asignamos la funcion que dibujara
	glutIdleFunc(actualizar); //Le asignamos la funcion que va hacer la accion que este dentro de la misma
	glutKeyboardFunc(teclado);
	//glutSpecialFunc(Funcion); //Para asignar teclas especiales con CTRL y esas
	glutMainLoop(); //Entra en loop de reconocimiento de eventos y es el ultimo que se ejecuta
	return 0;
}