#pragma once
#include "Zwierze.h"

#define SILAANTYLOPY 4
#define INIANTYLOPY 4
#define ZNAKANTYLOP 'A'
#define NAZWAANTYLOPY "Antylopa"

class Antylopa : public Zwierze {
public:
	Antylopa(pair<int, int> pos, Swiat& swiat);
	void ruch() override;
	pair<int, int> proponowanaPozycja(int kierunek) override;
	bool czyTenSamGatunek(Organizm* inny) override;
	~Antylopa();
};