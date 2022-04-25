#pragma once
#include "Roslina.h"

#define SILATRAWY 0
#define ZNAKTRAWY 't'
#define NAZWATRAWY "Trawa"

class Trawa : public Roslina {
public:
	Trawa(pair<int, int> pos, Swiat& swiat);
	void utworzOrganizm(pair<int, int> pole, Swiat& swiat) override;
	~Trawa();
};