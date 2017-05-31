//============================================================================
// Name        : package_problem.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include "Towar.h"

using namespace std;

int main() {
	cout << "Knapsack problem" << endl;

	Towar test("Naszyjnik", 123.89, 15);  // nazwa, cena, masa

	test.wyswietl();

	return 0;
}
