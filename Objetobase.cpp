#include "ObjetoBase.h"

ObjetoBase::ObjetoBase(int px, int py) {
	x = px;
	y = py;
	activa = true;
}

int ObjetoBase::getX() const {
	return x;
}

int ObjetoBase::getY() const {
	return y;
}

void ObjetoBase::setPosicion(int px, int py) {
	x = px;
	y = py;
}

bool ObjetoBase::estaActivo() const {
	return activa;
}

void ObjetoBase::desactivar() {
	activa = false;
}
