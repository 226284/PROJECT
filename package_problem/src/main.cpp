//============================================================================
// Name        : package_problem.cpp
// Author      : Michał Wieczorek, Artur Szafraniak
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "Towar.h"
#include "Magazyn.h"

using namespace std;

vector<string> explode(string const & s, char delim) {
	vector<string> result;
	istringstream iss(s);

	for (string token; getline(iss, token, delim);) {
		result.push_back(move(token));
	}

	return result;
}

void czytaj(string nazwa) {
	vector<string> tab;
	cout << nazwa << endl;
	fstream plik;
	plik.open(nazwa.c_str(), ios::in);
	if (plik.good()) {
		string napis;
		cout << "Zawartosc pliku:" << endl;
		while (!plik.eof()) {
			getline(plik, napis);

			tab = explode(napis, ' ');
			for (unsigned int i = 0; i < tab.size(); i++) {
				cout << tab[i] << " ";
			}
			cout << endl;
		}
		plik.close();
	}
	else
		cout << "Error! Nie udalo otworzyc sie pliku!" << endl;
}

int main() {
	cout << "Knapsack problem" << endl;

	string o = "dane.txt";
	czytaj(o);
	string li = "123";
	int dwa = stoi(li);
	int trzy = 3;
	int wynik = trzy * dwa;
	cout << wynik << endl;

	Magazyn jubiler(5);			// stworzenie tablicy na przedmioty w sklepie
	Towar przedmiot1("Naszyjnik", 300, 15); // stworzenie przykładowego towaru
	Towar przedmiot2("Pierścionek", 60, 20);
	Towar przedmiot3("kolczyki", 100, 8);
	Towar przedmiot4("zegarek", 300, 16);
	Towar przedmiot5("lancuch", 250, 23);

	jubiler.dodaj(przedmiot1, 0); 	//dodanie towaru do magazynu
	jubiler.dodaj(przedmiot2, 1);
	jubiler.dodaj(przedmiot3, 2);
	jubiler.dodaj(przedmiot4, 3);
	jubiler.dodaj(przedmiot5, 4);
	//jubiler.dodaj(przedmiot5, 4);

	//jubiler.sort3();
	cout << endl;

	jubiler.knapsack(30);

	jubiler.wyswietl_knap();

	return 0;
}
