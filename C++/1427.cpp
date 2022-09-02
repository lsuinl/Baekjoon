#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char n[11];
	cin >> n;
	for (int j = 0; j < strlen(n); j++) {
		for (int i = 0; i < strlen(n); i++) {
			int z;
			if (n[j] > n[i]) {
				z = n[i];
				n[i] = n[j];
				n[j] = z;
			}
		}
	}

	cout << n;

	return 0;
}