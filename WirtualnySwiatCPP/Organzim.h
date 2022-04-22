#pragma once
#include "Swiat.h"
#include <string>
#include <cstdlib>
class Swiat;

class Organizm {
protected:
	std::pair <int, int> pos;
	int sila;
	int inicjatywa;
	int wiek = 0;
	bool jestZywy = 1;
	char znak;
	std::string nazwa;
	Swiat& swiat;
public:
	Organizm(std::pair<int,int> pos, int sila, int inicjatywa, char znak, std::string nazwa, Swiat& swiat);
	virtual void akcja() = 0;
	virtual bool kolizja(Organizm* atakujacy) = 0;
	virtual bool czyTenSamGatunek(Organizm* inny) = 0;
	virtual std::pair <int, int> proponowanaPozycja(int kierunek);
	void rysowanie();
	int getSila();
	int getInicjatywa();
	int getPosX();
	int getPosY();
	int getWiek();
	bool getZywy();
	char getZnak();
	Swiat& getSwiat();
	std::string getNazwa();
	void setZywy(bool jestZywy);
	void setPosY(int y);
	void setPosX(int x);
	void setWiek(int wiek);
	bool czySieMiesci(std::pair <int, int> proposed);
	~Organizm();
};