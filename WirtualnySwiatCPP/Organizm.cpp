#include <iostream>
#include "Organzim.h"
using namespace std;
void Organizm::rysowanie() {
    cout << this->znak;
}
int Organizm::getSila() {
    return this->sila;
}
int Organizm::getInicjatywa() {
    return this->inicjatywa;
}
int Organizm::getPosX() {
    return this->posX;
}
int Organizm::getPosY() {
    return this->posY;
}
bool Organizm::getZywy() {
    return this->jestZywy;
}
void Organizm::setPosX(int x) {
    this->posX = x;
}
void Organizm::setPosY(int y) {
    this->posY = y;
}
void Organizm::setZywy(bool jestZywy) {
    this->jestZywy = jestZywy;
}