#ifndef JUGADOR_H
#define JUGADOR_H

#include "ObjetoBase.h"

class Jugador : public ObjetoBase {
private:
	int vidas;
	
public:
	Jugador(int x, int y);
	
	void moverIzquierda();
	void moverDerecha();
	
	void perderVida();
	int getVidas() const;
	
	void dibujar();
	void mover();
};

#endif
