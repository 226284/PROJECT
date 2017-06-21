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
SDL_Surface * menu = NULL;
SDL_Surface * plecak = NULL;

SDL_Surface *obiekt[8];
SDL_Surface *napis[4];
SDL_Rect Dane[8];
SDL_Rect Cel[8];
SDL_Rect napisDane[4];
SDL_Rect napisCel[4];
SDL_Rect miejsce[5];

SDL_Surface * dlon = NULL;
SDL_Rect dlonDane;
SDL_Rect menuCel;
SDL_Rect menuDane;
SDL_Rect plecakCel;

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

void obiekty_miejsce(SDL_Rect Cel[8], SDL_Rect Dane[8])
{
	miejsce[0].x=200;
	miejsce[0].y=450;

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

}

void napis_dane_ustawiam(SDL_Rect napisDane[4])
{
	napisDane[0].w = 178;
	napisDane[0].h = 45;


	napisDane[1].w = 170;
	napisDane[1].h = 28;


	napisDane[2].w = 214;
	napisDane[2].h = 34;


	napisDane[3].w = 180;
	napisDane[3].h = 23;


}

void napis_cel_ustawiam(SDL_Rect napisCel[4])
{


	napisCel[0].x = 350;
	napisCel[0].y =220;

	napisCel[1].x = 360;
	napisCel[1].y =265;

	napisCel[2].x = 360;
	napisCel[2].y =300;

	napisCel[3].x = 365;
	napisCel[3].y =340;

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
	int miejsce_plecak=7; // ile ma masy w sobie plecak (tzn ile uniesie, "x" gram) 
	int miejsca_jubilera=8; // ile bedzie obiektow u jubilera




	cout<<"DZIALAM"<<endl;

	int *tab=NULL;
	int rozmiar_plecaka=0;


	
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
	ekran = SDL_SetVideoMode( 1241, 576, 32, SDL_SWSURFACE | SDL_DOUBLEBUF );
	obraz = SDL_LoadBMP( "tlo.bmp" );
	dlon = SDL_LoadBMP("dlon.bmp");
	menu = SDL_LoadBMP("menu.bmp");
	plecak= SDL_LoadBMP("plecak.bmp");
	
	obiekt[0] = SDL_LoadBMP( "pierscionek.bmp" );	
	obiekt[1] = SDL_LoadBMP( "pierscionek2.bmp" );
	obiekt[2] = SDL_LoadBMP( "zegarek1.bmp" );
	obiekt[3] = SDL_LoadBMP( "zegarek2.bmp" );
	obiekt[4] = SDL_LoadBMP( "kolczyki.bmp" );
	obiekt[5] =  SDL_LoadBMP( "lancuszek.bmp" );
	obiekt[6] = SDL_LoadBMP( "naszyjnik.bmp" );
	obiekt[7] = SDL_LoadBMP( "naszyjnik2.bmp" );

	napis[0] = SDL_LoadBMP( "napis1.bmp");
	napis[1] = SDL_LoadBMP( "napis2.bmp");
	napis[2] = SDL_LoadBMP( "napis3.bmp");
	napis[3] = SDL_LoadBMP( "napis4.bmp");

	obiekty_miejsce(Cel,Dane);

	napis_dane_ustawiam(napisDane);
	napis_cel_ustawiam(napisCel);


	dlonDane.x = 0;
	dlonDane.y = 0;

	menuDane.w = 250;
	menuDane.h = 305;
	
	menuCel.x = 340;
	menuCel.y = 180;
	
	plecakCel.x = 100;
	plecakCel.y = 350;

	ruch.x=0;
	ruch.y=0;

	while( !wyjscie )
	{
		SDL_FillRect( ekran, NULL, 0 );
		SDL_ShowCursor( SDL_DISABLE );
	   	SDL_BlitSurface( obraz, NULL, ekran, NULL );
	   	SDL_BlitSurface( menu, & menuDane, ekran, & menuCel );
		SDL_SetColorKey( plecak , SDL_SRCCOLORKEY, SDL_MapRGB( plecak->format, 255, 255, 255) );
	   	SDL_BlitSurface( plecak, NULL, ekran, & plecakCel );

		for(int i=0; i<4; i++)
		{
			SDL_SetColorKey( napis[i] , SDL_SRCCOLORKEY, SDL_MapRGB( obiekt[i]->format, 0, 0, 0) );
	   		SDL_BlitSurface( napis[i], & napisDane[i], ekran, & napisCel[i] );
		}


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

		if(spacja==true && licznik_obiektow<rozmiar_plecaka)
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
				
				if(licznik_obiektow==rozmiar_plecaka)
				{
					menuDane.w = 250;
					menuDane.h = 305;
					x=0;

					napis_dane_ustawiam(napisDane);
					
					ruch.x = 0;
					ruch.y = 0;
					obiekty_miejsce(Cel,Dane);
					while(x<8)
					{
						chwyt[x]=true;
						x++;
						spacja=false;
					}
					licznik_obiektow=0;
				}
		}

		while( SDL_PollEvent( & zdarzenie ) )
		{
           		if( zdarzenie.key.keysym.sym == SDLK_SPACE )
           		{
				menuDane.w = 0;
				menuDane.h = 0;
				x=0;
				for(int i=0; i<4; i++)
				{
				napisDane[i].w = 0;
				napisDane[i].h = 0;				
				}
				while(x<8)
				{
					chwyt[x]=false;
					x++;
					spacja=true;
				}
				cout<<"kliknałem spacje"<<endl;
            		}



			if( zdarzenie.type == SDL_MOUSEBUTTONDOWN )
			{
				if( zdarzenie.button.button == SDL_BUTTON_LEFT &&
				( dlonDane.x >= napisCel[0].x && dlonDane.x <=
				napisCel[0].x + napisDane[0].w ) &&( dlonDane.y >=
				napisCel[0].y && dlonDane.y <= napisCel[0].y +
				napisDane[0].h ) )
				{
					Magazyn jubiler(miejsca_jubilera);	
					Plecak plecak1(miejsce_plecak);
					czytaj("dane.txt",jubiler);	
					jubiler.sort1(plecak1);	
					tab=plecak1.zwroc_numery();
					rozmiar_plecaka=plecak1.zwroc_rozmiar();
					cout<<"sort1"<<endl;
				}

				if( zdarzenie.button.button == SDL_BUTTON_LEFT &&
				( dlonDane.x >= napisCel[1].x && dlonDane.x <=
				napisCel[1].x + napisDane[1].w ) &&( dlonDane.y >=
				napisCel[1].y && dlonDane.y <= napisCel[1].y +
				napisDane[1].h ) )
				{
					Magazyn jubiler(miejsca_jubilera);	
					Plecak plecak1(miejsce_plecak);
					czytaj("dane.txt",jubiler);
					jubiler.sort2(plecak1);	
					tab=plecak1.zwroc_numery();
					rozmiar_plecaka=plecak1.zwroc_rozmiar();
					cout<<"sort2"<<endl;
				}

				if( zdarzenie.button.button == SDL_BUTTON_LEFT &&
				( dlonDane.x >= napisCel[2].x && dlonDane.x <=
				napisCel[2].x + napisDane[2].w ) &&( dlonDane.y >=
				napisCel[2].y && dlonDane.y <= napisCel[2].y +
				napisDane[2].h ) )
				{
					Magazyn jubiler(miejsca_jubilera);	
					Plecak plecak1(miejsce_plecak);
					czytaj("dane.txt",jubiler);
					jubiler.sort3(plecak1);	
					tab=plecak1.zwroc_numery();
					rozmiar_plecaka=plecak1.zwroc_rozmiar();
					cout<<"sort3"<<endl;
				}

				if( zdarzenie.button.button == SDL_BUTTON_LEFT &&
				( dlonDane.x >= napisCel[3].x && dlonDane.x <=
				napisCel[3].x + napisDane[3].w ) &&( dlonDane.y >=
				napisCel[3].y && dlonDane.y <= napisCel[3].y +
				napisDane[3].h ) )
				{
					Magazyn jubiler(miejsca_jubilera);	
					Plecak plecak1(miejsce_plecak);
					czytaj("dane.txt",jubiler);
					jubiler.knapsack(miejsce_plecak,plecak1);	
					tab=plecak1.zwroc_numery();
					rozmiar_plecaka=plecak1.zwroc_rozmiar();
					cout<<"knap"<<endl;
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
