#pragma once
#include <vector>
#include "Organzim.h"
using namespace std;

class Organizm;

class Swiat {
private:
	int szerokosc;
	int wysokosc;
	vector <Organizm*> organizmy;
public:
	Swiat(int szerokosc, int wysokosc);
	void wykonajTure();
	void rysujSwiat();
	int getSzerkosc();
	int getWysokosc();
	void setOrganizmy(vector <Organizm*> org);
	vector <Organizm*> getOrganizmy();
	void dodajOrganizm(Organizm* org);
	~Swiat();
};
