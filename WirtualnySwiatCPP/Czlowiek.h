#pragma once
#pragma once
#include "Zwierze.h"

#define SILACZL 5
#define INICZL 4
#define ZNAKCZL 'C'
#define NAZWACZL "Czlowiek"

class Czlowiek : public Zwierze {
protected:
	bool czyUmiejetnosc = false;
	int czasOdnowienia = 0;
public:
	Czlowiek(pair<int, int> pos, Swiat& swiat);
	void ruch() override;
	//bool kolizja(Organizm* atakujacy) override;
	bool czyTenSamGatunek(Organizm* inny) override;
	void utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) override;
	bool getUmiejetnosc();
	void setUmiejetnosc(bool wartosc);
	int getCzasOdnowienia();
	void setCzasOdnowienia(int time);
	~Czlowiek();
};