#pragma once
#pragma once
#include "Zwierze.h"

#define SILAOWCY 4
#define INIOWCY 4
#define ZNAKOWCY 'O'

class Owca : public Zwierze {
public:
	Owca(pair<int, int> pos, Swiat* swiat);
	~Owca();
};