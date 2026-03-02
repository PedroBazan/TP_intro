#ifndef BALA_H
#define BALA_H
#include "ObjetoBase.h"

class Bala: public ObjetoBase{
private:
	int direccion;
	
	
public: 
	Bala (int x, int y, int dir);
	void dibujar();
	void mover();
	int getDireccion();
};

#endif
