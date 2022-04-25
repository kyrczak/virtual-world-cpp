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
					this->getSwiat().dodajAktywnosc("Organizm " + org->getNazwa() + " zostalo zabite przez " + this->getNazwa());
					this->setPosX(proposedPosition.first);
					this->setPosY(proposedPosition.second);
				}
			}
		}
	}
	else if (klawisz == KEY_F) {
		if (!this->getUmiejetnosc() && this->getCzasOdnowienia()==0) {
			this->setUmiejetnosc(true);
			this->getSwiat().dodajAktywnosc("Czlowiek uruchomil umiejetnosc " + this->getNazwaUmiejetnosci());
		}
		else {
			this->getSwiat().dodajAktywnosc("Nie mozna uruchomic umiejtnosci");

		}
	}
	this->zarzadzanieCzasami();
}
bool Czlowiek::getUmiejetnosc() {
	return this->czyUmiejetnosc;
}
bool Czlowiek::kolizja(Organizm* atakujacy) {
	if (!this->getUmiejetnosc()) {
		return this->walka(atakujacy);
	}
	else {
		this->getSwiat().dodajAktywnosc("Tarcza Aluzra odbija atak "+atakujacy->getNazwa());
		vector<pair<int, int>> wolnePola = atakujacy->wolnePola();
		pair<int, int> wskPole = atakujacy->wybierzWolnePole(wolnePola);
		if (wskPole != pair<int, int> {ERRORPOLE, ERRORPOLE}) {
			atakujacy->setPosX(wskPole.first);
			atakujacy->setPosY(wskPole.second);
		}
		return false;
	}
}
int Czlowiek::getCzasOdnowienia() {
	return this->czasOdnowienia;
}
int Czlowiek::getCzasDzialania() {
	return this->czasDzialania;
}
std::string Czlowiek::getNazwaUmiejetnosci() {
	return this->umiejetnosc;
}
void Czlowiek::setUmiejetnosc(bool wartosc) {
	this->czyUmiejetnosc = wartosc;
}
void Czlowiek::setCzasOdnowienia(int time) {
	this->czasOdnowienia = time;
}
void Czlowiek::setCzasDzialania(int time) {
	this->czasDzialania = time;
}
void Czlowiek::zarzadzanieCzasami() {
	if (this->getUmiejetnosc()) {
		this->setCzasDzialania(this->getCzasDzialania() + 1);
		if (this->getCzasDzialania() == CZASDZI) {
			this->setCzasDzialania(0);
			this->setUmiejetnosc(false);
			this->setCzasOdnowienia(this->getCzasOdnowienia() + 1);
			this->getSwiat().dodajAktywnosc("Koniec umiejetnosci " + this->getNazwaUmiejetnosci());
		}
	}
	if (!this->getUmiejetnosc() && this->getCzasOdnowienia() > 0) {
		this->setCzasOdnowienia(this->getCzasOdnowienia() + 1);
		if (this->getCzasOdnowienia() == CZASODN) {
			this->setCzasOdnowienia(0);
		}
	}
}
bool Czlowiek::czyTenSamGatunek(Organizm* inny) {
	return false;
}
void Czlowiek::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	return;
}
Czlowiek::~Czlowiek() {

}