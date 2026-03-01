#include "Enemigo.h"

Enemigo::Enemigo(int px, int py, int v)
	: ObjetoBase(px, py) {
	vida = v;
}

void Enemigo::recibirDanio() {
	vida--;
	if (vida <= 0)
		desactivar();
}

bool Enemigo::estaVivo() const {
	return vida > 0;
}
