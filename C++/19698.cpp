#include <iostream>

using namespace std;

int main(void) {
	int n, w, h, l, result;
	cin >> n >> w >> h >> l;
	result = (w / l) * (h / l);
	if (n < result)
		result = n;
	cout << result;

	return 0;
}