#pragma once
#include "Roslina.h"

#define SILAGUARANY 0
#define MOCGUARANY	3
#define ZNAKGUARANY 'g'
#define NAZWAGUARANY "Guarana"

class Guarana : public Roslina {
public:
	Guarana(pair<int, int> pos, Swiat& swiat);
	void utworzOrganizm(pair<int, int> pole, Swiat& swiat) override;
	bool kolizja(Organizm* atakujacy) override;
	~Guarana();
};