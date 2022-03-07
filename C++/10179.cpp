#include <iostream>

using namespace std;

int main() {
	int number;
	
	cin >> number;

	for (int i = 0; i < number; i++) {
		double a, result;
		
		cin >> a;
		result = 0.8 * a;
		printf("$%.2lf\n",result);
	}
	return 0;
}

/*
#include <iostream>

using namespace std;

int main() {
	int number;
	
	cin >> number;

	for (int i = 0; i < number; i++) {
		double a, result;
		
		cin >> a;
		cout << fixed; //고정
		cout.precision(2);//소수점 2째자리까지, https://blog.naver.com/vot768/222595610427
		result = 0.8 * a;
		cout << "$" << result<<endl;
	}
	return 0;
}*/