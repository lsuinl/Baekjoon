#include <iostream>
using namespace std;

int main() {
	int n, width, length;
	cin >> n;
	width = n / 2 + 1;
	length = n - length + 2;
	cout << width * length;

	return 0;
}