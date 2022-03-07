#include <iostream>

using namespace std;

int main() {
	int a, avg = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		if (a < 40)
			a = 40;
		avg += a;
	}
	cout << avg / 5;

}
