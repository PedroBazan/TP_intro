#include <iostream>
#include <conio2.h>
#include <cstdlib>
#include <ctime>
#include "Juego.h"
#include <windows.h>

using namespace std;

Juego::Juego() : jugador(40, 23)
{
	enEjecucion = true;
	direccionEnemigos = 1;
	contadorMovimiento = 0;
	puntaje = 0;
	balasDisponibles = 200;
	
	srand(time(NULL));
	
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		enemigos[i] = NULL;
	
	for (int i = 0; i < MAX_BALAS; i++)
		balas[i] = NULL;
	
	int indice = 0;
	
	int inicioX = 10;
	int inicioY = 3;
	int separacionX = 5;
	int separacionY = 2;
	
	for (int fila = 0; fila < 5; fila++)
	{
		for (int columna = 0; columna < 11; columna++)
		{
			int posX = inicioX + columna * separacionX;
			int posY = inicioY + fila * separacionY;
			
			if (rand() % 4 == 0)
				enemigos[indice] = new EnemigoFuerte(posX, posY);
			else
				enemigos[indice] = new EnemigoBasico(posX, posY);
			
			indice++;
		}
	}
}

Juego::~Juego()
{
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		delete enemigos[i];
	
	for (int i = 0; i < MAX_BALAS; i++)
		delete balas[i];
}

void Juego::actualizar()
{
	// CONTROLES
	if (kbhit())
	{
		char tecla = getch();
		
		if (tecla == 'a' || tecla == 'A')
			jugador.moverIzquierda();
		
		if (tecla == 'd' || tecla == 'D')
			jugador.moverDerecha();
		
		if (tecla == ' ')
		{
			if (balasDisponibles > 0)   
			{
				for (int i = 0; i < MAX_BALAS; i++)
				{
					if (balas[i] == NULL || !balas[i]->estaActivo())
					{
						if (balas[i] != NULL)
							delete balas[i];
						
						balas[i] = new Bala(
											jugador.getX(),
											jugador.getY() - 1,
											-1
											);
						
						balasDisponibles--;
						if (balasDisponibles <= 0)
							enEjecucion = false;
						break;
					}
				}
			}
		}
	} 
	
	// DISPARO ENEMIGO
	if (rand() % 20 == 0)
	{
		int columnaRandom = rand() % 11;
		
		Enemigo* enemigoMasAbajo = NULL;
		int yMasAbajo = -1;
		
		for (int i = 0; i < MAX_ENEMIGOS; i++)
		{
			if (enemigos[i] != NULL && enemigos[i]->estaActivo())
			{
				int columna = (enemigos[i]->getX() - 10) / 5;
				
				if (columna == columnaRandom)
				{
					if (enemigos[i]->getY() > yMasAbajo)
					{
						yMasAbajo = enemigos[i]->getY();
						enemigoMasAbajo = enemigos[i];
					}
				}
			}
		}
		
		if (enemigoMasAbajo != NULL)
		{
			for (int i = 0; i < MAX_BALAS; i++)
			{
				if (balas[i] == NULL || !balas[i]->estaActivo())
				{
					if (balas[i] != NULL)
						delete balas[i];
					
					balas[i] = new Bala(
										enemigoMasAbajo->getX(),
										enemigoMasAbajo->getY() + 1,
										1
										);
					break;
				}
			}
		}
	}
	
	// MOVIMIENTO ENEMIGOS
	contadorMovimiento++;
	
	if (contadorMovimiento % 15 == 0)
	{
		int maxX = 0;
		int minX = 500;
		
		for (int i = 0; i < MAX_ENEMIGOS; i++)
		{
			if (enemigos[i] != NULL && enemigos[i]->estaActivo())
			{
				int x = enemigos[i]->getX();
				if (x > maxX) maxX = x;
				if (x < minX) minX = x;
			}
		}
		
		bool tocarBorde = false;
		
		if ((direccionEnemigos == 1 && maxX >= 70) ||
			(direccionEnemigos == -1 && minX <= 5))
			tocarBorde = true;
		
		if (tocarBorde)
		{
			direccionEnemigos *= -1;
			
			for (int i = 0; i < MAX_ENEMIGOS; i++)
				if (enemigos[i] != NULL && enemigos[i]->estaActivo())
					enemigos[i]->setPosicion(
											 enemigos[i]->getX(),
											 enemigos[i]->getY() + 2
											 );
		}
		else
		{
			for (int i = 0; i < MAX_ENEMIGOS; i++)
				if (enemigos[i] != NULL && enemigos[i]->estaActivo())
					enemigos[i]->setPosicion(
											 enemigos[i]->getX() + direccionEnemigos,
											 enemigos[i]->getY()
											 );
		}
	}
	
	// MOVER BALAS
	for (int i = 0; i < MAX_BALAS; i++)
	{
		if (balas[i] != NULL)
		{
			if (balas[i]->estaActivo())
				balas[i]->mover();
			else
			{
				delete balas[i];
				balas[i] = NULL;
			}
		}
	}
	
	// COLISIONES
	for (int i = 0; i < MAX_BALAS; i++)
	{
		if (balas[i] != NULL && balas[i]->estaActivo())
		{
			// Bala jugador
			if (balas[i]->getDireccion() == -1)
			{
				for (int j = 0; j < MAX_ENEMIGOS; j++)
				{
					if (enemigos[j] != NULL && enemigos[j]->estaActivo())
					{
						if (balas[i]->getX() == enemigos[j]->getX() &&
							balas[i]->getY() == enemigos[j]->getY())
						{
							enemigos[j]->recibirDanio();
							balas[i]->desactivar();
							
							if (!enemigos[j]->estaActivo())
								puntaje += 10;
							
							break;
						}
					}
				}
			}
			
			// Bala enemigo
			if (balas[i]->getDireccion() == 1)
			{
				if (balas[i]->getX() == jugador.getX() &&
					balas[i]->getY() == jugador.getY())
				{
					jugador.perderVida();
					balas[i]->desactivar();
					
					// Parpadeo 
					for (int k = 0; k < 3; k++)
					{
						gotoxy(jugador.getX(), jugador.getY());
						cout << " ";
						Sleep(70);
						
						jugador.dibujar();
						Sleep(70);
					}
				}
			}
		}
	}
	
	
	if (jugador.getVidas() <= 0)
		enEjecucion = false;
	
	for (int i = 0; i < MAX_ENEMIGOS; i++)
	{
		if (enemigos[i] != NULL && enemigos[i]->estaActivo())
		{
			if (enemigos[i]->getY() >= jugador.getY())
			{
				enEjecucion = false;
				break;
			}
		}
	}
}

void Juego::dibujar()
{
	clrscr();
	
	gotoxy(2,1);
	cout << "Puntaje: " << puntaje;
	
	gotoxy(60,1);
	cout << "Vidas: " << jugador.getVidas();
	
	gotoxy(30,1);
	cout << "Balas: " << balasDisponibles;
	
	jugador.dibujar();
	
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		if (enemigos[i] != NULL && enemigos[i]->estaActivo())
			enemigos[i]->dibujar();
	
	for (int i = 0; i < MAX_BALAS; i++)
		if (balas[i] != NULL && balas[i]->estaActivo())
			balas[i]->dibujar();
}

void Juego::ejecutar()
{
	while (enEjecucion)
	{
		actualizar();
		dibujar();
		Sleep(50);
	}
	
	clrscr();
	
	gotoxy(30,10);
	
	if (jugador.getVidas() <= 0)
		cout << "GAME OVER";
	else
		cout << "GANASTE";
	
	gotoxy(30,12);
	cout << "Puntaje Final: " << puntaje;
	
	getch();
}
