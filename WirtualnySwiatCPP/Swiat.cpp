#include <iostream>
#include "Swiat.h"

using namespace std;

Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc) {

}
void Swiat::wykonajTure() {
	for(Organizm org :)
}
void Swiat::rysujSwiat() {
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			cout << '*';
		}
		cout << endl;
	}
}
int Swiat::getSzerkosc() {
	return szerokosc;
}
int Swiat::getWysokosc() {
	return wysokosc;
}