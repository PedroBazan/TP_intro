#include <iostream>
#include <conio2.h>
#include "Jugador.h"
using namespace std;

Jugador::Jugador(int px, int py) :ObjetoBase(px, py) {
	vidas = 3;
}

void Jugador::mover() {
	if (kbhit()) {
		char tecla = getch();
		
		if (tecla == 'a' && x > 1)
			x--;
		
		if (tecla == 'd' && x < 78)
			x++;
	}
}

void Jugador::dibujar() {
	gotoxy(x, y);
	putch('A');
}

int Jugador::getVidas() const {
	return vidas;
}

void Jugador::perderVida() {
	vidas--;
}
