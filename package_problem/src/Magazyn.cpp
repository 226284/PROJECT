/*
 * Magazyn.cpp
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#include "Magazyn.h"
#include <algorithm> 

namespace std {

Magazyn::Magazyn(int rozmiar) {
	tab = new Towar[rozmiar];
	ROZMIAR = rozmiar;
	towar_ilosc = 0;
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
		cout << i + 1 << ". ";
		tab[i].wyswietl();
	}
}

void Magazyn::sort1() {
	float* plecak = new float[ROZMIAR];

	float temp = 0;
	int pole = 0;
	cout << "zaczynaM" << endl;
	for (int j = 0; j < ROZMIAR; j++) {
		for (int i = 0; i < ROZMIAR; i++) {
			if (temp < tab[i].get_wartosc()) {
				temp = tab[i].get_wartosc();
				pole = i;
			}
		}
		plecak[j] = temp;
		this->usun(pole);
		temp = 0;
	}

	cout << "po wszystkin" << endl;
	this->wyswietl();
	for (int i = 0; i < ROZMIAR; i++) {
		cout << plecak[i] << endl;
	}
}

void Magazyn::sort2() {
	float* plecak = new float[ROZMIAR];

	float temp_kasa = 0;
	float temp_masa = 10000;
	int pole = 0;
	cout << "zaczynaM" << endl;
	for (int j = 0; j < ROZMIAR; j++) {
		for (int i = 0; i < ROZMIAR; i++) {
			if (temp_masa > tab[i].get_masa()) {
				temp_masa = tab[i].get_masa();
				temp_kasa = tab[i].get_wartosc();
				pole = i;
				cout << "jest wieksze" << i << endl;
			}
		}

		cout << j << endl;
		plecak[j] = temp_kasa;
		this->usun(pole);
		temp_masa = 10000;
		this->wyswietl();
	}

	cout << "po wszystkim" << endl;
	this->wyswietl();
	for (int i = 0; i < ROZMIAR; i++) {
		cout << plecak[i] << endl;
	}

}
void Magazyn::sort3() {
	float* plecak = new float[ROZMIAR];

	float temp = 0;
	float temp2 = 0;
	int pole = 0;
	cout << "zaczynaM" << endl;
	for (int j = 0; j < ROZMIAR; j++) {
		for (int i = 0; i < ROZMIAR; i++) {
			if (temp < tab[i].get_wartosc() / tab[i].get_masa()) {
				cout << tab[i].get_wartosc() / tab[i].get_masa() << endl;
				temp = tab[i].get_wartosc() / tab[i].get_masa();
				temp2 = tab[i].get_wartosc();
				pole = i;
			}
		}
		plecak[j] = temp2;
		this->usun(pole);
		temp = 0;
	}

	cout << "po wszystkin" << endl;
	this->wyswietl();
	for (int i = 0; i < ROZMIAR; i++) {
		cout << plecak[i] << endl;
	}

}

int Magazyn::max(int liczba1, int liczba2) {
	if (liczba1 > liczba2) {
		return liczba1;
	}
	return liczba2;
}

int Magazyn::knapsack(int wielkosc) {
	int i, j; // pomocnicze liczniki
	int tmp[ROZMIAR + 1][wielkosc + 1]; // tablica pomocnicza do przechowywania danych

	for (i = 0; i <= ROZMIAR; i++) {
		for (j = 0; j <= wielkosc; j++) {
			if (i == 0 || j == 0) { // zerowe indeksy wypełniamy zerami
				tmp[i][j] = 0;
			}
			else if (tab[i - 1].get_masa() <= j) {
				// znalezienie maksimum
				tmp[i][j] = max(
						tab[i - 1].get_wartosc() + tmp[i - 1][j - tab[i - 1].get_masa()],
						tmp[i - 1][j]);
			}
			else { // zwykłe przepisanie z wyższego indeksu tablicy
				tmp[i][j] = tmp[i - 1][j];
			}
		}
	}
	return tmp[ROZMIAR][wielkosc]; // zwrócenie maksymalnej wartości
}

} /* namespace std */
