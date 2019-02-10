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
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex2f(0.0, 0.0);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();// Aqui termina la limpieza, este mejora el cambio de imagen, mejor que el FlushBuffer

}

void actualizar() {
	glutPostRedisplay();

	


		if (abs(xCuadrado - xBolita) + abs(yCuadrado - yBolita) < 0.015) {
			cout << "Hay colision" << endl;
		}
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

	case GLFW_KEY_O:
		yCuadrado2 -= 0.1;
		break;


	case GLFW_KEY_L:
		yCuadrado2 += 0.1;
		break;

	
		}
}


int main(int argc, char* argv[]){
	//Iniciar la libreria GLUT
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //Tipo de color y donde se guardaran las imagenes
	//Fija tamaño y posición inicial de las ventanas
	glutInitWindowSize(800, 600); //Tamaño de la ventana
	glutInitWindowPosition(50, 50); //Posicion en donde va a iniciar la ventana
	glutCreateWindow("Ventana"); //Crea la ventana y titulo de la ventana
	//Declara los callbacks
	iniciar();
	glutDisplayFunc(dibujar); //Le asignamos la funcion que dibujara
	glutIdleFunc(actualizar); //Le asignamos la funcion que va hacer la accion que este dentro de la misma
	 // Draws the bullets on screen when they are active
	glutKeyboardFunc(teclado);
	//glutSpecialFunc(Funcion); //Para asignar teclas especiales con CTRL y esas
	glutMainLoop(); //Entra en loop de reconocimiento de eventos y es el ultimo que se ejecuta
	return 0;
}