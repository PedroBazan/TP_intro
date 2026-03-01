#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "EnemigoBasico.h"
#include "Bala.h"
#include "EnemigoFuerte.h"

#define MAX_ENEMIGOS 30
#define MAX_BALAS 100

class Juego {
private:
	Jugador jugador;
	
	Enemigo* enemigos[MAX_ENEMIGOS];
	Bala* balas[MAX_BALAS];
	
	int direccionEnemigos;
	bool enEjecucion;
	
public:
	Juego();
	~Juego();
	
	void ejecutar();
	void actualizar();
	void dibujar();
};
#endif
