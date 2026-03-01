#include <iostream>
#include <conio2.h>
#include "EnemigoFuerte.h"
using namespace std;


EnemigoFuerte::EnemigoFuerte(int px, int py)
	: Enemigo(px, py, 2) {}

void EnemigoFuerte::mover()
{
	// VACIO
}

void EnemigoFuerte::dibujar() {
	textcolor(LIGHTRED);
	gotoxy(getX(), getY());
	putch('W');
}
