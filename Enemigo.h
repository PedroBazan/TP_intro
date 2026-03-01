#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "ObjetoBase.h"

 class Enemigo: public ObjetoBase {
 protected:
	 int vida;
	 
 public: 
	 Enemigo(int x, int y, int v) : ObjetoBase(x, y) { vida = v; }
	 virtual ~Enemigo() {} 
	 virtual void dibujar() = 0; // Polimorfismo revisar liberacion de memoria
	 void recibirDanio() { vida--; if(vida <= 0) desactivar(); }
	 bool estaVivo() const { return vida > 0; }
	 void mover() override { y++; } // Movimiento hacia abajo
	
 };
 
#endif
