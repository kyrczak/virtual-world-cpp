#pragma once
#include "Roslina.h"

#define SILAJAGODY 99
#define ZNAKJAGODY 'j'
#define NAZWAJAGODY "Wilcze jagody"

class WilczeJagody : public Roslina {
public:
	WilczeJagody(pair<int, int> pos, Swiat& swiat);
	void utworzOrganizm(pair<int, int> pole, Swiat& swiat) override;
	bool kolizja(Organizm* atakujacy) override;
	~WilczeJagody();
};