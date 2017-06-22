/*
 * Magazyn.cpp
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#include "Magazyn.h"
#include "plecak.h"
#include <algorithm> 

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
		cout << i + 1 << ". ";
		tab[i].wyswietl();
	}
}

void Magazyn::sort1(Plecak & pl_podany	) {
	Towar towar;
	float temp = 0;
	int pole = 0;
	for (int j = 0; j < ROZMIAR-1; j++) 
	{
		for (int i = 0; i < ROZMIAR; i++) 
		{
			if (temp < tab[i].get_wartosc()) 
			{
				temp = tab[i].get_wartosc();
				pole = i;
				towar=tab[i];
			}
		}
		pl_podany.dodaj(towar);
		this->usun(pole);
		temp = 0;
	}
}

void Magazyn::sort2(Plecak & pl_podany) {

	Towar towar;
	float temp_masa = 10000;
	int pole = 0;
	for (int j = 0; j < ROZMIAR-1; j++) {
		for (int i = 0; i < ROZMIAR; i++) {
			if (temp_masa > tab[i].get_masa()) {
				temp_masa = tab[i].get_masa();
				pole = i;
				towar=tab[i];
			}
		}
		pl_podany.dodaj(towar);
		this->usun(pole);
		temp_masa = 10000;
	}



}
void Magazyn::sort3(Plecak & pl_podany) {
	Towar towar;
	float temp = 0;
	int pole = 0;
	for (int j = 0; j < ROZMIAR-1; j++) {
		for (int i = 0; i < ROZMIAR; i++) {
			if (temp < tab[i].get_wartosc() / tab[i].get_masa()) {
				temp = tab[i].get_wartosc() / tab[i].get_masa();
				pole = i;
				towar=tab[i];
			}
		}
		pl_podany.dodaj(towar);
		this->usun(pole);
		temp = 0;
	}

}

int Magazyn::max(int liczba1, int liczba2) {
	if (liczba1 > liczba2) {
		return liczba1;
	}
	return liczba2;
}

void Magazyn::knapsack(int wielkosc,Plecak & pl_podany) {


	
		
	int i, j; // pomocnicze liczniki
	int tmp[ROZMIAR + 1][wielkosc + 1]; // tab pomocnicza do przechowywania danych

	for (i = 0; i <= ROZMIAR; i++) {
		for (j = 0; j <= wielkosc; j++) {
			if (i == 0 || j == 0) { // zerowe indeksy wypełniamy zerami
				tmp[i][j] = 0;
			}
			else if (tab[i].get_masa() <= j) {
				// znalezienie maksimum
				tmp[i][j] = max(
						tab[i].get_wartosc()
								+ tmp[i - 1][j - tab[i].get_masa()],
						tmp[i - 1][j]);
			}
			else { // zwykłe przepisanie z wyższego indeksu tablicy
				tmp[i][j] = tmp[i - 1][j];
			}
		}
	}
	// pomocnicze wyświetlanie zawartości tablicy
	for (i = 0; i <= ROZMIAR; i++) {
		for (j = 0; j <= wielkosc; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << endl;
	}

	i = ROZMIAR;
	j = wielkosc;

	while (i > 0 && j > 0) {
		if (tmp[i][j] != tmp[i - 1][j]) {
			pl_podany.dodaj(tab[i]);
			j = j - tab[i].get_masa();
			i = i - 1;
		}
		else {
			i = i - 1;
		}
	}
	delete []tab;
}



} /* namespace std */
