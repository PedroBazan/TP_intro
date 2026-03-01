#include "Jugador.h"
#include <conio2.h>

Jugador::Jugador(int px, int py)
	: ObjetoBase(px, py)
{
	vidas = 3;
}

void Jugador::moverIzquierda() {
	if (getX() > 1) {
		setPosicion(getX() - 1, getY());
	}
}

void Jugador::moverDerecha() {
	if (getX() < 79) {   
		setPosicion(getX() + 1, getY());
	}
}

void Jugador::perderVida() {
	vidas--;
}

int Jugador::getVidas() const {
	return vidas;
}

void Jugador::dibujar() {
	textcolor(LIGHTGREEN);
	gotoxy(getX(), getY());
	putch('A');
}

void Jugador::mover() {
	
}
