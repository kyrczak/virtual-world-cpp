#include <random>
#include "Antylopa.h"

Antylopa::Antylopa(pair<int, int> pos, Swiat& swiat) : Zwierze(pos, SILAANTYLOPY, INIANTYLOPY, ZNAKANTYLOP, NAZWAANTYLOPY, swiat) {

}
bool Antylopa::czyTenSamGatunek(Organizm* inny) {
	return dynamic_cast<Antylopa*>(inny) != nullptr;
}
pair<int,int> Antylopa::proponowanaPozycja(int kierunek) {
    pair <int, int> ruchy[8] = {
        {0,1},{0,-1},{1,0},{-1,0},{0,2},{0,-2},{2,0},{-2,0}
    };
    pair <int, int> pair = { (this->getPosX() + ruchy[kierunek].first),(this->getPosY() + ruchy[kierunek].second) };
    return pair;
}
void Antylopa::ruch() {
	uniform_int_distribution<int> dist(0, 7);
	int kierunek = dist(this->getSwiat().getMt());
	pair <int, int> proposedPosition = this->proponowanaPozycja(kierunek);
	if (this->czySieMiesci(proposedPosition)) {
		Organizm* org = this->swiat.getOrganizm(proposedPosition);
		if (org == nullptr) {
			this->setPosX(proposedPosition.first);
			this->setPosY(proposedPosition.second);
		}
		else if (this->czyTenSamGatunek(org)) {
			this->rozmnazajSie();
		}
		else {
			if (org->kolizja(this)) {
				this->getSwiat().dodajAktywnosc("Organizm " + org->getNazwa() + " zostalo zabite przez " + this->getNazwa());
				this->setPosX(proposedPosition.first);
				this->setPosY(proposedPosition.second);
			}
		}
	}
}
bool Antylopa::kolizja(Organizm* atakujacy) {
	uniform_int_distribution<int> dist(0, 1);
	bool atak = dist(this->getSwiat().getMt());
	if (atak) {
		return this->walka(atakujacy);
	}
	else {
		this->getSwiat().dodajAktywnosc("Antylopa ucieka od ataku");
		return false;
	}
}
void Antylopa::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new Antylopa(pole, swiat));
}
Antylopa::~Antylopa() {

}