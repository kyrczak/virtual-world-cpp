#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <functional>
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
	vector <string> aktywnosci;
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
	vector <string> getAktywnosci();
	Organizm* getOrganizm(pair <int,int> pozycja);
	char** getPlansza();
	default_random_engine& getMt();
	void dodajOrganizm(Organizm* org);
	void wyczyscPlansze();
	void rysujPlansze();
	void sortujOrganizmy();
	void rysujWektor();
	void projektInfo();
	void dodajAktywnosc(string aktywnosc);
	~Swiat();
};
