#include <iostream>

using namespace std;
int main() {
	long a, b, c, result;
	cin >> a >> b >> c;

	result = c - b;
	if (result <= 0)
		result = -1;
	else
		result = a / result + 1;

	cout << result;
}
