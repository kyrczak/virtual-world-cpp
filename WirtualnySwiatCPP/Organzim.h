#pragma once
#include "Swiat.h"

class Organizm {
private:
	int sila;
	int inicjatywa;
	int posX;
	int posY;
	Swiat& swiat;
public:
	void akcja();
	void kolizja();
	void rysowanie();
};