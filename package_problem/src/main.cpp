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
SDL_Surface * ekran = NULL;
SDL_Surface * obraz = NULL;

SDL_Surface *obiekt[8];
SDL_Rect Dane[8];
SDL_Rect Cel[8];
SDL_Rect miejsce[5];

SDL_Surface * dlon = NULL;
SDL_Rect dlonDane;

SDL_Rect ruch;
SDL_Event zdarzenie;
bool wyjscie = false;

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

		while (!plik.eof()) 
		{
			getline(plik, napis);

			if(napis!="")
			{
				tab = explode(napis, ' ');
/*
				for (unsigned int i = 0; i < tab.size(); i++)
				{
					cout << tab[i] << " ";
				}
*/
				temp1=stoi(tab[1]);
				temp2=stoi(tab[2]);
				Towar towar(tab[0],temp1,temp2,x);
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

	Magazyn jubiler(8);	//8 to ogolna ilosc obiektow u jubilera
	Plecak plecak1(7);	// 7 to masa jaka uniesie plecak

	czytaj("dane.txt",jubiler);
	cout<<"DZIALAM"<<endl;
	jubiler.wyswietl();

	jubiler.knapsack(7,plecak1);
	plecak1.wyswietl();
	int *tab=NULL;
	int rozmiar_plecaka=0;
	tab=plecak1.zwroc_numery();
	rozmiar_plecaka=plecak1.zwroc_rozmiar();

	
	bool spacja=false;
	bool chwyt[8];
	int x=0;
	int licznik_obiektow=0;
	while(x<8)
	{
		chwyt[x]=true;
		x++;
	}
	string spr="";

	SDL_Init( SDL_INIT_EVERYTHING );
	ekran = SDL_SetVideoMode( 1024, 576, 32, SDL_SWSURFACE | SDL_DOUBLEBUF );
	obraz = SDL_LoadBMP( "tlo.bmp" );
	dlon = SDL_LoadBMP("dlon.bmp");
	
	obiekt[0] = SDL_LoadBMP( "pierscionek.bmp" );	
	obiekt[1] = SDL_LoadBMP( "pierscionek2.bmp" );
	obiekt[2] = SDL_LoadBMP( "zegarek1.bmp" );
	obiekt[3] = SDL_LoadBMP( "zegarek2.bmp" );
	obiekt[4] = SDL_LoadBMP( "kolczyki.bmp" );
	obiekt[5] =  SDL_LoadBMP( "lancuszek.bmp" );
	obiekt[6] = SDL_LoadBMP( "naszyjnik.bmp" );
	obiekt[7] = SDL_LoadBMP( "naszyjnik2.bmp" );

	miejsce[0].x=100;
	miejsce[0].y=500;

	Dane[0].w = 65;
	Dane[0].h = 61;
	Cel[0].x = 29;
	Cel[0].y = 262;

	Dane[1].w = 30;
	Dane[1].h = 30;
	Cel[1].x = 109;
	Cel[1].y = 272;

	Dane[2].w = 43;
	Dane[2].h = 32;
	Cel[2].x = 160;
	Cel[2].y = 272;

	Dane[3].w = 34;
	Dane[3].h = 32;
	Cel[3].x = 210;
	Cel[3].y = 272;

	Dane[4].w = 101;
	Dane[4].h = 76;
	Cel[4].x = 240;
	Cel[4].y = 242;

	Dane[5].w = 25;
	Dane[5].h = 55;
	Cel[5].x = 590;
	Cel[5].y = 255;

	Dane[6].w = 61;
	Dane[6].h = 50;
	Cel[6].x = 650;
	Cel[6].y = 262;


	Dane[7].w = 133;
	Dane[7].h = 102;
	Cel[7].x = 890;
	Cel[7].y =170;


	dlonDane.x = 0;
	dlonDane.y = 0;

	ruch.x=0;
	ruch.y=0;

	while( !wyjscie )
	{
		SDL_FillRect( ekran, NULL, 0 );
		SDL_ShowCursor( SDL_DISABLE );
	   	SDL_BlitSurface( obraz, NULL, ekran, NULL );


		for(int i=0; i<8; i++)
		{
			SDL_SetColorKey( obiekt[i] , SDL_SRCCOLORKEY, SDL_MapRGB( obiekt[i]->format, 255, 255, 255) );
	   		SDL_BlitSurface( obiekt[i], & Dane[i], ekran, & Cel[i] );
		
		}

		SDL_SetColorKey( dlon , SDL_SRCCOLORKEY, SDL_MapRGB( dlon->format, 0, 0, 0) );
        	SDL_BlitSurface( dlon, NULL, ekran, & dlonDane );

		SDL_SetColorKey( dlon , SDL_SRCCOLORKEY, SDL_MapRGB( dlon->format, 0, 0, 0) );
        	SDL_BlitSurface( dlon, NULL, ekran, & ruch );

		if( zdarzenie.type == SDL_MOUSEMOTION )
		{
			dlonDane.x = zdarzenie.motion.x;
			dlonDane.y = zdarzenie.motion.y;
		}
		SDL_Flip( ekran );

		if(spacja==true&&licznik_obiektow<rozmiar_plecaka)
		{
		
				if(ruch.x<Cel[tab[licznik_obiektow]].x && chwyt[tab[licznik_obiektow]]==false)
				{
					++ruch.x;
				}	else if(ruch.x>Cel[tab[licznik_obiektow]].x && chwyt[tab[licznik_obiektow]]==false)
					{
					--ruch.x;
					}
	
				if(ruch.y<Cel[tab[licznik_obiektow]].y && chwyt[tab[licznik_obiektow]]==false)
				{
					++ruch.y;
				}	else if(ruch.y>Cel[tab[licznik_obiektow]].y && chwyt[tab[licznik_obiektow]]==false)
					{
						--ruch.y;
					}

				if(ruch.x==Cel[tab[licznik_obiektow]].x && ruch.y==Cel[tab[licznik_obiektow]].y && chwyt[tab[licznik_obiektow]]==false)
				{
					chwyt[tab[licznik_obiektow]]=true;
					Cel[tab[licznik_obiektow]].x=miejsce[0].x;
					Cel[tab[licznik_obiektow]].y=miejsce[0].y;
					licznik_obiektow++;
				}
		}

		while( SDL_PollEvent( & zdarzenie ) )
		{
           		if( zdarzenie.key.keysym.sym == SDLK_SPACE )
           		{
				x=0;
				while(x<8)
				{
					chwyt[x]=false;
					x++;
					spacja=true;
				}
            		}



			if( zdarzenie.type == SDL_MOUSEBUTTONDOWN )
			{
				for (int i=0; i<8; i++)
				{

					if( zdarzenie.button.button == SDL_BUTTON_LEFT &&
					( dlonDane.x >= Cel[i].x && dlonDane.x <=
					Cel[i].x + Dane[i].w ) &&( dlonDane.y >=
					Cel[i].y && dlonDane.y <= Cel[i].y +
					Dane[i].h ) )
					{
						Cel[i].x=miejsce[0].x;
						Cel[i].y=miejsce[0].y;
					}
				}
				
			}

			if( zdarzenie.key.keysym.sym == SDLK_ESCAPE )
			{		
				wyjscie =true;
			}


   
		}
	}

/*
	Plecak plecak1(7);
	Plecak plecak2(7);
	cout << "Knapsack problem" << endl;
	// wprowadzane dane:
	int wielkosc_plecaka = 7;
	string o = "dane.txt";

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
	jubiler.sort3(plecak1);
	plecak1.wyswietl();
	plecak2.wyswietl();
*/
	return 0;
}
