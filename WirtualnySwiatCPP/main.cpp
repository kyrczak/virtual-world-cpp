
#include "Imports.h"
using namespace std;

int main() {
	Swiat swiat(20, 20);
	swiat.dodajOrganizm(new Wilk({ 0, 0 }, swiat));
	swiat.dodajOrganizm(new Wilk({ 11,0 }, swiat));
	swiat.dodajOrganizm(new Lis({ 10, 12 }, swiat));
	swiat.dodajOrganizm(new Owca({ 5,6 }, swiat));
	swiat.dodajOrganizm(new Owca({ 3,14 }, swiat));
	swiat.dodajOrganizm(new Zolw({ 3,15 }, swiat));
	swiat.dodajOrganizm(new Zolw({ 8,15 }, swiat));
	swiat.dodajOrganizm(new Antylopa({ 6,10 }, swiat));
	swiat.dodajOrganizm(new Antylopa({ 3,9 }, swiat));
	swiat.dodajOrganizm(new Trawa({ 2,3 }, swiat));
	swiat.dodajOrganizm(new Trawa({ 5,3 }, swiat));
	swiat.dodajOrganizm(new Trawa({ 2,4 }, swiat));
	swiat.dodajOrganizm(new Czlowiek({ 13,3 }, swiat));
	swiat.dodajOrganizm(new Mlecz({ 19,0 }, swiat));
	swiat.dodajOrganizm(new Guarana({ 19,19 }, swiat));
	swiat.dodajOrganizm(new WilczeJagody({ 10,10 }, swiat));
	swiat.dodajOrganizm(new WilczeJagody({ 10,11 }, swiat));
	swiat.dodajOrganizm(new BarszczSosnowskiego({ 14,18 }, swiat));
	while (1) {
		swiat.wykonajTure();
		swiat.pobierzKlawisz();
		system("CLS");
	}
	return 0;
}