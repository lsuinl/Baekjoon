#include <iostream>

using namespace std;

int main()
{
	int n, num[10] = {}, maxx = -1, suin = 0;

	cin >> n;
	while (n >= 10)
	{
		num[n % 10]++;
		n /= 10;
	}

	num[n]++;
	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)
			suin += num[i];
		else
			maxx = max(maxx, num[i]);
	}
	maxx = max(maxx, (suin + 1) / 2);
	cout << maxx;
}
