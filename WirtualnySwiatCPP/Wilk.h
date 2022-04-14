#pragma once
#include "Zwierze.h"

#define SILAWILKA 9
#define INIWILKA 5
#define ZNAKWILKA 'W'

class Wilk : public Zwierze {
public:
	Wilk(pair<int, int> pos, Swiat* swiat);
	~Wilk();
};