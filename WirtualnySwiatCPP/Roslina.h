#pragma once
#include "Organzim.h"
#define ROZROST 50
#define INIC 0

class Roslina : public Organizm {
protected:
public:
	Roslina(pair<int, int> pos, int sila, int inicjatywa, char znak, std::string nazwa, Swiat& swiat);
	void akcja() override;
	bool kolizja(Organizm* atakujacy) override;
	bool czyTenSamGatunek(Organizm* inny) override;
	bool walka(Organizm* atakujacy);
	virtual void rozrost();
	~Roslina();
};