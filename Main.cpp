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

//code 1
int oddSum(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		//sum of n numbers
		//return n + oddSum(n - 1);
		if (n % 2 == 1) {
			return n + oddSum(n - 1);
		}
		else {
			return oddSum(n - 1);
		}
	}
}

//code 2
int itRec = 0;

int recBillets(const int max, int cmp) {
	
	int mb25 = 0, mb16 = 0, mb1 = 0;

	//1st call
	if (cmp == 0) {
		int res = max % bMax;
		if (res > sMin) {
			mb1 = res %sMin;
			mb16 = floor(res / sMin);
		}
		else {
			mb1 = res;
		}

		mb25 = floor(max / bMax);
		itRec = mb25 - 1;
		cmp = mb25 + mb16 + mb1;

		return recBillets(max, cmp);
	}

	if (itRec == 0) {
		return cmp;
	}
	else {
		int reste = max - (itRec*bMax);
		mb1 = reste % sMin;
		mb16 = floor(reste / sMin);
		int cmp2 = itRec + mb1 + mb16;
		if (cmp2 < cmp) {
			cmp = cmp2;
		}
		itRec--;
		return recBillets(max, cmp);
	}	
}

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

//code 4
double regress(double x) {
	return -2.5871740461643640e+000 * pow(x, 0)
		+ 8.6042714823477581e+002 * pow(x, 1)
		+ -2.2824637597271503e+003 * pow(x, 2)
		+ 2.4002782690356726e+003 * pow(x, 3)
		+ -1.3311640388068954e+003 * pow(x, 4)
		+ 4.3221987458079934e+002 * pow(x, 5)
		+ -8.5097881486796553e+001 * pow(x, 6)
		+ 1.0020573969648803e+001 * pow(x, 7)
		+ -6.5108498698443973e-001 * pow(x, 8)
		+ 1.8084251841408546e-002 * pow(x, 9);
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
			int in;

			cout << "Combien de nombre pour la somme" << endl;
			cin >> in;

			cout << oddSum(in) << endl;

			break;
		}
		case 'b': {
			int in;

			cout << "Quel est le nombre" << endl;
			cin >> in;

			cout << recBillets(in, 0) << endl;

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
			double in;
			cout << "Input please " << endl;
			cin >> in;

			cout << round(regress(in)) << endl;

			break;
		}
		default:
			break;
		}

	} while (inp != 'q');

	system("PAUSE");

	return 0;
}