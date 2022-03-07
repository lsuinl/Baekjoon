#include <iostream>

using namespace std;

int main() {
	int l, a, b, c, d, result;
	cin >> l >> a >> b >> c >> d;
	if (b / d > a / c)
		if (b % d == 0)
			result = l - b / d;
		else
			result = l - b / d - 1;
	else
		if (a % c == 0)
			result = l - a / c;
		else
			result = l - a / c - 1;
	cout << result;
}
