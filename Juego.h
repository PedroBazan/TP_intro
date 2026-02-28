#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "EnemigoBasico.h"
#include "Bala.h"

#define MAX_ENEMIGOS 30
#define MAX_BALAS 100

class Juego{
private:
	Jugador jugador;
	
	EnemigoBasico* enemigos[MAX_ENEMIGOS]; 
	Bala* balas[MAX_BALAS];
	int direccionEnemigos;
	
public:
	juego();
	void iniciar();
	void loop();
	void actualizar();
	void dibujar();
	void procesarIngreso();
	void dispararJugador();
	
	
};

#endif
