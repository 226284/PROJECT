//============================================================================
// Name        : package_problem.cpp
// Author      : Michał Wieczorek, Artur Szafraniak
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "Towar.h"
#include "Magazyn.h"
#include "plecak.h"
#include "SDL/SDL.h"

using namespace std;

vector<string> explode(string const & s, char delim) {
	vector<string> result;
	istringstream iss(s);

	for (string token; getline(iss, token, delim);) {
		result.push_back(move(token));
	}

	return result;
}

void czytaj(string nazwa, Magazyn & jubiler) {

	int temp1=0;
	int temp2=0;
	int x=0;
	vector<string> tab;
	cout << nazwa << endl;
	fstream plik;
	plik.open(nazwa.c_str(), ios::in);
	if (plik.good())
	{
		string napis;
		cout << "Zawartosc pliku:" << endl;
		while (!plik.eof()) 
		{
			getline(plik, napis);

			if(napis!="")
			{
				tab = explode(napis, ' ');
				for (unsigned int i = 0; i < tab.size(); i++)
				{
					cout << tab[i] << " ";
				}
				temp1=stoi(tab[1]);
				temp2=stoi(tab[2]);
				Towar towar(tab[0],temp1,temp2);
				jubiler.dodaj(towar,x);
				++x;
			}
			
		
		}
	}	
		else
		{	
			cout << "Error! Nie udalo otworzyc sie pliku!" << endl;
		}

		plik.close();
	

}

int main() {
	Magazyn jubiler(5);

	czytaj("dane.txt",jubiler);
	cout<<"DZIALAM"<<endl;
	jubiler.wyswietl();
	SDL_Init( SDL_INIT_EVERYTHING );
	SDL_Surface * ekran = NULL;
	SDL_Surface * obraz = NULL;

	ekran = SDL_SetVideoMode( 1024, 576, 32, SDL_SWSURFACE | SDL_DOUBLEBUF );
	obraz = SDL_LoadBMP( "tlo.bmp" );
		SDL_ShowCursor( SDL_DISABLE );
	   	SDL_BlitSurface( obraz, NULL, ekran, NULL );

    SDL_Flip( ekran );
    SDL_Delay( 2000 );
    SDL_Quit();

/*
	Plecak plecak1(7);
	Plecak plecak2(7);
	cout << "Knapsack problem" << endl;
	// wprowadzane dane:
	int wielkosc_plecaka = 7;
	string o = "dane.txt";
	czytaj(o);
	string li = "123";
	int dwa = stoi(li);
	int trzy = 3;
	int wynik = trzy * dwa;
	cout << wynik << endl;

	Magazyn jubiler(5);			// stworzenie tablicy na przedmioty w sklepie
	Towar przedmiot1("Kolczyki", 100, 3);
	Towar przedmiot2("Pierścionek", 20, 2); // stworzenie przykładowego towaru
	Towar przedmiot3("Naszyjnik", 60, 4);
	Towar przedmiot4("Zegarek", 40, 1);


	jubiler.dodaj(przedmiot1, 1); 	//dodanie towaru do magazynu
	jubiler.dodaj(przedmiot2, 2);
	jubiler.dodaj(przedmiot3, 3);
	jubiler.dodaj(przedmiot4, 4);

	cout << endl << "**********************************************************************" << endl;

	// wykonanie algorytmu 1-0
	jubiler.knapsack(wielkosc_plecaka,plecak2);

	cout << "Zawartość plecaka: " << endl;
	jubiler.wyswietl_knap();
	jubiler.sort3(plecak1);
	plecak1.wyswietl();
	plecak2.wyswietl();
*/
	return 0;
}
