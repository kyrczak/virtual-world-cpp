#pragma once
#include "Roslina.h"

#define SILABARSZCZU 10
#define ZNAKBARSZCZU 'b'
#define NAZWABARSZCZU "Barszcz sosnowskiego"

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(std::pair<int, int> pos, Swiat& swiat);
	void utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) override;
	void akcja() override;
	void zabijDookola();
	bool kolizja(Organizm* atakujacy) override;
	bool czyZwierze(Organizm* org);
	~BarszczSosnowskiego();
};