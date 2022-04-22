#include <iostream>
#include "Organzim.h"
using namespace std;
Organizm::Organizm(pair<int, int> pos, int sila, int inicjatywa, char znak, string nazwa, Swiat& swiat) : pos(pos), sila(sila), inicjatywa(inicjatywa), znak(znak), nazwa(nazwa), swiat(swiat) {

}
void Organizm::rysowanie() {
    this->swiat.getPlansza()[this->getPosX()][this->getPosY()] = this->getZnak();
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
string Organizm::getNazwa() {
    return this->nazwa;
}
Swiat& Organizm::getSwiat() {
    return this->swiat;
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
bool Organizm::czySieMiesci(pair <int, int> proposed) {
    return (proposed.first >= 0 && proposed.second >= 0 && proposed.first < this->swiat.getSzerkosc() && proposed.second < this->swiat.getWysokosc());
}
pair <int, int> Organizm::proponowanaPozycja(int kierunek) {
    pair <int, int> ruchy[4] = {
        {0,1},{0,-1},{1,0},{-1,0}
    };
    pair <int, int> pair = { (this->getPosX() + ruchy[kierunek].first),(this->getPosY() + ruchy[kierunek].second) };
    return pair;
}
Organizm::~Organizm() {

}