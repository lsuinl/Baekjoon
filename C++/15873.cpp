#include <iostream>

using namespace std;

int main()
{
	int inp, a, b;
	cin >> inp;
	if (inp > 100)
	{
		if (inp % 10 == 0)
		{
			a = inp / 100;
			b = 10;
		}
		else
		{
			a = 10;
			b = inp % 10;
		}
	}
	else
	{
		a = inp / 10;
		b = inp % 10;
	}

	cout << a + b;
	return 0;
}

// int main(){
// 	int n;
// 	cin>>n;
// 	if(100>n)
// 		cout<<n/10+n%10;
// 	else if(n%10 ==0)
// 		cout<<n/100+10;
// 	else
// 		cout<<n%100+10;
// }