#ifndef OBJETOBASE_H
#define OBJETOBASE_H

class ObjetoBase {
protected:
	int x, y;
	bool activa;
	
public:
	ObjetoBase(int _x, int _y);
	virtual ~ObjetoBase();
	
	virtual void dibujar() = 0;
	virtual void mover() = 0;
	
	int getX();
	int getY();
	bool estaActiva();
	void desactivar();
};

#endif
