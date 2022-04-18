#include "Zwierze.h"
#include <time.h>
#include <stdlib.h>

void Zwierze::akcja() {	
	int kierunek = rand() % 4;
	bool ruch = true;	
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
			org->kolizja(this);
		}
	}
	this->setWiek(this->getWiek() + 1);
}
void Zwierze::kolizja(Organizm* atakujacy) {
	if (this->getSila() < atakujacy->getSila() ){
		this->setZywy(false);
	}
	else if (this->getSila() == atakujacy->getSila()) {
		this->setZywy(false);
	}
}
pair <int, int> Zwierze::proponowanaPozycja(int kierunek) {	
	pair <int, int> ruchy[4] = {
		{0,1},{0,-1},{1,0},{-1,0}
	};
	pair <int, int> pair = { (this->getPosX() + ruchy[kierunek].first),(this->getPosY() + ruchy[kierunek].second) };
	return pair;
}
Zwierze::Zwierze(pair<int, int> pos, int sila, int inicjatywa, char znak,std::string nazwa, Swiat& swiat) : Organizm(pos, sila, inicjatywa, znak,nazwa , swiat) {

}
Zwierze::~Zwierze() {

}