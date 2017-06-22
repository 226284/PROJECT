#ifndef Obiekt_SDL_H_
#define Obiekt_SDL_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <vector>
#include <string>
#include <memory>

using namespace std;


class Obiekt_SDL
{

	public:
	Obiekt_SDL();
	Obiekt_SDL(int wartosc);
	Obiekt_SDL(string nazwa,int w,int h, int x,int y);
	void pokaz(SDL_Surface * ekran);
	void pokaztlo(SDL_Surface * ekran);
	void dodaj(string nazwa,int w,int h, int x,int y);
	void dodaj(int wartosc);
	SDL_Rect daj_dane();
	SDL_Rect daj_miejsce();
	SDL_Surface* daj_surf();
	void ustaw_wh(int w, int h);
	void ustaw_xy(int x, int y);
	void clean();
	void clean_t();



	private:

	SDL_Color textColor;
	SDL_Surface* obraz=NULL;
	TTF_Font *font=NULL;
	SDL_Rect dane;	// szerokosc i wysokosc
	SDL_Rect miejsce;	// gdzie wyladuje

};



#endif
