#include <iostream>

using namespace std;

int main()
{
	int people, area, a, b, c, d, e, result;
	cin >> people >> area;
	cin >> a >> b >> c >> d >> e;
	result = people * area;

	cout << a - result << " " << b - result << " " << c - result << " " << d - result << " " << e - result;
	return 0;
}