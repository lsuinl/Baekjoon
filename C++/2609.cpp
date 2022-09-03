#include <iostream>

using namespace std;

int suin(int a, int b) {
    //최대공약수
	int r;
	while (b != 0) {
		r = a % b; //나눈 나머지 r
		a = b; //작은 수를 a로
		b = r; //나머지를 b로
	}
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;

    //a*b=최대공약수*최소공배수
	cout << suin(a,b) << endl << (a*b)/suin(a,b);
	return 0;
}