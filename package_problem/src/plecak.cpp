/*
 * plecak.cpp
 *
 *  Created on: 18 czerwca(czerwiec?) 2017
 *      Author: Artur
 */

#include "plecak.h"

using namespace std;

Plecak::Plecak(int masa_podana)
{
	masa=masa_podana;
}

void Plecak::dodaj(Towar obiekt)
{
	if(masa>=obiekt.get_masa())
	{
		pl.push_back(obiekt);
		masa=masa-obiekt.get_masa();
	}
		else 
		{
		cout<<"za mało masy"<<endl;
		}	

}

void Plecak::wyswietl()
{
	cout<<"poczatek"<<endl;
	for (list<Towar>::iterator iter = pl.begin(); iter != pl.end();
			iter++) {
		iter->wyswietl();
	}
	cout<<"koniec"<<endl;
}
