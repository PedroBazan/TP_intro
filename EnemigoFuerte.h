#ifndef ENEMIGOFUERTE_H
#define ENEMIGOFUERTE_H
#include "Enemigo.h"

class EnemigoFuerte : public Enemigo {
public:
	EnemigoFuerte(int x, int y) : Enemigo(x, y, 2) {} 
	void dibujar() { gotoxy(x, y); textcolor(LIGHTRED); putch('W'); }
};
#endif
