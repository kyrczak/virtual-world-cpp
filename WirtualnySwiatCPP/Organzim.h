#pragma once
#include "Swiat.h"
class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int wiek;
	int posX;
	int posY;
	bool jestZywy = 1;
	char znak = '?';
	Swiat* swiat;
public:
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie();
	int getSila();
	int getInicjatywa();
	int getPosX();
	int getPosY();
	bool getZywy();
	void setZywy(bool jestZywy);
	void setPosY(int y);
	void setPosX(int x);
};