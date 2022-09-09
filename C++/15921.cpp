#include <iostream>

using namespace std;

int main()
{
	int count, suin, avg = 0;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		if (count == 0)
		{
			cout << "divide by zero";
			break;
		}
		cin >> suin;
		avg += suin;
	}
	if (avg == 0)
		cout << "divide by zero";
	else
		cout << "1.00";

	return 0;
}