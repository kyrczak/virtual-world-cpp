#pragma once
#include "Organzim.h"

class Zwierze : public Organizm {
protected:

public:
	void akcja() override;
	void kolizja() override;
};