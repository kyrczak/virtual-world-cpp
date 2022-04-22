#include "Zwierze.h"
#include <time.h>
#include <stdlib.h>
#include <random>

void Zwierze::akcja() {	
	this->ruch();
	this->setWiek(this->getWiek() + 1);
}
bool Zwierze::kolizja(Organizm* atakujacy) {
	return this->walka(atakujacy);
}
bool Zwierze::walka(Organizm* atakujacy) {
	if (this->getSila() < atakujacy->getSila()) {
		this->setZywy(false);
		return true;
	}
	else if (this->getSila() == atakujacy->getSila()) {
		this->setZywy(false);
		return true;
	}
	else {
		atakujacy->setZywy(false);
		return false;
	}
}
void Zwierze::ruch() {
	uniform_int_distribution<int> dist(0, 3);
	int kierunek = dist(this->getSwiat().getMt());
	pair <int, int> proposedPosition = this->proponowanaPozycja(kierunek);
	if (this->czySieMiesci(proposedPosition)) {
		Organizm* org = this->swiat.getOrganizm(proposedPosition);
		if (org == nullptr) {
			this->setPosX(proposedPosition.first);
			this->setPosY(proposedPosition.second);
		}
		else if (this->czyTenSamGatunek(org)) {
			//RozmnozSie
		}
		else {
			if (org->kolizja(this)) {
				this->setPosX(proposedPosition.first);
				this->setPosY(proposedPosition.second);
			}
		}
	}
}
Zwierze::Zwierze(pair<int, int> pos, int sila, int inicjatywa, char znak,std::string nazwa, Swiat& swiat) : Organizm(pos, sila, inicjatywa, znak,nazwa , swiat) {

}
Zwierze::~Zwierze() {

}