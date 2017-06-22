#include "Obsluga_SDL.h"

#include <iostream>

using namespace std;

Obsluga_SDL::Obsluga_SDL(int w, int h)
{
	ekran = SDL_SetVideoMode( w, h, 32, SDL_SWSURFACE | SDL_DOUBLEBUF );
}

void Obsluga_SDL::pokaz(Obiekt_SDL podany)
{
	podany.pokaz(ekran);
}


void Obsluga_SDL::pokaz_tablice(Obiekt_SDL podany[], int rozmiar)
{
	for(int i=0;i<rozmiar;i++)
	{
		podany[i].pokaz(ekran);
	}
	
}

void Obsluga_SDL::pokaz_tlo(Obiekt_SDL podany)
{
	podany.pokaztlo(ekran);
}

bool Obsluga_SDL::esc(SDL_Event zdarzenie)
{
	if( zdarzenie.key.keysym.sym == SDLK_ESCAPE )
	{		
		return true;
	}	else
		{
			return false;
		}
}


int Obsluga_SDL::ruchx(SDL_Event zdarzenie)
{
		return zdarzenie.motion.x;
}

int Obsluga_SDL::ruchy(SDL_Event zdarzenie)
{
		return zdarzenie.motion.y;
}

bool Obsluga_SDL::ruch(SDL_Event zdarzenie)
{
	if( zdarzenie.type == SDL_MOUSEMOTION )
	{		
		return true;
	}	else
		{
			return false;
		}
}

bool Obsluga_SDL::klik(SDL_Event zdarzenie)
{
	if( zdarzenie.type == SDL_MOUSEBUTTONDOWN )
	{		
		return true;
	}	else
		{
			return false;
		}
}

bool Obsluga_SDL::klik_lewy(SDL_Event zdarzenie)
{
	if( zdarzenie.button.button == SDL_BUTTON_LEFT )
	{		
		return true;
	}	else
		{
			return false;
		}
}

void Obsluga_SDL::flip()
{
	SDL_Flip( ekran );
}


bool Obsluga_SDL::obszar_klikniecia(SDL_Rect myszka,Obiekt_SDL napis)
{

	SDL_Rect napisDane=napis.daj_dane();
	SDL_Rect napisCel=napis.daj_miejsce();

	if( ( myszka.x >= napisCel.x && myszka.x <=napisCel.x + napisDane.w ) &&
	( myszka.y >=	napisCel.y && myszka.y <= napisCel.y +napisDane.h ) )
		{
			return true;
		}	else
			{
			return false;
			}
}

bool Obsluga_SDL::klik_alg(SDL_Event zdarzenie,SDL_Rect myszka,Obiekt_SDL napis)
{
	if( this->klik_lewy(zdarzenie) && this->obszar_klikniecia(myszka,napis) )
	{	
		return true;
	}
}

int* Obsluga_SDL::myszka1(bool algorytm[4], int miejsca_jubilera, int miejsce_plecak, int & rozmiar_plecaka, int wartosc[4], int pokaz[4])
{
	int* tab= NULL;
	int numer_algorytmu=0;
	Magazyn jubiler(miejsca_jubilera);	
	Plecak plecak1(miejsce_plecak);
	Towar pierscionek("pierscionek", 20, 2,0);
	Towar pierscionek2("pierscionek2",50,4,1);
	Towar zegarek1("zegarek1",60,4,2);
	Towar zegarek2("zegarek2",120,9,3);
	Towar kolczyki("kolczyki",100,3,4);
	Towar lancuszek("lancuszek",75,4,5);
	Towar naszyjnik("naszyjnik",50,3,6);
	Towar naszyjnik2("naszyjnik2",170,10,7);
	jubiler.dodaj(pierscionek,0);
	jubiler.dodaj(pierscionek2,1);
	jubiler.dodaj(zegarek1,2);
	jubiler.dodaj(zegarek2,3);
	jubiler.dodaj(kolczyki,4);
	jubiler.dodaj(lancuszek,5);
	jubiler.dodaj(naszyjnik,6);
	jubiler.dodaj(naszyjnik2,7);
	
	if(algorytm[0]==true)
	{
		jubiler.sort1(plecak1);
		cout<<"alg1"<<endl;
		numer_algorytmu=0;
	}	else if (algorytm[1]==true)
		{
			jubiler.sort2(plecak1);
			cout<<"alg2"<<endl;
			numer_algorytmu=1;
		}	else if(algorytm[2]==true)
			{
				jubiler.sort3(plecak1);
				cout<<"alg3"<<endl;
				numer_algorytmu=2;
			}	else if(algorytm[3]==true)
				{
					jubiler.knapsack(miejsce_plecak,plecak1);
					cout<<"alg4"<<endl;
					numer_algorytmu=3;
				}

	tab=plecak1.zwroc_numery();
	rozmiar_plecaka=plecak1.zwroc_rozmiar();

	wartosc[numer_algorytmu]=plecak1.zwroc_wartosc();
	pokaz[numer_algorytmu]=1;
	return tab;

}

void Obsluga_SDL::myszka2(int & x, Obiekt_SDL napisDane[4], bool chwyt[8], bool & klik, Obiekt_SDL & menuDane)
{
	menuDane.ustaw_xy(5000,5000);
	x=0;
	for(int i=0; i<4; i++)
	{
		napisDane[i].ustaw_xy(5000,5000);				
	}
	while(x<8)
	{
		chwyt[x]=false;
		x++;
		klik=true;
	}
}

void Obsluga_SDL::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination  )
{

	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface( source, NULL, destination, &offset );
}

void Obsluga_SDL::sprawdzam1(int pokaz[4])
{
	for(int i=0;i<4;i++)
	{
		if(pokaz[i]==1)
		{
			pokaz[i]=2;
		}
	}
}

void Obsluga_SDL::sprawdzam2(int pokaz[4],Obiekt_SDL message[4])
{
	if(pokaz[0]==2)
	{
		SDL_Rect offset;
		offset.x = 1050;
		offset.y = 150;
		SDL_BlitSurface( message[0].daj_surf(), NULL, ekran, &offset );
	}

	if(pokaz[1]==2)
	{
		SDL_Rect offset;
		offset.x = 1050;
		offset.y = 260;
		SDL_BlitSurface( message[1].daj_surf(), NULL, ekran, &offset );
	}

	if(pokaz[2]==2)
	{
		SDL_Rect offset;
		offset.x = 1050;
		offset.y = 390;
		SDL_BlitSurface( message[2].daj_surf(), NULL, ekran, &offset );
	}

	if(pokaz[3]==2)
	{
		SDL_Rect offset;
		offset.x = 1050;
		offset.y = 510;
		SDL_BlitSurface( message[3].daj_surf(), NULL, ekran, &offset );
	}
}

void Obsluga_SDL::spacja_dzialanie(Obiekt_SDL  & menu, int & x,Obiekt_SDL napis[],Obiekt_SDL  & dlon,Obiekt_SDL obiekt[],bool chwyt[8], bool & klik, int pokaz[4], int & licznik_obiektow  )
{

	x=0;
	menu.ustaw_xy(340,180);
	napis[0].ustaw_xy(350,220);
	napis[1].ustaw_xy(360,265);
	napis[2].ustaw_xy(360,300);
	napis[3].ustaw_xy(365,340);
	dlon.ustaw_xy(0,0);
	obiekt[0].ustaw_xy(29,262);
	obiekt[1].ustaw_xy(109,272);
	obiekt[2].ustaw_xy(160,272);
	obiekt[3].ustaw_xy(210,272);
	obiekt[4].ustaw_xy(240,242);
	obiekt[5].ustaw_xy(590,252);
	obiekt[6].ustaw_xy(650,262);
	obiekt[7].ustaw_xy(890,170);
	while(x<8)
	{
		chwyt[x]=true;
		x++;
		klik=false;
	}

	licznik_obiektow=0;
}

void Obsluga_SDL::reset()
{
	
}

