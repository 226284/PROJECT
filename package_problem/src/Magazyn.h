/*
 * Magazyn.h
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#ifndef MAGAZYN_H_
#define MAGAZYN_H_
#include "Towar.h"

namespace std {

class Magazyn {
public:
	Magazyn();
	virtual ~Magazyn();
	//metody do obsługi magazynu
	// dodaj towar
	// usun towar
private:
	Towar tab[20];	// tablica zawierająca dane magazynowe
};

} /* namespace std */

#endif /* MAGAZYN_H_ */
