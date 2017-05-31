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
	towar_ilosc=0;
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
		cout << i+1 << ". ";
		tab[i].wyswietl();
	}
}

void Magazyn::sort1() 
{
	float* plecak = new float[ROZMIAR];


	float temp=0;
	int pole=0;
	cout<<"zaczynaM"<<endl;
	for(int j=0;j<ROZMIAR;j++)
	{
		for(int i=0; i<ROZMIAR; i++)
		{
			if(temp<tab[i].get_wartosc() )
			{
				temp=tab[i].get_wartosc();
				pole=i;
			}
		}
		plecak[j]=temp;
		this->usun(pole);
		temp=0;
	}

	cout<<"po wszystkin"<<endl;
	this->wyswietl();
	for(int i=0; i<ROZMIAR; i++)
	{
		cout<<plecak[i]<<endl;
	}
}

void Magazyn::sort2()
{
	float* plecak = new float[ROZMIAR];


	float temp_kasa=0;
	float temp_masa=10000;
	int pole=0;
	cout<<"zaczynaM"<<endl;
	for(int j=0;j<ROZMIAR;j++)
	{
		for(int i=0; i<ROZMIAR; i++)
		{
			if(temp_masa>tab[i].get_masa() )
			{	
				temp_masa=tab[i].get_masa();
				temp_kasa=tab[i].get_wartosc();
				pole=i;
				cout<<"jest wieksze"<<i<<endl;
			}
		}

		cout<<j<<endl;
		plecak[j]=temp_kasa;
		this->usun(pole);
		temp_masa=10000;
	this->wyswietl();
	}

	cout<<"po wszystkim"<<endl;
	this->wyswietl();
	for(int i=0; i<ROZMIAR; i++)
	{
		cout<<plecak[i]<<endl;
	}

}
void Magazyn::sort3() 
{
	float* plecak = new float[ROZMIAR];


	float temp=0;
	float temp2=0;
	int pole=0;
	cout<<"zaczynaM"<<endl;
	for(int j=0;j<ROZMIAR;j++)
	{
		for(int i=0; i<ROZMIAR; i++)
		{
			if(temp<tab[i].get_wartosc()/tab[i].get_masa() )
			{	
				cout<<tab[i].get_wartosc()/tab[i].get_masa()<<endl;
				temp=tab[i].get_wartosc()/tab[i].get_masa();
				temp2=tab[i].get_wartosc();
				pole=i;
			}
		}
		plecak[j]=temp2;
		this->usun(pole);
		temp=0;
	}

	cout<<"po wszystkin"<<endl;
	this->wyswietl();
	for(int i=0; i<ROZMIAR; i++)
	{
		cout<<plecak[i]<<endl;
	}

}

} /* namespace std */
