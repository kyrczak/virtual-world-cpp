#include "Trawa.h"

Trawa::Trawa(pair<int, int> pos, Swiat& swiat) :Roslina(pos, SILATRAWY, INIC, ZNAKTRAWY, NAZWATRAWY, swiat) {

}
void Trawa::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new Trawa(pole, swiat));
}
Trawa::~Trawa() {

}