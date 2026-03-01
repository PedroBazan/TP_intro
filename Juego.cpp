#include <iostream>
#include <conio2.h>
#include "Juego.h"
#include <windows.h>
using namespace std;



Juego::Juego() : jugador(40, 23) {
	enEjecucion = true;
	
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		enemigos[i] = nullptr;
	
	for (int i = 0; i < MAX_BALAS; i++)
		balas[i] = nullptr;
	
	enemigos[0] = new EnemigoBasico(10, 5);
	enemigos[1] = new EnemigoFuerte(20, 5);
	enemigos[2] = new EnemigoBasico(30, 5);
}

Juego::~Juego() {
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		delete enemigos[i];
}

void Juego::actualizar() {
	jugador.mover();
	
	for (int i = 0; i < MAX_ENEMIGOS; i++) {
		if (enemigos[i] && enemigos[i]->estaActivo()) {
			// movimiento 
		}
	}
	
	if (jugador.getVidas() <= 0)
		enEjecucion = false;
}

void Juego::dibujar() {
	clrscr();
	
	jugador.dibujar();
	
	for (int i = 0; i < MAX_ENEMIGOS; i++) {
		if (enemigos[i] && enemigos[i]->estaActivo())
			enemigos[i]->dibujar();
	}
}

void Juego::ejecutar() {
	while (enEjecucion) {
		actualizar();
		dibujar();
		Sleep(50);
	}
}
