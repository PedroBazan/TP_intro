#include <iostream>
#include <conio2.h>
#include "Enemigo.h"
using namespace std;

Enemigo::Enemigo(int px, int py, int vidaInicial)
	: ObjetoBase(px, py) {
	vida = vidaInicial;
}

void Enemigo::recibirDanio() {
	vida--;
	if (vida <= 0)
		desactivar();
}

bool Enemigo::estaVivo() const {
	return vida > 0;
}
