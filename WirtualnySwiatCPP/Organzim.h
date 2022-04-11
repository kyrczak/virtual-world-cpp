#pragma once
#include "Swiat.h"
class Swiat;

class Organizm {
private:
	int sila;
	int inicjatywa;
	int posX;
	int posY;
	Swiat& swiat;
public:
	virtual void akcja();
	virtual void kolizja();
	virtual void rysowanie();
};