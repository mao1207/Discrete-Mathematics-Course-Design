#include <iostream>
using namespace std;
int main()
{
	int A, B, C, D, E;
	E = 0;
	D = 0;
	for (A = 0; A <= 1; A++)
		for (B = 0; B <= 1; B++)
			for (C = 0; C <= 1; C++)
				if ((A || B) && (!A || C) && (D || !C))
					cout << "A=" << A << "," << "B=" << B << endl;
	return 0;
}