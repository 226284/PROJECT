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
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

using namespace std;
SDL_Surface * ekran = NULL;
SDL_Surface * obraz = NULL;
SDL_Surface * menu = NULL;
SDL_Surface * plecak = NULL;
SDL_Surface *message[4] = {NULL,NULL,NULL,NULL};

SDL_Surface *obiekt[8];
SDL_Surface *napis[4];
SDL_Rect Dane[8];
SDL_Rect Cel[8];
SDL_Rect napisDane[4];
SDL_Rect napisCel[4];
SDL_Rect miejsce;

SDL_Surface * dlon = NULL;
SDL_Rect dlonDane;
SDL_Rect menuCel;
SDL_Rect menuDane;
SDL_Rect plecakCel;

SDL_Rect ruch;
SDL_Event zdarzenie;
bool wyjscie = false;
TTF_Font *font = NULL;
SDL_Color textColor = { 255, 255, 255 };

/******************************************************************************************/

vector<string> explode(string const & s, char delim);

void obiekty_miejsce(SDL_Rect Cel[8], SDL_Rect Dane[8]);

void ustaw_xy(SDL_Rect & podany, int x, int y);
void ustaw_wh(SDL_Rect & podany, int w, int h);

void napis_dane_ustawiam(SDL_Rect napisDane[4]);

void napis_cel_ustawiam(SDL_Rect napisCel[4]);

void czytaj(string nazwa, Magazyn & jubiler);

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

void sprawdzam1(int pokaz[4]);
void sprawdzam2(int pokaz[4]);
int myszka1(int numer_algorytmu, int miejsca_jubilera, int miejsce_plecak, int* tab, int & rozmiar_plecaka, int wartosc[4]);
/************************************************************************/ 



int main() {
	int wartosc[4]={0,0,0,0};
	int pokaz[4]={0,0,0,0};	//kazdy algorytm ma swojego boola, np. gdy wykonuje sie pierwszy to on dostaje true i potem jest pokazywany

	SDL_Init( SDL_INIT_EVERYTHING );
	TTF_Init();
	int miejsce_plecak=12; // ile ma masy w sobie plecak (tzn ile uniesie, "x" gram) 
	int miejsca_jubilera=8; // ile bedzie obiektow u jubilera

	font = TTF_OpenFont( "cz.otf", 20 );


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
	ustaw_xy(dlonDane,0,0);
	ustaw_wh(menuDane,250,305);
	ustaw_xy(menuCel,340,180);
	ustaw_xy(plecakCel,100,350);
	ustaw_xy(ruch,0,0);
	ustaw_xy(miejsce,200,450);


	while( !wyjscie )
	{
		SDL_FillRect( ekran, NULL, 0 );
		SDL_ShowCursor( SDL_DISABLE );
	   	SDL_BlitSurface( obraz, NULL, ekran, NULL );
	   	SDL_BlitSurface( menu, & menuDane, ekran, & menuCel );
		SDL_SetColorKey( plecak , SDL_SRCCOLORKEY, SDL_MapRGB( plecak->format, 255, 255, 255) );
	   	SDL_BlitSurface( plecak, NULL, ekran, & plecakCel );
		message[0] = TTF_RenderText_Solid( font, to_string(wartosc[0]).c_str(), textColor );
		message[1] = TTF_RenderText_Solid( font, to_string(wartosc[1]).c_str(), textColor );
		message[2] = TTF_RenderText_Solid( font, to_string(wartosc[2]).c_str(), textColor );
		message[3] = TTF_RenderText_Solid( font, to_string(wartosc[3]).c_str(), textColor );
		
		sprawdzam2(pokaz);
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
					Cel[tab[licznik_obiektow]].x=miejsce.x;
					Cel[tab[licznik_obiektow]].y=miejsce.y;
					licznik_obiektow++;
				}
				
				if(licznik_obiektow==rozmiar_plecaka)
				{
					ustaw_wh(menuDane,250,302);
					x=0;

					napis_dane_ustawiam(napisDane);
					
					ustaw_xy(ruch,0,0);
					obiekty_miejsce(Cel,Dane);
					while(x<8)
					{
						chwyt[x]=true;
						x++;
						spacja=false;
					}
					sprawdzam1(pokaz);
					licznik_obiektow=0;
				}
		}

		while( SDL_PollEvent( & zdarzenie ) )
		{
           		if( zdarzenie.key.keysym.sym == SDLK_SPACE )
           		{
				ustaw_wh(menuDane,0,0);
				x=0;
				for(int i=0; i<4; i++)
				{
					ustaw_wh(napisDane[i],0,0);				
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
					wartosc[0]=plecak1.zwroc_wartosc();
					pokaz[0]=1;
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
					wartosc[1]=plecak1.zwroc_wartosc();
					pokaz[1]=1;
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
					wartosc[2]=plecak1.zwroc_wartosc();
					pokaz[2]=1;
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
					wartosc[3]=plecak1.zwroc_wartosc();
					pokaz[3]=1;
					cout<<"knap"<<endl;
				}
			}

			if( zdarzenie.key.keysym.sym == SDLK_ESCAPE )
			{		
				wyjscie =true;
			}
		}
	}
	return 0;
}

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
	ustaw_xy(Cel[0],29,262);
	ustaw_xy(Cel[1],109,272);
	ustaw_xy(Cel[2],160,272);
	ustaw_xy(Cel[3],210,272);
	ustaw_xy(Cel[4],240,242);
	ustaw_xy(Cel[5],590,252);
	ustaw_xy(Cel[6],650,262);
	ustaw_xy(Cel[7],890,170);

	ustaw_wh(Dane[0],65,61);
	ustaw_wh(Dane[1],30,30);
	ustaw_wh(Dane[2],43,32);
	ustaw_wh(Dane[3],34,32);
	ustaw_wh(Dane[4],101,76);
	ustaw_wh(Dane[5],25,55);
	ustaw_wh(Dane[6],61,50);
	ustaw_wh(Dane[7],133,102);
}

void napis_dane_ustawiam(SDL_Rect napisDane[4])
{
ustaw_wh(napisDane[0],178,45);
ustaw_wh(napisDane[1],170,28);
ustaw_wh(napisDane[2],214,34);
ustaw_wh(napisDane[3],180,23);
}

void napis_cel_ustawiam(SDL_Rect napisCel[4])
{
ustaw_xy(napisCel[0],350,220);
ustaw_xy(napisCel[1],360,265);
ustaw_xy(napisCel[2],360,300);
ustaw_xy(napisCel[3],365,340);
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

void ustaw_xy(SDL_Rect & podany, int x, int y)
{
	podany.x=x;
	podany.y=y;
}

void ustaw_wh(SDL_Rect & podany, int w, int h)
{
	podany.w=w;
	podany.h=h;
}

void sprawdzam1(int pokaz[4])
{
	for(int i=0;i<4;i++)
	{
		if(pokaz[i]==1)
		{
			pokaz[i]=2;
		}
	}
}

void sprawdzam2(int pokaz[4])
{
	if(pokaz[0]==2)
	{
		apply_surface( 1050, 150, message[0], ekran );
	}

	if(pokaz[1]==2)
	{
		apply_surface( 1050, 260, message[1], ekran );
	}

	if(pokaz[2]==2)
	{
		apply_surface( 1050, 390, message[2], ekran );
	}

	if(pokaz[3]==2)
	{
		apply_surface( 1050, 510, message[3], ekran );
	}
}

int myszka1(int numer_algorytmu, int miejsca_jubilera, int miejsce_plecak, int* tab, int & rozmiar_plecaka, int wartosc[4])
{
	Magazyn jubiler(miejsca_jubilera);	
	Plecak plecak1(miejsce_plecak);
	czytaj("dane.txt",jubiler);	
	jubiler.sort1(plecak1);	
	tab=plecak1.zwroc_numery();
	rozmiar_plecaka=plecak1.zwroc_rozmiar();
	cout<<"sort1"<<endl;
	wartosc[numer_algorytmu]=plecak1.zwroc_wartosc();
	return 1;

}

