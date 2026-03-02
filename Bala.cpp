#include <iostream>
#include <conio2.h>
#include "Bala.h"
using namespace std;

int Bala::getDireccion()
{
	return direccion;
}
Bala::Bala(int px, int py, int dir)
	: ObjetoBase(px, py)
{
	direccion = dir;
}

void Bala::mover()
{
	setPosicion(getX(), getY() + direccion);
	
	// Si sale bala se borra
	if (getY() < 1 || getY() > 24)
	{
		desactivar();
	}
}

void Bala::dibujar()
{
	if (direccion == -1)
		textcolor(LIGHTCYAN); 
	else
		textcolor(LIGHTRED);  
	
	gotoxy(getX(), getY());
	putch('|');
}
