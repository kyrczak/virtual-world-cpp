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
}
bool Zolw::kolizja(Organizm* atakujacy) {
	if (atakujacy->getSila() < 5) {
		return false;
	}
	else {
		return (this->walka(atakujacy));
	}
}
Zolw::~Zolw() {

}