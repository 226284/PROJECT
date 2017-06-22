#include "Obiekt_SDL.h"
#include <iostream>

using namespace std;


Obiekt_SDL::Obiekt_SDL()
{
	dane.x=0;
	dane.y=0;
	dane.w=0;
	dane.h=0;	
}

Obiekt_SDL::Obiekt_SDL(int wartosc)
{
	textColor = { 255, 255, 255 };
	font=TTF_OpenFont( "cz.otf", 20 );
	obraz=TTF_RenderText_Solid( font, to_string(wartosc).c_str(), textColor );	
}

void Obiekt_SDL::dodaj(int wartosc)
{

	textColor = { 255, 255, 255 };
	font=TTF_OpenFont( "cz.otf", 20 );
	obraz=TTF_RenderText_Solid( font, to_string(wartosc).c_str(), textColor );	
}

Obiekt_SDL::Obiekt_SDL(string nazwa,int w,int h, int x,int y)
{
	obraz = SDL_LoadBMP(nazwa.c_str());
	dane.x=0;
	dane.y=0;
	dane.w=w;
	dane.h=h;
	miejsce.x=x;
	miejsce.y=y;
}


void Obiekt_SDL::pokaz(SDL_Surface * ekran)
{
	SDL_SetColorKey( obraz , SDL_SRCCOLORKEY, SDL_MapRGB( obraz->format, 255, 255, 255) );
	SDL_BlitSurface( obraz, &dane, ekran, &miejsce);

	if(dane.w==0&&dane.h==0)
	{
		SDL_SetColorKey( obraz , SDL_SRCCOLORKEY, SDL_MapRGB( obraz->format, 255, 255, 255) );
		SDL_BlitSurface( obraz, NULL, ekran, &miejsce);	
	}

	if(miejsce.x==0&&miejsce.y==0)
	{
		SDL_SetColorKey( obraz , SDL_SRCCOLORKEY, SDL_MapRGB( obraz->format, 255, 255, 255) );
		SDL_BlitSurface( obraz, &dane, ekran, NULL);	
	
	}
}



void Obiekt_SDL::pokaztlo(SDL_Surface * ekran)
{
	SDL_BlitSurface( obraz, NULL, ekran, NULL);
}

void Obiekt_SDL::dodaj(string nazwa,int w,int h, int x,int y)
{
	obraz = SDL_LoadBMP(nazwa.c_str());
	dane.w=w;
	dane.h=h;
	miejsce.x=x;
	miejsce.y=y;
}

SDL_Rect Obiekt_SDL::daj_dane()
{
	return dane;
}

SDL_Rect Obiekt_SDL::daj_miejsce()
{
	return miejsce;
}

SDL_Surface* Obiekt_SDL::daj_surf()
{
	return obraz;
}

void Obiekt_SDL::ustaw_wh(int w, int h)
{
	dane.x=0;
	dane.y=0;
	dane.w=w;
	dane.h=h;
}

void Obiekt_SDL::ustaw_xy(int x, int y)
{
	miejsce.x=x;
	miejsce.y=y;
}


void Obiekt_SDL::clean()
{
	SDL_FreeSurface( obraz );
}

void Obiekt_SDL::clean_t()
{
	SDL_FreeSurface( obraz );
}


