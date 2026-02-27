#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "ObjetoBase.h"

 class Enemigo: public ObjetoBase {
 protected:
	 int resistencia;
	 
 public: 
	 Enemigo( int x, int y, int r);
	 
	 virutal void recibirDani();
	 bool estaMuerto();
 };
 
#endif
