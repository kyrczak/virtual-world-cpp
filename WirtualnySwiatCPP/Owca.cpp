#include "Owca.h"

Owca::Owca(pair<int, int> pos, Swiat& swiat) :Zwierze(pos, SILAOWCY, INIOWCY, ZNAKOWCY, NAZWAOWCY, swiat) {

}
bool Owca::czyTenSamGatunek(Organizm* inny) {
	return dynamic_cast<Owca*>(inny) != nullptr;
}
Owca::~Owca() {

}