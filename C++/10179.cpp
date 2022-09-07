#include <iostream>

using namespace std;

int main() {
	int number;
	
	cin >> number;

	for (int i = 0; i < number; i++) {
		double a, result;
		
		cin >> a;
		result = 0.8 * a;
		printf("$%.2lf\n",result);
	}
	return 0;
}
