/*
Jerry
Math-pro5
main.cpp
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int bMax = 25;
const int sMin = 16;

//code 3
int iterBillets(int max) {

	int mb25=0, mb16=0, mb1=0;

	//1st
	int res = max % bMax;
	
	if (res > sMin) {
		mb1 = res % sMin;
		mb16 = floor(res / sMin);
	}
	else {
		mb1 = res;
	}
	mb25 = floor(max / bMax);
	
	int cmp = mb25 + mb16 + mb1;

	//rest
	for (int i = mb25 - 1; i != 0; i--) {
		int reste = max - (i*bMax);
		mb1 = reste % sMin;
		mb16 = floor(reste / sMin);
		int cmp2 = i + mb1 + mb16;
		if (cmp2 < cmp) {
			cmp = cmp2;
		}
	}

	return cmp;
}

int main() {

	char inp;

	do
	{
		cout << "MENU" << endl;
		cout << "A: algo somme impair rec" << endl;
		cout << "B: billets minimum rec" << endl;
		cout << "C: billets minimum iter" << endl;
		cout << "D: N retour N" << endl;
		cout << "Q: quitter" << endl;
		cout << "Enter votre choix" << endl;
		cin >> inp;

		inp = tolower(inp);

		switch (inp)
		{
		case 'a': {

			break;
		}
		case 'b': {

			break;
		}
		case 'c': {
			int in;

			cout << "Quel est le nombre" << endl;
			cin >> in;

			cout << iterBillets(in) << endl;

			break;
		}
		case 'd': {


			break;
		}
		default:
			break;
		}

	} while (inp != 'q');

	system("PAUSE");

	return 0;
}