#include <iostream>
#include <conio2.h>

using namespace std;

void mostrarPantallaInicio()
{
	clrscr();
	
	textcolor(WHITE);
	
	gotoxy(25,5);
	cout << "SPACE INVADERS PEDRO BAZAND ";
	
	gotoxy(20,8);
	cout << "Mover izquierda: A";
	
	gotoxy(20,9);
	cout << "Mover derecha: D";
	
	gotoxy(20,10);
	cout << "Disparar: ESPACIO";
	
	gotoxy(20,16);
	cout << "Presione una tecla para comenzar...";
	
	
	gotoxy(20,11);
	cout<<"maximo de balas 200";
	gotoxy(20,12);
	cout<<"vidas 3";
	
	
	getch();  // Espera a que se toque una tecla
}
