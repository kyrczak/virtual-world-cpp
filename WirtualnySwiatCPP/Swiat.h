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
	char** plansza;
public:
	Swiat(int szerokosc, int wysokosc);
	void wykonajTure();
	void rysujSwiat();
	int getSzerkosc();
	int getWysokosc();
	void setOrganizmy(vector <Organizm*> org);
	vector <Organizm*> getOrganizmy();
	char** getPlansza();
	void dodajOrganizm(Organizm* org);
	void wyczyscPlansze();
	void rysujPlansze();
	~Swiat();
};
