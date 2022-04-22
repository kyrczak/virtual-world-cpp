#pragma once
#include <vector>
#include <random>
#include "Organzim.h"
#define IMIE "Patryk"
#define NAZWISKO "Korczak"
#define INDEX 188618
using namespace std;

class Organizm;

class Swiat {
private:
	int szerokosc;
	int wysokosc;
	vector <Organizm*> organizmy;
	char** plansza;
	random_device rd;
	default_random_engine mt;
public:
	Swiat(int szerokosc, int wysokosc);
	void wykonajTure();
	void rysujSwiat();
	int getSzerkosc();
	int getWysokosc();
	void setOrganizmy(vector <Organizm*> org);
	vector <Organizm*> getOrganizmy();
	Organizm* getOrganizm(pair <int,int> pozycja);
	char** getPlansza();
	default_random_engine& getMt();
	void dodajOrganizm(Organizm* org);
	void wyczyscPlansze();
	void rysujPlansze();
	void sortujOrganizmy();
	void rysujWektor();
	void projektInfo();
	~Swiat();
};
