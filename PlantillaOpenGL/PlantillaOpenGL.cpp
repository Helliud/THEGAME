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

double velocidad = 1.2;
double velocidadBolita = 1;

double tiempoAnterior = 0.0;
double tiempoActual = 0.0;
double tiempoDiferencial = 0.0;

int contadorIzq = 0;
int contadorDer = 0;

bool reinicio = false;

enum Direccion { Izquierda, Derecha, Arriba, Abajo };
Direccion direccionBolita = Direccion::Izquierda;
Direccion direccionBolita2 = Direccion::Arriba;

//Declaramos
GLFWwindow * window;

void marcadorIzqierdo() {

	if (contadorIzq == 0) {
		//0
		glBegin(GL_POINTS);
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

	if (contadorIzq == 3) {
		exit(EXIT_SUCCESS);
	}
}

void marcadorDerecho() {
	glPointSize(5);
	if (contadorDer == 0) {
		glBegin(GL_POINTS);
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

	if (contadorDer == 3) {
		exit(EXIT_SUCCESS);
	}
}

void dibujarBarras() {
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
}

void dibujarBolita() {
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
}

void barreras() {

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

void dibujar() {
	dibujarBarras();
	dibujarBolita();
	barreras();
}

void checarColision() {

	if (xBolita < xCuadrado + 0.0075 && yBolita < yCuadrado + 0.2 && yBolita > yCuadrado - 0.2) {
		std::cout << "Colision" << endl;
		direccionBolita = Direccion::Derecha;
		velocidadBolita += 0.08;
	}



	if (xBolita > xCuadrado2 - 0.0075 && yBolita > yCuadrado2 - 0.2 && yBolita < yCuadrado2 + 0.2) {
		std::cout << "Colision2" << endl;
		direccionBolita = Direccion::Izquierda;
		velocidadBolita += 0.08;
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
		glPointSize(5);

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

	marcadorIzqierdo();
	marcadorDerecho();



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

	// Si no se pudo iniciar GLFW terminamos la ejecucion
	if (!glfwInit()) { exit(EXIT_FAILURE); } // Si se pudo iniciar GLFW entonces inicializamos la ventana

	window = glfwCreateWindow(800, 600, "Ventana", NULL, NULL);

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

	cout << "\nPONG \n\n Equipo: \n Araceli Arizmendi Leon \n Joel Alejandro Delabra \n Jesus Antonio Escobedo Cota \n Javier Eliud Lizarraga Martin del Campo \n\n" << endl;
	
	glfwSetKeyCallback(window, teclado_callback);
	tiempoAnterior = glfwGetTime();

	//ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 800, 600);
		//Establece el color de borrado
		glClearColor(0, 0, 0, 0);
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


