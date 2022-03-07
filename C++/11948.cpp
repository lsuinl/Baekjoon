#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a[6], result = 0;
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
		result += a[i];
	}
	result = result - min(min( a[0],a[1]),min(a[2],a[3])) - min(a[4], a[5]);
	cout << result;
	return 0;
}