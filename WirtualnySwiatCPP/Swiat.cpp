#include <iostream>
#include "Swiat.h"

using namespace std;

Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc) {

}
void Swiat::wykonajTure() {
	for (Organizm* org : this->getOrganizmy()) {
		org->akcja();
	}
}
void Swiat::rysujSwiat() {

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

}
Swiat::~Swiat() {
}
