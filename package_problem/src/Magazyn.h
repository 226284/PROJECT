/*
 * Magazyn.h
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#ifndef MAGAZYN_H_
#define MAGAZYN_H_
#include <list>
#include "IMagazyn.h"
#include "Towar.h"
#include "plecak.h"

namespace std {

class Magazyn: public IMagazyn{
public:
	Magazyn(int rozmiar);
	virtual ~Magazyn();
	//metody do obsługi magazynu
	virtual void dodaj(Towar przedmiot, int pole); 	// dodaje towar na podane pole tablicy
	virtual void usun(int pole); 	// usuwa towar z podanego pola w tablicy
	virtual void wyswietl();
	void sort1(Plecak & plecak);	// wedle ceny (najwieksza cena pierwsza)
	void sort2(Plecak & plecak);	// wedle masy (na poczatek najlzesze)
	void sort3(Plecak & plecak);   //stosunek cena/masa pierwszy
	int max(int liczba1, int liczba2);
	void knapsack(int wielkosc,Plecak & plecak); // przyjmuje wielkość plecaka, pozostałe parametry są w amgazynie

private:
	Towar *tab;		// tablica zawierająca dane magazynowe
	int ROZMIAR;	// przechowuje rozmiar tablicy
};

} /* namespace std */

#endif /* MAGAZYN_H_ */
