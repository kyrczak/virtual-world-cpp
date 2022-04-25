#include "Mlecz.h"

Mlecz::Mlecz(std::pair<int, int> pos, Swiat& swiat) :Roslina(pos, SILAMLECZA, INIC, ZNAKMLECZA, NAZWAMLECZA, swiat) {

}
void Mlecz::utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) {
	this->getSwiat().dodajOrganizm(new Mlecz(pole, swiat));
}
Mlecz::~Mlecz() {

}
void Mlecz::rozrost() {
	for (int i = 0; i < 3; i++) {
		std::uniform_int_distribution<int> dist(1, ROZROST);
		int szansa = dist(this->getSwiat().getMt());
		if (szansa == 1) {
			this->rozmnazajSie();
		}
	}
}