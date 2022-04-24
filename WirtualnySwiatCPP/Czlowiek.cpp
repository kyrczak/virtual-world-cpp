#include "Czlowiek.h"

Czlowiek::Czlowiek(pair<int, int> pos, Swiat& swiat) : Zwierze(pos, SILACZL, INICZL, ZNAKCZL, NAZWACZL, swiat) {

}
void Czlowiek::ruch() {
	int klawisz = this->getSwiat().getKlawisz();
	if (klawisz != 0 && klawisz != KEY_F) {
		pair <int, int> proposedPosition = this->proponowanaPozycja(klawisz-1);
		if (this->czySieMiesci(proposedPosition)) {
			Organizm* org = this->swiat.getOrganizm(proposedPosition);
			if (org == nullptr) {
				this->setPosX(proposedPosition.first);
				this->setPosY(proposedPosition.second);
			}
			else {
				if (org->kolizja(this)) {
					this->getSwiat().dodajAktywnosc("Zwierze " + org->getNazwa() + " zostalo zabite przez " + this->getNazwa());
					this->setPosX(proposedPosition.first);
					this->setPosY(proposedPosition.second);
				}
			}
		}
	}
	else if (klawisz == KEY_F) {
		//OdpalTarczeAlzura
	}
	
}
//Dokoncz wszystkie setery i gettery
bool Czlowiek::czyTenSamGatunek(Organizm* inny) {
	return false;
}
void Czlowiek::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	return;
}
Czlowiek::~Czlowiek() {

}