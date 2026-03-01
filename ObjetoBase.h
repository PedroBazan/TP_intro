#ifndef OBJETOBASE_H
#define OBJETOBASE_H

class ObjetoBase {
private:
	int x;
	int y;
	bool activa;
	
public:
	ObjetoBase(int px, int py);
	
	int getX() const;
	int getY() const;
	
	void setPosicion(int px, int py);
	
	bool estaActivo() const;
	void desactivar();
	
	virtual void dibujar() = 0;
	virtual void mover() = 0;
};

#endif
