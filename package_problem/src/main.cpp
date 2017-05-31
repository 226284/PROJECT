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

	Magazyn jubiler(5);				// stworzenie tablicy na przedmioty w sklepie
	Towar przedmiot1("Naszyjnik", 123.89, 15); // stworzenie przykładowego towaru
	Towar przedmiot2("Pierścionek", 599.99, 20);
	Towar przedmiot3("kolczyki", 100, 8);
	Towar przedmiot4("zegarek", 300, 16);
	Towar przedmiot5("lancuch", 276, 23);

	jubiler.dodaj(przedmiot1, 0); 	//dodanie towaru do magazynu
	jubiler.dodaj(przedmiot2, 1);
	jubiler.dodaj(przedmiot3, 2);
	jubiler.dodaj(przedmiot4, 3);
	jubiler.dodaj(przedmiot5, 4);

	jubiler.sort3();
	cout << endl;


	return 0;
}
