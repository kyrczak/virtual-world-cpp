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
	bool jestZywy;
	char znak = '?';
	Swiat* swiat;
public:
	Organizm(Swiat* swt, int x, int y);
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie();
	~Organizm();
};