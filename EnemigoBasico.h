#ifndef ENEMIGOBASICO_H
#define ENEMIGOBASICO_H
#include "Enemigo.h"

class EnemigoBasico: public Enemigo {
public:
	EnemigoBasico(int x, int y);
	
	void dibujar();
	void mover();
	
};

#endif
