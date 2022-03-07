#include <iostream>
//수학시러
using namespace std;

int main(void) {
	int inp, result;
	cin >> inp;
	result = inp % 8;
	if (result == 1)
		cout << 1;
	else if (result == 2 || result == 0)
		cout << 2;
	else if (result == 3 || result == 7)
		cout << 3;
	else if (result == 4 || result == 6)
		cout << 4;
	else
		cout << 5;

	return 0;
}