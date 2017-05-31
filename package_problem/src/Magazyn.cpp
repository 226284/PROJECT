/*
 * Magazyn.cpp
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#include "Magazyn.h"

namespace std {

Magazyn::Magazyn(int rozmiar) {
	tab = new Towar[rozmiar];
	ROZMIAR = rozmiar;
}

Magazyn::~Magazyn() {
	delete[] tab;
}

void Magazyn::dodaj(Towar przedmiot, int pole) {
	if (pole >= 0 && pole < ROZMIAR) {
		tab[pole] = przedmiot;
	}
	else {
		cout << "Nieprawidłowa wartośc pola";
	}
}

void Magazyn::usun(int pole) {
	Towar tmp;

	if (pole >= 0 && pole < ROZMIAR) {
		tab[pole] = tmp;
	}
	else {
		cout << "Nieprawidłowa wartość pola";
	}
}

void Magazyn::wyswietl() {
	int i;

	for (i = 0; i < ROZMIAR; i++) {
		cout << i+1 << ". ";
		tab[i].wyswietl();
	}
}

} /* namespace std */
