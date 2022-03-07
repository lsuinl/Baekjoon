#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int a, b, c, d, min;
	cin >> a >> b >> c >> d;
	if (abs((a + b) - (c + d)) > abs((a + c) - (b + d)))
		min = abs((a + b) - (c + d));
	else
		min = abs((a + c) - (b + d));

	if (min > abs((a + d) - (b + c)))
		min = abs((a + d) - (b + c));

	cout << min;
}

