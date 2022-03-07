#include <iostream>
#define pi 3.141592;
using namespace std;

int main() {
	int d1, d2;
	double result;

	cin >> d1 >> d2;
	result = (d1 * 2) + (d2+d2)*pi;
	printf("%.6lf", result);
	return 0;
}