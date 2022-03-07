#include <iostream>

using namespace std;

int main() {
	int a[10001];

	for (int j = 1; j <= 10000; j++) {
		int result;
		a[j] = j;
		for (int i = 1; i <= 10000; i++) {
			result = i + (i % 10) + ((i%100)/ 10) + ((i % 1000) / 100) + (i / 1000);
			if (j == result) {
				a[j] = 0;
			}
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (a[i] != 0)
			cout << a[i] << endl;
	}

	return 0;
}