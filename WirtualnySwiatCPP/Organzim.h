#pragma once
#include "Swiat.h"
class Swiat;

class Organizm {
protected:
	std::pair <int, int> pos;
	int sila;
	int inicjatywa;
	int wiek = 0;
	bool jestZywy = 1;
	char znak;
	Swiat* swiat;
public:
	Organizm(std::pair<int,int> pos, int sila, int inicjatywa, char znak, Swiat* swiat);
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	void rysowanie();
	int getSila();
	int getInicjatywa();
	int getPosX();
	int getPosY();
	int getWiek();
	bool getZywy();
	char getZnak();
	void setZywy(bool jestZywy);
	void setPosY(int y);
	void setPosX(int x);
	void setWiek(int wiek);
	bool czySieMiesci(std::pair <int, int> proposed);
	Swiat* getSwiat();
	~Organizm();
};