#pragma once
#include "Organzim.h"

class Zwierze : public Organizm {
public:
	Zwierze(pair<int, int> pos, int sila, int inicjatywa, char znak, Swiat* swiat);
	void akcja() override;
	void kolizja() override;
	~Zwierze();
};