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
	Plecak(int masa_podana);
	void dodaj(Towar obiekt);
	void wyswietl();

};



#endif /* PLECAK_H_ */