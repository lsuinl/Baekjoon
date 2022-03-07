#include <iostream>

using namespace std;
int suin(int result) {
	int a;
	for (int i = 0; i < 4; i++) {
		cin >> a;
		result += a;
	}
	return result;
}


int main() {
	int s=0, t=0;
	s = suin(s);
	t = suin(t);
	if (s >= t)
		cout << s;
	else
		cout << t;
	return 0;
}