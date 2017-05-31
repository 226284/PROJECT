/*
 * Towar.cpp
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#include "Towar.h"

namespace std {

Towar::Towar(string nowa_nazwa, float nowa_wartosc, float nowa_masa) {
	nazwa = nowa_nazwa;
	wartosc = nowa_wartosc;
	masa = nowa_masa;
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

string Towar::get_nazwa(){
	return nazwa;
}

float Towar::get_wartosc(){
	return wartosc;
}

float Towar::get_masa(){
	return masa;
}

void Towar::wyswietl(){
	cout << "Nazwa: " << nazwa << " | ";
	cout << "Cena: " << wartosc << "zł" << " | ";
	cout << "Masa: " << masa << "g" << endl;
}

} /* namespace std */
