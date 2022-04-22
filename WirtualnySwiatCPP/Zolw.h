#pragma once
#include "Zwierze.h"

#define SILAZOLWIA 2
#define INIZOLWIA 1
#define ZNAKZOLWIA 'Z'
#define NAZWAZOLWIA "Zolw"

class Zolw : public Zwierze {
public:
	Zolw(pair<int, int> pos, Swiat& swiat);
	void ruch() override;
	bool kolizja(Organizm* atakujacy) override;
	bool czyTenSamGatunek(Organizm* inny) override;
	~Zolw();
};