#include <iostream>

using namespace std;

int main() {
	int n, m, k, o,x; //n=�� ī��, m=�ո� o, n=�޸� o;
	cin >> n >> m >> k;
	if (m > k)
		o = k;
	else
		o = m;
	
	if (n - m > n - k)
		x = n - k;
	else
		x = n - m;

	cout << o + x;
	return 0;
}