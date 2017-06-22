/*
 * Towar.cpp
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#include "Towar.h"

namespace std {

Towar::Towar(string nowa_nazwa, float nowa_wartosc, float nowa_masa, int nowy_numer) {
	nazwa = nowa_nazwa;
	wartosc = nowa_wartosc;
	masa = nowa_masa;
	numer = nowy_numer;
}

Towar::~Towar() {
	// TODO Auto-generated destructor stub
}

void Towar::set_nazwa(string nowa_nazwa){
	nazwa = nowa_nazwa;
}

void Towar::set_wartosc(float nowa_wartosc){
	wartosc = nowa_wartosc;
}

void Towar::set_masa(float nowa_masa){
	masa = nowa_masa;
}

void Towar::nadaj(string nowa_nazwa, float nowa_wartosc, float nowa_masa, int nowy_numer){
	nazwa = nowa_nazwa;
	masa = nowa_masa;
	wartosc = nowa_wartosc;
	numer = nowy_numer;
}

string Towar::get_nazwa(){
	return nazwa;
}

int Towar::get_wartosc(){
	return wartosc;
}

int Towar::get_masa(){
	return masa;
}

int Towar::get_numer(){
	return numer;
}

void Towar::wyswietl(){
	cout << "Nazwa: " << nazwa << " | ";
	cout << "Cena: " << wartosc << "zł" << " | ";
	cout << "Masa: " << masa << "g" << " | ";
	cout << "Numer przedmiotu: " << numer<< endl;
}

} /* namespace std */
