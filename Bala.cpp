#include <iostream>
#include <conio2.h>
#include "Bala.h"
using namespace std;

Bala::Bala(int px, int py) : ObjetoBase(px, py, pdir) {}

void Bala::mover() {
	y--;
	if (y < 1)
		desactivar();
}

void Bala::dibujar() {
	gotoxy(x, y);
	putch('|');
}
