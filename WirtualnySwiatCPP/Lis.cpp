#include "Lis.h"
#include <random>

Lis::Lis(pair<int, int> pos, Swiat& swiat) : Zwierze(pos, SILALISA, INILISA, ZNAKLISA, NAZWALISA, swiat) {

}
bool Lis::czyTenSamGatunek(Organizm* inny) {
	return dynamic_cast<Lis*>(inny) != nullptr;
}
void Lis::ruch() {
	int kierunek = rand() % 4;
	pair <int, int> proposedPosition = this->proponowanaPozycja(kierunek);
	if (this->czySieMiesci(proposedPosition)) {
		Organizm* org = this->swiat.getOrganizm(proposedPosition);
		if (org == nullptr) {
			this->setPosX(proposedPosition.first);
			this->setPosY(proposedPosition.second);
		}
		else if (this->czyTenSamGatunek(org)) {
			this->rozmnazajSie(org);
		}
		else {
			if (org->getSila() < this->getSila()) {
				if (org->kolizja(this)) {
					this->getSwiat().dodajAktywnosc("Zwierze " + org->getNazwa() + " zostalo zabite przez " + this->getNazwa());
					this->setPosX(proposedPosition.first);
					this->setPosY(proposedPosition.second);
				}
			}
		}
	}
}
void Lis::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new Lis(pole, swiat));
}
Lis::~Lis() {

}