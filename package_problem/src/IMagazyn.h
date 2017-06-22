/*
 * IMagazyn.h
 *
 *  Created on: 31 maj 2017
 *      Author: michal
 */

#ifndef IMAGAZYN_H_
#define IMAGAZYN_H_
#include "Towar.h"

namespace std {

class IMagazyn {
public:
	IMagazyn();
	virtual ~IMagazyn();

	virtual void dodaj(Towar przedmiot, int pole)=0; // dodaje towar na podane pole tablicy
	virtual void usun(int pole)=0; 				// usuwa towar z podanego pola w tablicy
	virtual void wyswietl()=0;					// wyświetla zawartość magazynu
};

} /* namespace std */

#endif /* IMAGAZYN_H_ */
