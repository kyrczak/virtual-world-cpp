#include <iostream>
#include "Swiat.h"

using namespace std;

Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc) {
	this->plansza = new char*[wysokosc];
	for (int i = 0; i < wysokosc; i++) {
		this->plansza[i] = new char[szerokosc];
	}
}
void Swiat::wykonajTure() {
	for (Organizm* org : this->getOrganizmy()) {
		org->akcja();
	}
	this->rysujSwiat();
}
void Swiat::rysujSwiat() {
	this->wyczyscPlansze();
	for (Organizm* org : this->getOrganizmy()) {
		org->rysowanie();
	}
	this->rysujPlansze();
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
}
char** Swiat::getPlansza() {
	return this->plansza;
}
Swiat::~Swiat() {
	for (int i = 0; i < wysokosc; i++) {
		delete[] this->plansza[i];
	}
	delete[] this->plansza;
}
