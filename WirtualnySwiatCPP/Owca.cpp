#include "Owca.h"

Owca::Owca(pair<int, int> pos, Swiat& swiat) :Zwierze(pos, SILAOWCY, INIOWCY, ZNAKOWCY, NAZWAOWCY, swiat) {

}
bool Owca::czyTenSamGatunek(Organizm* inny) {
	return dynamic_cast<Owca*>(inny) != nullptr;
}
void Owca::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new Owca(pole, swiat));
}
Owca::~Owca() {

}