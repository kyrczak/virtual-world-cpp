#include "Swiat.h"
#include <conio.h>
using namespace std;

Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc), rd(), mt(rd()), klawisz(0) {
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
	for (Organizm* org : this->getOrganizmy()) {
		if (org->getZywy()) {
			org->akcja();
		}
	}
	this->rysujSwiat();
	this->zwiekszTura();
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
void Swiat::setKlawisz(int klawisz) {
	this->klawisz = klawisz;
}
int Swiat::getKlawisz() {
	return this->klawisz;
}
int Swiat::getTura() {
	return this->ktoraTura;
}
void Swiat::zwiekszTura() {
	this->ktoraTura++;
}
vector <Organizm*> Swiat::getOrganizmy() {
	return this->organizmy; 
}
vector <string> Swiat::getAktywnosci() {
	return this->aktywnosci;
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
	for (string str : this->getAktywnosci()) {
		cout << str << endl;
	}
	cout << endl;
	/*for (Organizm* org : this->getOrganizmy()) {
		cout << org->getNazwa() << ": Inicjatywa - " << org->getInicjatywa() << " Sila - " << org->getSila() << " Wiek - " << org->getWiek() << endl;
	}*/
	this->aktywnosci.clear();
}
void Swiat::projektInfo() {
	cout << IMIE << " " << NAZWISKO << " Index: " << INDEX << endl;
	cout << "Wirtualny swiat C++	"<<"Tura: "<<this->getTura()<< endl;
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
void Swiat::pobierzKlawisz() {
	unsigned char ch1 = _getch();
	unsigned char ch2;
	switch (ch1) {
	case ARROWFUNC:
		ch2 = _getch();
		switch (ch2) {
		case KEY_UP:
			this->setKlawisz(UP);
			break;
		case KEY_DOWN:
			this->setKlawisz(DOWN);
			break;
		case KEY_LEFT:
			this->setKlawisz(LEFT);
			break;
		case KEY_RIGHT:
			this->setKlawisz(RIGHT);
			break;
		default:
			break;
		}
		break;
	case KEY_F:
		this->setKlawisz(KEY_F);
		break;
	case 'q':
		exit(0);
		break;
	default:
		break;
	}
}
char** Swiat::getPlansza() {
	return this->plansza;
}
default_random_engine& Swiat::getMt() {
	return this->mt;
}
void Swiat::dodajAktywnosc(string aktywnosc) {
	this->aktywnosci.push_back(aktywnosc);
}
Swiat::~Swiat() {
	for (int i = 0; i < wysokosc; i++) {
		delete[] this->plansza[i];
	}
	delete[] this->plansza;
}
