#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "ObjetoBase.h"

class Enemigo : public ObjetoBase {
private:
	int vida;
	
public:
	Enemigo(int x, int y, int v);
	
	void recibirDanio();
	bool estaVivo() const;
};

#endif
