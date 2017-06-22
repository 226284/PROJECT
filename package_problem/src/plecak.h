/*
 * plecak.h
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#ifndef PLECAK_H_
#define PLECAK_H_
#include <string>
#include <iostream>
#include <list>
#include "Towar.h"

using namespace std;

class Plecak 
{
	list<Towar> pl;
	int masa;	// dopuszczalna masa
	
	public:
	~Plecak();
	Plecak(int masa_podana);
	void dodaj(Towar obiekt);
	void wyswietl();
	int* zwroc_numery();
	int zwroc_rozmiar();
	int zwroc_wartosc();
	void oproznij();

};



#endif /* PLECAK_H_ */
