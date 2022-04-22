#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Lis.h"
#include "Antylopa.h"
using namespace std;

int main() {
	Swiat swiat(20, 20);
	swiat.dodajOrganizm(new Wilk({ 0, 0 }, swiat));
	swiat.dodajOrganizm(new Owca({ 5,5 }, swiat));
	swiat.dodajOrganizm(new Lis({ 10, 12 }, swiat));
	swiat.dodajOrganizm(new Owca({ 15,19 }, swiat));
	swiat.dodajOrganizm(new Owca({ 3,14 }, swiat));
	swiat.dodajOrganizm(new Zolw({ 3,15 }, swiat));
	swiat.dodajOrganizm(new Antylopa({ 6,10 }, swiat));
	while (1) {
		swiat.wykonajTure();
		Sleep(350);
		system("CLS");
	}
	return 0;
}