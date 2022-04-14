#include "Zwierze.h"
#include <time.h>
#include <stdlib.h>

void Zwierze::akcja() {
	int kierunek = rand() % 4;
	pair <int,int> ruchy[4] = {
		{0,1},{0,-1},{1,0},{-1,0}
	};
	pair <int, int> proposedPosition = { (this->getPosX() + ruchy[kierunek].first),(this->getPosY() + ruchy[kierunek].second) };
	if (this->czySieMiesci(proposedPosition)) {
		for (Organizm* org : this->getSwiat()->getOrganizmy()) {
			if (proposedPosition.first == org->getPosX() && proposedPosition.second == org->getPosY()) {
				this->kolizja();
			}
		}
		this->setPosX(proposedPosition.first);
		this->setPosY(proposedPosition.second);
	}
	this->setWiek(this->getWiek() + 1);
}
void Zwierze::kolizja() {

}
Zwierze::Zwierze(pair<int, int> pos, int sila, int inicjatywa, char znak, Swiat* swiat) :Organizm(pos, sila, inicjatywa, znak, swiat) {

}
Zwierze::~Zwierze() {

}