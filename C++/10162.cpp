#include <iostream>

using namespace std;

int main() {
	int t, a, b, c;
	cin >> t;
	a = t / 300;
	b = (t % 300) / 60;
	c = (t % 300) % 60 / 10;
	if (t % 10 == 0) {
		cout << a << " " << b << " " << c;
	}
	else
		cout << -1;
}