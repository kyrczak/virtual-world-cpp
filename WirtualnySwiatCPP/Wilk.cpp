#include "Wilk.h"

Wilk::Wilk(pair<int,int> pos, Swiat& swiat) : Zwierze(pos,SILAWILKA,INIWILKA,ZNAKWILKA, NAZWAWILKA,swiat)  {

}
bool Wilk::czyTenSamGatunek(Organizm* inny) {
	return dynamic_cast<Wilk*>(inny) != nullptr;
}
void Wilk::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new Wilk(pole, swiat));
}
Wilk::~Wilk() {

}