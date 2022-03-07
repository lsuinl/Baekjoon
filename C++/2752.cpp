#include <iostream>

using namespace std;

int main() {
	int a, b, c, empty;
	cin >> a >> b >> c;

	if (a > b) {
		empty = a;
		a = b;
		b = empty;
	}
	if (b>c) {
		empty = b;
		b = c;
		c = empty;
	}
	if (a > b) {
		empty = a;
		a = b;
		b = empty;
	}

	cout <<a << " " << b<< " " << c;

	return 0;
}