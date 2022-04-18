#include "Wilk.h"

Wilk::Wilk(pair<int,int> pos, Swiat& swiat) : Zwierze(pos,SILAWILKA,INIWILKA,ZNAKWILKA, NAZWAWILKA,swiat)  {

}
bool Wilk::czyTenSamGatunek(Organizm* inny) {
	return dynamic_cast<Wilk*>(inny) != nullptr;
}
Wilk::~Wilk() {

}