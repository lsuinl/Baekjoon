#include <iostream>

using namespace std;
int main() {
	int a, b, c, result,max;
	cin >> a >> b >> c;

	if (a == b && b == c)
		result = 10000 + a * 1000;
	else if (a == b || b == c)
		result = 1000 + b * 100;
	else if (c == a)
		result = 1000 + a * 100;
	else {
		if (a > b)
			max = a;
		else
			max = b;
		if (max < c)
			max = c;
		result = max * 100;
	}
	cout << result;
	}
	 //¸¾¿¡¾Èµê