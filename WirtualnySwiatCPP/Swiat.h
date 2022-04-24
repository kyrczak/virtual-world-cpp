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
#define KEY_F 102
#define ARROWFUNC 224
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
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
	int klawisz;
public:
	Swiat(int szerokosc, int wysokosc);
	void wykonajTure();
	void rysujSwiat();
	int getSzerkosc();
	int getWysokosc();
	void setKlawisz(int klawisz);
	int getKlawisz();
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
	void pobierzKlawisz();
	void dodajAktywnosc(string aktywnosc);
	~Swiat();
};
