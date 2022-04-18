#pragma once
#include "Zwierze.h"

#define SILAWILKA 9
#define INIWILKA 5
#define ZNAKWILKA 'W'
#define NAZWAWILKA "Wilk"

class Wilk : public Zwierze {
public:
	Wilk(pair<int, int> pos, Swiat& swiat);
	bool czyTenSamGatunek(Organizm* inny) override;
	~Wilk();
};