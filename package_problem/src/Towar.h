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
	Towar(string nowa_nazwa = "brak", float nowa_wartosc = 0, float nowa_masa = 9999);
	virtual ~Towar();
	// metody do obsługi towaru
	void set_nazwa(string nowa_nazwa);
	void set_wartosc(float nowa_wartosc);
	void set_masa(float nowa_masa);
	string get_nazwa();
	int get_wartosc();
	int get_masa();
	void wyswietl();
private:
	string nazwa;	// nazwa towaru
	int wartosc; 	// wartość w [zł]
	int masa;		// masa w [g]
	//int ilosc; 		// ilość towaru na magazynie
};

} /* namespace std */

#endif /* TOWAR_H_ */
