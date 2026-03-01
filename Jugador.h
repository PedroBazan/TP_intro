#ifndef JUGADOR_H
#define JUGADOR_H

#include "ObjetoBase.h"

class Jugador: public ObjetoBase{
private:
	int vidas;
	
public:
	Jugador( int x, int y);
	
	void dibujar();
	void mover();
	
	void perderVida();
	int getVidas();
};

#endif
