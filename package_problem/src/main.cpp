//============================================================================
// Name        : package_problem.cpp
// Author      : Michał Wieczorek, Artur Szafraniak
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================


#include "Towar.h"
#include "Magazyn.h"
#include "plecak.h"
#include "Obiekt_SDL.h"
#include "Obsluga_SDL.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

using namespace std;


/************************************************/

int main() {
	int licznik8=0;
	bool klik=false;
	int* tab=NULL;	//tablica zawierajaca numery przedmiotow
	int wartosc[4];
	int pokaz[4];
	bool algorytm[4]={false,false,false,false};
	bool chwyt[8];
	SDL_Rect myszka;
	SDL_Init( SDL_INIT_EVERYTHING );
	TTF_Init();
	TTF_Font *font = NULL;
	font = TTF_OpenFont( "cz.otf", 20 );
	
	bool wyjscie=false;
	SDL_Event zdarzenie;
	int miejsce_plecak=12; // ile ma masy w sobie plecak (tzn ile uniesie, "x" gram) 
	int miejsca_jubilera=8; // ile bedzie obiektow u jubilera
	int rozmiar_plecaka=0;
	int licznik_obiektow=0;

	cout <<"dzialam"<<endl;

	Obiekt_SDL tlo("tlo.bmp" ,0,0,0,0);
	Obiekt_SDL obiekt[8];


	Obsluga_SDL OB(1241,576);




	obiekt[0].dodaj("pierscionek.bmp",65,61,29,262);
	obiekt[1].dodaj("pierscionek2.bmp",30,30,109,272);
	obiekt[2].dodaj("zegarek1.bmp",43,32,160,272);
	obiekt[3].dodaj("zegarek2.bmp",34,32,210,272);
	obiekt[4].dodaj("kolczyki.bmp",101,76,240,242);
	obiekt[5].dodaj("lancuszek.bmp",25,55,590,252);
	obiekt[6].dodaj("naszyjnik.bmp",50,61,650,262);
	obiekt[7].dodaj("naszyjnik2.bmp",133,102,890,170);

	Obiekt_SDL menu("menu.bmp",250,305,340,180);
	Obiekt_SDL dlon("dlon.bmp",0,0,0,0);
	Obiekt_SDL plecak("plecak.bmp",0,0,100,350);
	Obiekt_SDL napis[4];
	Obiekt_SDL mes[4];

	napis[0].dodaj("napis1.bmp",178,45,350,220);
	napis[1].dodaj("napis2.bmp",170,28,360,265);
	napis[2].dodaj("napis3.bmp",214,34,360,300);
	napis[3].dodaj("napis4.bmp",180,23,365,340);

	mes[0].dodaj(170);
	mes[1].dodaj(220);
	mes[2].dodaj(225);
	mes[3].dodaj(235);



	while( !wyjscie )
	{
	OB.pokaz_tlo(tlo);
	OB.pokaz(menu);
	OB.pokaz(dlon);
	OB.pokaz(plecak);
	OB.pokaz_tablice(obiekt,8);
	OB.pokaz_tablice(napis,4);
	OB.sprawdzam2(pokaz,mes);
	
	OB.flip();
		if(klik==true && licznik_obiektow<rozmiar_plecaka)
		{		
			if( (dlon.daj_miejsce()).x < (obiekt[tab[licznik_obiektow]].daj_miejsce()).x && chwyt[tab[licznik_obiektow]]==false)
			{
					dlon.ustaw_xy((dlon.daj_miejsce()).x+1,(dlon.daj_miejsce()).y);
			}	else if( (dlon.daj_miejsce()).x > (obiekt[tab[licznik_obiektow]].daj_miejsce()).x && chwyt[tab[licznik_obiektow]]==false)
					{
					dlon.ustaw_xy((dlon.daj_miejsce()).x-1,(dlon.daj_miejsce()).y);
					}
			if( (dlon.daj_miejsce()).y < (obiekt[tab[licznik_obiektow]].daj_miejsce()).y && chwyt[tab[licznik_obiektow]]==false)
			{
					dlon.ustaw_xy((dlon.daj_miejsce()).x,(dlon.daj_miejsce()).y+1);
			}	else if( (dlon.daj_miejsce()).y > (obiekt[tab[licznik_obiektow]].daj_miejsce()).y && chwyt[tab[licznik_obiektow]]==false)
					{
					dlon.ustaw_xy((dlon.daj_miejsce()).x,(dlon.daj_miejsce()).y-1);
					}


			if( (dlon.daj_miejsce()).y == (obiekt[tab[licznik_obiektow]].daj_miejsce()).y && (dlon.daj_miejsce()).x == (obiekt[tab[licznik_obiektow]].daj_miejsce()).x && chwyt[tab[licznik_obiektow]]==false )
			{
				chwyt[tab[licznik_obiektow]]=true;
				obiekt[tab[licznik_obiektow]].ustaw_xy(200,450);
				licznik_obiektow++;
			}
		}

		if(licznik_obiektow==rozmiar_plecaka)
		{
			OB.sprawdzam1(pokaz);
		}

		while( SDL_PollEvent( & zdarzenie ) )
		{	
           		if( zdarzenie.key.keysym.sym == SDLK_SPACE )
           		{
				OB.spacja_dzialanie(menu,licznik8,napis,dlon,obiekt,chwyt,klik,pokaz,licznik_obiektow);
            		}

			wyjscie=OB.esc(zdarzenie);
			if( OB.ruch(zdarzenie) )
			{
				myszka.x = OB.ruchx(zdarzenie);
				myszka.y = OB.ruchy(zdarzenie);
			}	

			if(  OB.klik(zdarzenie) )
			{
				algorytm[0]=OB.klik_alg(zdarzenie,myszka,napis[0]);
				algorytm[1]=OB.klik_alg(zdarzenie,myszka,napis[1]);
				algorytm[2]=OB.klik_alg(zdarzenie,myszka,napis[2]);
				algorytm[3]=OB.klik_alg(zdarzenie,myszka,napis[3]);
				tab=OB.myszka1(algorytm,miejsca_jubilera,miejsce_plecak,rozmiar_plecaka,wartosc,pokaz);
				OB.myszka2(licznik8,napis,chwyt,klik,menu);
			}


		}
	
	}

	menu.clean();
	dlon.clean();
	tlo.clean();
	plecak.clean();

	obiekt[0].clean();
	obiekt[1].clean();
	obiekt[2].clean();
	obiekt[3].clean();
	obiekt[4].clean();
	obiekt[5].clean();
	obiekt[6].clean();
	obiekt[7].clean();

	napis[0].clean();
	napis[1].clean();
	napis[2].clean();
	napis[3].clean();

	mes[0].clean_t();
	mes[1].clean_t();
	mes[2].clean_t();
	mes[3].clean_t();
	delete tab;
	TTF_CloseFont( font );
	TTF_Quit();
	SDL_Quit();
	return 0;
}

