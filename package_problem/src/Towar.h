/*
 * Towar.h
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#ifndef TOWAR_H_
#define TOWAR_H_
#include <string>
#include <iostream>


namespace std {

class Towar {
public:
	Towar(string nowa_nazwa = "brak", float nowa_wartosc = 0, float nowa_masa = 9999, int nowy_numer = 0);
	virtual ~Towar();
	// metody do obsługi towaru
	void set_nazwa(string nowa_nazwa);
	void set_wartosc(float nowa_wartosc);
	void set_masa(float nowa_masa);
	string get_nazwa();
	int get_wartosc();
	int get_masa();
	int get_numer();
	void wyswietl();
	void nadaj(string nowa_nazwa,float nowa_wartosc,float nowa_masa, int numer);
private:
	string nazwa;	// nazwa towaru
	int wartosc; 	// wartość w [zł]
	int masa;		// masa w [g]
	int numer;
	//int ilosc; 		// ilość towaru na magazynie
};

} /* namespace std */

#endif /* TOWAR_H_ */
