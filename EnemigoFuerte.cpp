#include <iostream>
#include <conio2.h>
#include "EnemigoFuerte.h"
using namespace std;

EnemigoFuerte::EnemigoFuerte(int x, int y)
	: Enemigo(x, y, 2) {}

void EnemigoFuerte::dibujar() {
	gotoxy(x, y);
	putch('W');
}

