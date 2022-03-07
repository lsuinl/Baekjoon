#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int apple1,apple2 ,orange1, orange2, result;
	cin >> apple1 >> orange1;
	cin >> apple2 >> orange2;

	if (abs(apple1 - apple2) > abs(orange1 - orange2)) {
		if (apple1 > apple2)
			result = apple2 + orange1;
		else
			result = apple1 + orange2;
	}
	else
		if (orange1 > orange2)
			result = orange2 + apple1;
		else
			result = orange1 + apple2;

	cout << result;

	return 0;
}