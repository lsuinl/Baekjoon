#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int d, h, w;
	cin >> d >> h >> w;
	double a = sqrt((d * d) / double(h * h + w * w));//double 넣은 이유 기억

	cout << int(a * h) << " " << int(a * w) << endl;
}
