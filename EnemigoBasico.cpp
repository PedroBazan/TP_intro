#include <iostream>
#include <conio2.h>
#include "EnemigoBasico.h"
using namespace std;

EnemigoBasico::EnemigoBasico(int px, int py)
	: Enemigo(px, py, 1) {}

void EnemigoBasico::mover()
{
	// VACIO
}

void EnemigoBasico::dibujar() {
	textcolor(WHITE);
	gotoxy(getX(), getY());
	putch('V');
}
