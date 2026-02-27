#ifndef JUGADOR_H
#define jUGADOR_H

#include "ObjetoBase.h"

class Jugador: public ObjetoBase{
private:
	int vidas;
	
public:
	Jugador( int x, int y);
	
	void dibujar();
	void mover (char tecla);
	
	void perderVida();
	int getVidas();
};

#endif
