#include <random>
#include "Zolw.h"

Zolw::Zolw(pair<int, int> pos, Swiat& swiat) : Zwierze(pos, SILAZOLWIA, INIZOLWIA, ZNAKZOLWIA, NAZWAZOLWIA, swiat) {

}
bool Zolw::czyTenSamGatunek(Organizm* inny) {
	return dynamic_cast<Zolw*>(inny) != nullptr;
}
void Zolw::ruch() {
	uniform_int_distribution<int> dist(0, 15);
	int kierunek = dist(this->getSwiat().getMt());
	if (kierunek < 4) {
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
}
bool Zolw::kolizja(Organizm* atakujacy) {
	if (atakujacy->getSila() < 5) {
		this->getSwiat().dodajAktywnosc("Zolw odbil atak " + atakujacy->getNazwa());
		return false;
	}
	else {
		return (this->walka(atakujacy));
	}
}
void Zolw::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new Zolw(pole, swiat));
}
Zolw::~Zolw() {

}