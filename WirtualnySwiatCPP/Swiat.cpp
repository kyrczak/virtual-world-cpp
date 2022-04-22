#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <functional>
#include "Swiat.h"

using namespace std;

Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc), rd(), mt(rd()) {
	this->plansza = new char*[wysokosc];
	for (int i = 0; i < wysokosc; i++) {
		this->plansza[i] = new char[szerokosc];
	}
}
bool porownajOrganizmy(Organizm* lewy, Organizm* prawy) {
	if (lewy->getInicjatywa() != prawy->getInicjatywa()) {
		return (lewy->getInicjatywa() > prawy->getInicjatywa());
	}
	else {
		return (lewy->getWiek() > prawy->getWiek());
	}
}
void Swiat::wykonajTure() {
	this->sortujOrganizmy();
	this->rysujSwiat();
	for (Organizm* org : this->getOrganizmy()) {
		if (org->getZywy()) {
			org->akcja();
		}
	}
}
void Swiat::rysujSwiat() {
	this->wyczyscPlansze();
	for (Organizm* org : this->getOrganizmy()) {
		if (org->getZywy()) {
			org->rysowanie();
		}
	}
	this->projektInfo();
	this->rysujPlansze();
	this->rysujWektor();
}
int Swiat::getSzerkosc() {
	return szerokosc;
}
int Swiat::getWysokosc() {
	return wysokosc;
}
void Swiat::setOrganizmy(vector <Organizm*> vec) {
	this->organizmy = vec;
}
vector <Organizm*> Swiat::getOrganizmy() {
	return this->organizmy; 
}
Organizm* Swiat::getOrganizm(pair <int, int> pozycja) {
	Organizm* inny = nullptr;
	for (Organizm* org : this->getOrganizmy()) {
		if (org->getPosX() == pozycja.first && org->getPosY() == pozycja.second) {
			inny = org;
		}
	}
	return inny;
}
void Swiat::dodajOrganizm(Organizm* org) {
	this->organizmy.push_back(org);
}
void Swiat::wyczyscPlansze() {
	for (int i = 0; i < this->getWysokosc(); i++) {
		for (int j = 0; j < this->getSzerkosc(); j++) {
			this->getPlansza()[i][j] = '.';
		}
	}
}
void Swiat::rysujPlansze() {
	for (int i = 0; i < this->getWysokosc(); i++) {
		for (int j = 0; j < this->getSzerkosc(); j++) {
			cout << this->getPlansza()[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void Swiat::rysujWektor() {
	for (Organizm* org : this->getOrganizmy()) {
		cout << org->getNazwa() << ": Inicjatywa - " << org->getInicjatywa() << " Sila - " << org->getSila() << " Wiek - " << org->getWiek() << endl;
	}
}
void Swiat::projektInfo() {
	cout << IMIE << " " << NAZWISKO << " Index: " << INDEX << endl;
	cout << "Wirtualny swiat C++" << endl;
	cout << endl;
}
void Swiat::sortujOrganizmy() {
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (!(this->organizmy[i]->getZywy())) {
			swap(this->organizmy[i], this->organizmy.back());
			this->organizmy.pop_back();
		}
	}
	sort(this->organizmy.begin(), this->organizmy.end(), porownajOrganizmy);
}
char** Swiat::getPlansza() {
	return this->plansza;
}
default_random_engine& Swiat::getMt() {
	return this->mt;
}
Swiat::~Swiat() {
	for (int i = 0; i < wysokosc; i++) {
		delete[] this->plansza[i];
	}
	delete[] this->plansza;
}
