#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
using namespace std;

int main() {
	srand(NULL);
	Swiat swiat(20, 20);
	swiat.dodajOrganizm(new Wilk({ 2, 4 }, &swiat));
	swiat.dodajOrganizm(new Wilk({ 0, 15 }, &swiat));
	swiat.dodajOrganizm(new Wilk({ 10, 12 }, &swiat));
	swiat.dodajOrganizm(new Owca({ 5,5 }, &swiat));
	while (1) {
		swiat.wykonajTure();
		Sleep(250);
		system("CLS");
	}
	return 0;
}