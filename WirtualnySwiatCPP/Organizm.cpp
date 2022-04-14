#include <iostream>
#include "Organzim.h"
using namespace std;
Organizm::Organizm(pair<int, int> pos, int sila, int inicjatywa, char znak, Swiat* swiat) : pos(pos), sila(sila), inicjatywa(inicjatywa), znak(znak), swiat(swiat) {

}
void Organizm::rysowanie() {
    this->getSwiat()->getPlansza()[this->getPosX()][this->getPosY()] = this->getZnak();
}
int Organizm::getSila() {
    return this->sila;
}
int Organizm::getInicjatywa() {
    return this->inicjatywa;
}
int Organizm::getPosX() {
    return this->pos.first;
}
int Organizm::getPosY() {
    return this->pos.second;
}
int Organizm::getWiek() {
    return this->wiek;
}
bool Organizm::getZywy() {
    return this->jestZywy;
}
char Organizm::getZnak() {
    return this->znak;
}
void Organizm::setPosX(int x) {
    this->pos.first = x;
}
void Organizm::setPosY(int y) {
    this->pos.second = y;
}
void Organizm::setZywy(bool jestZywy) {
    this->jestZywy = jestZywy;
}
void Organizm::setWiek(int wiek) {
    this->wiek = wiek;
}
Swiat* Organizm::getSwiat() {
    return this->swiat;
}
bool Organizm::czySieMiesci(pair <int, int> proposed) {
    return (proposed.first >= 0 && proposed.second >= 0 && proposed.first < this->getSwiat()->getSzerkosc() && proposed.second < this->getSwiat()->getWysokosc());
}
Organizm::~Organizm() {

}