#pragma once
#include "Zwierze.h"

#define SILALISA 3
#define INILISA 7
#define ZNAKLISA 'L'
#define NAZWALISA "Lis"

class Lis : public Zwierze {
public:
	Lis(pair<int, int> pos, Swiat& swiat);
	void ruch() override;
	bool czyTenSamGatunek(Organizm* inny) override;
	void utworzOrganizm(pair<int, int> pole, Swiat& swiat) override;
	~Lis();
};