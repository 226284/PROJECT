/*
 * Towar.h
 *
 *  Created on: 30 maj 2017
 *      Author: michal
 */

#ifndef TOWAR_H_
#define TOWAR_H_
#include <string>

namespace std {

class Towar {
public:
	Towar();
	virtual ~Towar();
	// metody do obsługi towaru
	// zmien nazwe
	// zmien wartosc
	// zmien mase
private:
	string nazwa;	// nazwa towaru
	float wartosc; 	// wartość w [zł]
	float masa;		// masa w [g]
	//int ilosc; 		// ilość towaru na magazynie
};

} /* namespace std */

#endif /* TOWAR_H_ */
