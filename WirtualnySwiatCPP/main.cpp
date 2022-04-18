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
	swiat.dodajOrganizm(new Wilk({ 0, 0 }, swiat));
	swiat.dodajOrganizm(new Owca({ 5,5 }, swiat));
	swiat.dodajOrganizm(new Wilk({ 0, 15 }, swiat));
	swiat.dodajOrganizm(new Wilk({ 10, 12 }, swiat));
	swiat.dodajOrganizm(new Owca({ 15,19 }, swiat));
	swiat.dodajOrganizm(new Owca({ 1,1 }, swiat));
	while (1) {
		swiat.wykonajTure();
		Sleep(125);
		system("CLS");
	}
	return 0;
}