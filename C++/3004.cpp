#include <iostream>
//https://jaimemin.tistory.com/1567
using namespace std;

int main() {
	int n, rkfh, tpfh;
	cin >> n;
	rkfh = n / 2 + 1;
	tpfh = n - rkfh + 2;
	cout << rkfh * tpfh;

	return 0;
}