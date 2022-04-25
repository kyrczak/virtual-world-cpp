#include "Guarana.h"

Guarana::Guarana(std::pair<int, int> pos, Swiat& swiat) :Roslina(pos, SILAGUARANY, INIC, ZNAKGUARANY, NAZWAGUARANY, swiat) {

}
void Guarana::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new Guarana(pole, swiat));
}
bool Guarana::kolizja(Organizm* atakujacy) {
	atakujacy->setSila(atakujacy->getSila() + MOCGUARANY);
	this->getSwiat().dodajAktywnosc("Organizm " + atakujacy->getNazwa() + " zjadl guarane");
	return this->walka(atakujacy);
}
Guarana::~Guarana() {

}