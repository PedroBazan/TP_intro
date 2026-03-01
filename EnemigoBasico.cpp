#include <iostream>
#include <conio2.h>
#include "EnemigoBasico.h"
using namespace std;

EnemigoBasico::EnemigoBasico(int x, int y)
	: Enemigo(x, y, 1) {}

void EnemigoBasico::dibujar() {
	gotoxy(x, y);
	putch('V');
}

