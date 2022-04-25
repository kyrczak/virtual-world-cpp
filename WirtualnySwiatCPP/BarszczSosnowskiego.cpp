#include "BarszczSosnowskiego.h"
#include "Zwierze.h"

BarszczSosnowskiego::BarszczSosnowskiego(std::pair<int, int> pos, Swiat& swiat) : Roslina(pos, SILABARSZCZU, INIC, ZNAKBARSZCZU, NAZWABARSZCZU, swiat) {

}
void BarszczSosnowskiego::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new BarszczSosnowskiego(pole, swiat));
}
void BarszczSosnowskiego::akcja() {
	this->zabijDookola();
	this->rozrost();
	this->setWiek(this->getWiek() + 1);
}
void BarszczSosnowskiego::zabijDookola() {
	pair<int, int> polaDookola[4] = {
		{this->getPosX(),this->getPosY() + 1},
		{this->getPosX(),this->getPosY() - 1},
		{this->getPosX() + 1,this->getPosY()},
		{this->getPosX() - 1,this->getPosY()}
	};
	for(int i = 0; i < 4; i++) {
		if (this->getSwiat().getOrganizm(polaDookola[i]) != nullptr && this->czySieMiesci(polaDookola[i])) {
			if (this->czyZwierze(this->getSwiat().getOrganizm(polaDookola[i]))) {
				this->getSwiat().getOrganizm(polaDookola[i])->setZywy(false);
				this->getSwiat().dodajAktywnosc("Barszcz sosnowskiego zabil " + this->getSwiat().getOrganizm(polaDookola[i])->getNazwa());
			}
		}
	}
}
bool BarszczSosnowskiego::kolizja(Organizm* atakujacy) {
	atakujacy->setZywy(false);
	return this->walka(atakujacy);
}
bool BarszczSosnowskiego::czyZwierze(Organizm* org) {
	return dynamic_cast<Zwierze*> (org) != nullptr;
}
BarszczSosnowskiego::~BarszczSosnowskiego() {

}