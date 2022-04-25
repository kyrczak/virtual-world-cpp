#include "WilczeJagody.h"
WilczeJagody::WilczeJagody(std::pair<int, int> pos, Swiat& swiat) : Roslina(pos, SILAJAGODY, INIC, ZNAKJAGODY, NAZWAJAGODY, swiat) {

}
void WilczeJagody::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new WilczeJagody(pole, swiat));
}
bool WilczeJagody::kolizja(Organizm* atakujacy) {
	atakujacy->setZywy(false);
	this->getSwiat().dodajAktywnosc("Wilcze jagody zabily " + atakujacy->getNazwa());
	return this->walka(atakujacy);
}
WilczeJagody::~WilczeJagody() {

}