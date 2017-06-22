#ifndef Obsluga_SDL_H_
#define Obsluga_SDL_H_

#include <iostream>
#include "Towar.h"
#include "Magazyn.h"
#include "plecak.h"
#include "Obiekt_SDL.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
using namespace std;




class Obsluga_SDL
{

	SDL_Surface * ekran = NULL;

	public:
	Obsluga_SDL(int w,int h);
	void pokaz(Obiekt_SDL podany);
	void pokaz_tablice(Obiekt_SDL podany[], int rozmiar);
	void pokaz_tlo(Obiekt_SDL podany);
	void flip();

	bool esc(SDL_Event zdarzenie);
	bool ruch(SDL_Event zdarzenie);
	bool klik(SDL_Event zdarzenie);
	bool klik_lewy(SDL_Event zdarzenie);
/*
obszkar_klikniecia - sprawdza czy kliknieta myszka w okreslony obszar
*/
	bool obszar_klikniecia(SDL_Rect myszka,Obiekt_SDL napis);
	bool klik_alg(SDL_Event zdarzenie,SDL_Rect myszka,Obiekt_SDL napis);
/*
myszka1 - po kliknieciu myszka w algorytm on sie po prostu wykonuje i zwraca wskaznik na tablice w ktorej sa przechowywane NUMERY obiektow (np. pierscionek ma numer 0 itd) jest mi to potrzebne do odpowiedniego zbierania przez reke
*/
	int* myszka1(bool algorytm[4], int miejsca_jubilera, int miejsce_plecak, int & rozmiar_plecaka, int wartosc[4], int pokaz[4]);
/*
myszka2 - po klikniecu wymiaru menu oraz napisow sa zerowane, zeby cala animacja byla widoczna, wewnatrz klikniecie dostaje TRUE(zeby zadzialalo zbieranie) 
*/
	void myszka2(int & x, Obiekt_SDL napisDane[4], bool chwyt[8], bool & klik, Obiekt_SDL & menuDane);

	int ruchx(SDL_Event zdarzenie);
	int ruchy(SDL_Event zdarzenie);

	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
/*
sprawdzam1 i sprawdzam2 - byly mi potrzebne do poprawnego dzialania symulacji ruchu reki, 4 elementy w tablicy pokaz sa dla kazdego z algorytmow, w myszka1 po wykoanniu sie algorytmu odpowiednie miejsce w pokaz dostaje wartosc 1; w sprawdzam1 po zebraniu dostaje wartosc 2 i moga byc pokazywa
sprawdzam2 sprawdza czy elementy w tablicy pokaz maja wartosc 2; jesli tak to wyswietla odpowiedni napis
*/
	void sprawdzam1(int pokaz[4]);
	void sprawdzam2(int pokaz[4], Obiekt_SDL message[4]);
/*
spacja_dzialanie: po zebraniu elementow przez reke, mozna kliknac spacje, co przywraca poprzedni stan programu (wraca menu w ktorym mozna wybrac kolejny algorytm do przetestowania) + dlon wraca do rogu
*/
	void spacja_dzialanie(Obiekt_SDL  & menu, int & x,Obiekt_SDL napis[],Obiekt_SDL  & dlon,Obiekt_SDL obiekt[],bool chwyt[8], bool & spacja, int pokaz[4], int & licznik_obiektow  );
	void reset();
};


#endif
