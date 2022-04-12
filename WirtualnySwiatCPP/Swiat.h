#pragma once
#include <vector>
#include "Organzim.h"
class Organizm;

class Swiat {
private:
	int szerokosc;
	int wysokosc;
	std::vector <Organizm> organizmy;
public:
	Swiat(int szerokosc, int wysokosc);
	void wykonajTure();
	void rysujSwiat();
	int getSzerkosc();
	int getWysokosc();
	std::vector <Organizm> setOrganizmy();
	void dodajOrganizm(Organizm org);
};
