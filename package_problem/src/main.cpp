//============================================================================
// Name        : package_problem.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include "Towar.h"
#include "Magazyn.h"

using namespace std;

int main() {
	cout << "Knapsack problem" << endl;

	Magazyn jubiler(20);				// stworzenie tablicy na przedmioty w sklepie
	Towar przedmiot1("Naszyjnik", 123.89, 15); // stworzenie przykładowego towaru
	Towar przedmiot2("Pierścionek", 599.99, 20);

	jubiler.dodaj(przedmiot1, 0); 	//dodanie towaru do magazynu
	jubiler.dodaj(przedmiot2, 1);
	jubiler.wyswietl();
	cout << endl;

	jubiler.usun(0);		// usunięcie towaru z magazynu
	jubiler.wyswietl();

	return 0;
}
