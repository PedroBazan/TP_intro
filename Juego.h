#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "EnemigoBasico.h"
#include "Bala.h"
#include "EnemigoFuerte.h"

#define FILAS 5
#define COLUMNAS 11
#define MAX_ENEMIGOS (FILAS * COLUMNAS)
#define MAX_BALAS 200

class Juego {
private:
	Jugador jugador;
	
	Enemigo* enemigos[MAX_ENEMIGOS];
	Bala* balas[MAX_BALAS];
	
	int direccionEnemigos;
	int contadorMovimiento;
	int puntaje;
	int balasDisponibles;
	bool enEjecucion;
	
public:
	Juego();
	~Juego();
	
	void ejecutar();
	void actualizar();
	void dibujar();
};
#endif
