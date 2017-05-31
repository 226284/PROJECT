/*
 * Magazyn.h
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#ifndef MAGAZYN_H_
#define MAGAZYN_H_
#include "IMagazyn.h"
#include "Towar.h"

namespace std {

class Magazyn: public IMagazyn{
public:
	Magazyn(int rozmiar);
	virtual ~Magazyn();
	//metody do obsługi magazynu
	virtual void dodaj(Towar przedmiot, int pole); 	// dodaje towar na podane pole tablicy
	virtual void usun(int pole); 	// usuwa towar z podanego pola w tablicy
	virtual void wyswietl();
	void sort1();	// wedle ceny (najwieksza cena pierwsza)
	void sort2();	// wedle masy (na poczatek najlzesze)
	void sort3();   //stosunek cena/masa pierwszy
private:
	Towar *tab;		// tablica zawierająca dane magazynowe
	int ROZMIAR;	// przechowuje rozmiar tablicy
	int towar_ilosc;	// ile mamy towaru na składzie
};

} /* namespace std */

#endif /* MAGAZYN_H_ */
