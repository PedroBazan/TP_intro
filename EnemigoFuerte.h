#ifndef ENEMIGOFUERTE_H
#define ENEMIGOFUERTE_H

#include "Enemigo.h"

class EnemigoFuerte : public Enemigo {
public:
	EnemigoFuerte(int x, int y);
	void mover();
	void dibujar();
};

#endif
