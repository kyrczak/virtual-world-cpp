#pragma once
#include "Organzim.h"
#include <stdlib.h>
#include <string>

class Zwierze : public Organizm {
public:
	Zwierze(pair<int, int> pos, int sila, int inicjatywa, char znak, std::string nazwa, Swiat& swiat);
	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	virtual bool czyTenSamGatunek(Organizm* inny) = 0;
	pair <int, int> proponowanaPozycja(int kierunek);
	~Zwierze();
};