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
		cout << fixed; //����
		cout.precision(2);//�Ҽ��� 2°�ڸ�����, https://blog.naver.com/vot768/222595610427
		result = 0.8 * a;
		cout << "$" << result<<endl;
	}
	return 0;
}*/