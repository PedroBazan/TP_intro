#include <iostream>
#include "ObjetoBase.h"
using namespace std;

ObjetoBase::ObjetoBase(int px, int py){
	x =px;
	y=py;
	activa=true;
}

ObjetoBase::~ObjetoBase(){
	
}
bool ObjetoBase::estaActivo()const {
	return activa;
}
void ObjetoBase::desactivar(){
	activo=false;
}
int ObjetoBase::getX(){
	return x;
}
int ObjetoBase::getY(){
	return  y;
}

