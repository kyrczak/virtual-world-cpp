#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Czlowiek.h"
using namespace std;

int main() {
	Swiat swiat(20, 20);
	swiat.dodajOrganizm(new Wilk({ 0, 0 }, swiat));
	swiat.dodajOrganizm(new Wilk({ 1, 0 }, swiat));
	swiat.dodajOrganizm(new Wilk({ 2, 0 }, swiat));
	swiat.dodajOrganizm(new Wilk({ 11,0 }, swiat));
	swiat.dodajOrganizm(new Lis({ 10, 12 }, swiat));
	swiat.dodajOrganizm(new Owca({ 5,6 }, swiat));
	swiat.dodajOrganizm(new Owca({ 3,14 }, swiat));
	swiat.dodajOrganizm(new Zolw({ 3,15 }, swiat));
	swiat.dodajOrganizm(new Zolw({ 8,15 }, swiat));
	swiat.dodajOrganizm(new Antylopa({ 6,10 }, swiat));
	swiat.dodajOrganizm(new Antylopa({ 3,9 }, swiat));
	swiat.dodajOrganizm(new Czlowiek({ 3,3 }, swiat));
	while (1) {
		swiat.wykonajTure();
		swiat.pobierzKlawisz();
		system("CLS");
	}
	return 0;
}