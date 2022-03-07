#include <iostream>

using namespace std;

int main() {
	int inp, a,b;
	cin >> inp;
	if (inp > 1000) {
		a = 10;
		b = 10;
	}
	else if (inp > 100) {
		if (inp % 10 == 0) {
			a = inp / 100;
			b = 10;
		}
		else {
			a = 10;
			b = inp % 10;
		}

	}
	else {
		a = inp / 10;
		b = inp % 10;
	}

	cout<<a+b;
	return 0;
}