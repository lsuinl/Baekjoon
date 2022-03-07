#include <iostream>

using namespace std;

int main() {
	int day, a, result = 0;
	cin >> day;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		if (a == day)
			result++;
	}
	cout << result;

	return 0;
}