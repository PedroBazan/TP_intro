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
		bool fuertes[11];
		
		for (int i = 0; i < 11; i++)
			fuertes[i] = false;
		
		int cantidadFuertes = 0;
		
		while (cantidadFuertes < 3)
		{
			int columnaRandom = rand() % 11;
			
			if (!fuertes[columnaRandom])
			{
				fuertes[columnaRandom] = true;
				cantidadFuertes++;
			}
		}
		
		for (int columna = 0; columna < 11; columna++)
		{
			int posX = inicioX + columna * separacionX;
			int posY = inicioY + fila * separacionY;
			
			if (fuertes[columna])
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
	// MOVERSE
	if (kbhit())
	{
		char tecla = getch();
		
		if (tecla == 'a' || tecla == 'A')
			jugador.moverIzquierda();
		
		if (tecla == 'd'|| tecla == 'D')
			jugador.moverDerecha();
		
		if (tecla == ' ')
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
					break;
				}
			}
		}
	}
	
	// VELOCIDAD ENEMIGOS
	contadorMovimiento++;
	
	if (contadorMovimiento % 5 == 0)
	{
		int maxX = 0;
		int minX = 3000;
		
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
		{
			tocarBorde = true;
		}
			
			if (tocarBorde)
			{
				direccionEnemigos *= -1;
				
				for (int i = 0; i < MAX_ENEMIGOS; i++)
				{
					if (enemigos[i] != NULL && enemigos[i]->estaActivo())
					{
						enemigos[i]->setPosicion(
												 enemigos[i]->getX(),
												 enemigos[i]->getY() + 2
												 );
					}
				}
			}
			else
			{
				for (int i = 0; i < MAX_ENEMIGOS; i++)
				{
					if (enemigos[i] != NULL && enemigos[i]->estaActivo())
					{
						enemigos[i]->setPosicion(
												 enemigos[i]->getX() + direccionEnemigos,
												 enemigos[i]->getY()
												 );
					}
				}
			}
	}
	
	// BALAS MOV
	for (int i = 0; i < MAX_BALAS; i++)
	{
		if (balas[i] != NULL && balas[i]->estaActivo())
			balas[i]->mover();
	}
	
	// COLISIONES
	for (int i = 0; i < MAX_BALAS; i++)
	{
		if (balas[i] != NULL && balas[i]->estaActivo())
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
					}
				}
			}
		}
	}
	
	if (jugador.getVidas() <= 0)
		enEjecucion = false;
	
	// GAME OVER
	for (int i = 0; i < MAX_ENEMIGOS; i++)
	{
		if (enemigos[i] != NULL && enemigos[i]->estaActivo())
		{
			if (enemigos[i]->getY() >= jugador.getY())
			{
				enEjecucion = false;
			}
		}
	}
	// GANASTE
	bool quedanEnemigos = false;
	
	for (int i = 0; i < MAX_ENEMIGOS; i++)
	{
		if (enemigos[i] != NULL && enemigos[i]->estaActivo())
		{
			quedanEnemigos = true;
			break;
		}
	}
	
	if (!quedanEnemigos)
	{
		enEjecucion = false;
	}
	
}

void Juego::dibujar()
{
	clrscr();
	
	jugador.dibujar();
	
	for (int i = 0; i < MAX_ENEMIGOS; i++)
	{
		if (enemigos[i] != NULL && enemigos[i]->estaActivo())
			enemigos[i]->dibujar();
	}
	
	for (int i = 0; i < MAX_BALAS; i++)
	{
		if (balas[i] != NULL && balas[i]->estaActivo())
			balas[i]->dibujar();
	}
}

void Juego::ejecutar()
{
	while (enEjecucion)
	{
		actualizar();
		dibujar();
		Sleep(50);
	}
	clrscr(); // BORRA PANTALLA
	//INFORMA SI GANASTE O PERDITE
	bool quedanEnemigos = false;
	
	for (int i = 0; i < MAX_ENEMIGOS; i++)
	{
		if (enemigos[i] != NULL && enemigos[i]->estaActivo())
		{
			quedanEnemigos = true;
			break;
		}
	}
	
	gotoxy(30, 10);
	
	if (quedanEnemigos)
		cout << "GAME OVER";
	else
		cout << "GANASTE";
	
	getch();
}

