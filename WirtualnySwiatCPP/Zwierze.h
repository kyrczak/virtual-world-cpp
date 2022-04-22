#pragma once
#include "Organzim.h"
#include <stdlib.h>
#include <string>

class Zwierze : public Organizm {
public:
	Zwierze(pair<int, int> pos, int sila, int inicjatywa, char znak, std::string nazwa, Swiat& swiat);
	void akcja() override;
	bool kolizja(Organizm* atakujacy) override;
	bool walka(Organizm* atakujacy);
	virtual void ruch();
	virtual bool czyTenSamGatunek(Organizm* inny) = 0;
	void rozmnozSie(Organizm* partner);
	~Zwierze();
};