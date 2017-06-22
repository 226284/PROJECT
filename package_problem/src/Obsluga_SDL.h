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
	bool obszar_klikniecia(SDL_Rect myszka,Obiekt_SDL napis);
	bool klik_alg(SDL_Event zdarzenie,SDL_Rect myszka,Obiekt_SDL napis);

	int* myszka1(bool algorytm[4], int miejsca_jubilera, int miejsce_plecak, int & rozmiar_plecaka, int wartosc[4], int pokaz[4]);
	void myszka2(int & x, Obiekt_SDL napisDane[4], bool chwyt[8], bool & klik, Obiekt_SDL & menuDane);

	int ruchx(SDL_Event zdarzenie);
	int ruchy(SDL_Event zdarzenie);

	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
	void sprawdzam1(int pokaz[4]);
	void sprawdzam2(int pokaz[4], Obiekt_SDL message[4]);

	void spacja_dzialanie(Obiekt_SDL  & menu, int & x,Obiekt_SDL napis[],Obiekt_SDL  & dlon,Obiekt_SDL obiekt[],bool chwyt[8], bool & spacja, int pokaz[4], int & licznik_obiektow  );
	void reset();
};


#endif
