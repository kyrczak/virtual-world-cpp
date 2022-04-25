#include "Roslina.h"

Roslina::Roslina(pair<int, int> pos, int sila, int inicjatywa, char znak, std::string nazwa, Swiat& swiat) : Organizm(pos, sila, inicjatywa, znak, nazwa, swiat) {

}
void Roslina::akcja() {
	this->rozrost();
	this->setWiek(this->getWiek() + 1);
}
void Roslina::rozrost() {
	uniform_int_distribution<int> dist(1, ROZROST);
	int szansa = dist(this->getSwiat().getMt());
	if (szansa == 1) {
		this->rozmnazajSie();
	}
}
bool Roslina::czyTenSamGatunek(Organizm* inny) {
	return false;
}
bool Roslina::kolizja(Organizm * atakujacy) {
	return this->walka(atakujacy);
}
bool Roslina::walka(Organizm* atakujacy) {
	this->setZywy(false);
	return true;
}
Roslina::~Roslina() {

}