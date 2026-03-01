#include <iostream>
#include <conio2.h>
#include "Juego.h"
#include "PantallaInicio.h"



using namespace std;



int main() {
	mostrarPantallaInicio();
	Juego juego;
	juego.ejecutar();
	return 0;
}

