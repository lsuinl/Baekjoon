#include <iostream>
#include <algorithm>  //min, max�Լ� �� �� �ʿ�
using namespace std;

int main(void) {
	int s, k, h, result;
	cin >> s >> k >> h;
	if (s + k + h >= 100)
		cout << "OK";
	else {
		result = min({ s, k, h });
		if (result == s)
			cout << "Soongsil";
		else if (result == k)
			cout << "Korea";
		else
			cout << "Hanyang";
	}

	return 0;
}