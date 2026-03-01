#include <iostream>
#include <conio2.h>
#include "Bala.h"
using namespace std;


Bala::Bala(int px, int py, int dir)
	: ObjetoBase(px, py)
{
	direccion = dir;
}

void Bala::mover()
{
	// Movimiento vertical según dirección
	setPosicion(getX(), getY() + direccion);
	
	// Si sale de pantalla, se desactiva
	if (getY() < 1)
	{
		desactivar();
	}
}

void Bala::dibujar()
{
	textcolor(LIGHTBLUE);
	gotoxy(getX(), getY());
	putch('|');
}
