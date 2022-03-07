#include <iostream>

using namespace std;
int main() {
	int burger, drink, minburger = 2000, mindrink = 2000;
	for (int i = 0; i < 3; i++) {
		cin >> burger;
		if (minburger > burger)
			minburger = burger;
	}
	for (int i = 0; i < 2; i++) {
		cin >> drink;
		if (mindrink > drink)
			mindrink = drink;
	}

	cout << mindrink + minburger - 50;

}
