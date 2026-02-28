#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "ObjetoBase.h"

 class Enemigo: public ObjetoBase {
 protected:
	 int vida;
	 
 public: 
	 Enemigo( int x, int y, int r);
	 
	 void recibirDanio();
	 void estaMuerto();
	 bool estaVivo()const;
	
 };
 
#endif
