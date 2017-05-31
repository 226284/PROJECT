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
private:
	Towar *tab;		// tablica zawierająca dane magazynowe
	int ROZMIAR;	// przechowuje rozmiar tablicy
};

} /* namespace std */

#endif /* MAGAZYN_H_ */
