#pragma once
#include "Roslina.h"

#define SILAMLECZA 0
#define ZNAKMLECZA 'm'
#define NAZWAMLECZA "Mlecz"

class Mlecz : public Roslina {
public:
	Mlecz(pair<int, int> pos, Swiat& swiat);
	void utworzOrganizm(pair<int, int> pole, Swiat& swiat) override;
	void rozrost() override;
	~Mlecz();
};