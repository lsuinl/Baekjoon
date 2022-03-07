#include <iostream>

using namespace std;

int main() {
	int k, n, m, result;
	
	cin >> k >> n >> m;
	result = (k * n)-m;
	if (result <0)
		result = 0;
	cout << result;

	return 0;
}