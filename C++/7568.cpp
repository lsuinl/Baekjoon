#include <iostream>
#include <utility>
#include <vector>
//구조체, 벡터의 활용 https://blog.naver.com/yungzin98/222615915967

using namespace std;
//방법 1: 내가한거
/*
//입력받고, 비교해서 큰 사람 수 카운트하기
void countt(int number, int count[50]) {
	
	int height[50], weight[50];
	for (int i = 0; i < number; i++) {
		cin >> weight[i] >> height[i];
	}
	
	for (int j = 0; j < number; j++) {
		for (int i = 0; i < number; i++) {
			if (weight[j] < weight[i] && height[j] < height[i])
				count[j]++;
			else if (weight[j] == weight[i] && height[j] < height[i])
				count[j]++;
			else if (weight[j] < weight[i] && height[j] == height[i])
				count[j]++;
		}
	}
}

void result(int number, int count[50]) {
	int result[50];
	//큰 사람 수가 적을수록 등수가 높음. 
	for (int j = 0; j < number; j++) {
		result[j] = 1;
		for (int i = 0; i < number; i++) {
			if (count[j] > count[i])
				result[j]++;
		}
	}

	//출력
	for (int j = 0; j < number; j++)
		cout << result[j]<<" ";
}


int main() {
	int number, count[50]={0,};
	cin >> number;

	countt(number,count);
	result(number, count);
	return 0;

}*/
//방법2 utility클래스, pair
/*
int main() {
	int num;
	int rank = 1;
	pair<int, int> arr[50];
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (arr[i].first < arr[j].first && arr[i].second)
				rank++;
			cout << rank << " ";
			rank = 1;
		}
	}
}*/

//구조체, 벡터 <vector>클래스
struct person {
public:
	int height;
	int weight;
	int priority;
	person(int a, int b, int c = 1) {
		height = a;
		weight = b;
		priority = c;
	}
};

vector<person> v;

int main() {
	int PersonNum;
	cin >> PersonNum;
	for (int i = 0; i < PersonNum; i++) {
		int pHeight, pWeight;
		cin >> pHeight >> pWeight;
		person man(pHeight, pWeight);
		v.push_back(man);
	}
	for (int i = 0; i < PersonNum; i++) {
		for (int j = 0; j < PersonNum; j++) {
			if ((v[i].height < v[j].height) && (v[i].weight < v[j].weight)) {
				v[i].priority++;
			}
		}
	}
	for (int i = 0; i < PersonNum - 1; i++) {
		cout << v[i].priority << ' ';
	}
	cout << v[PersonNum - 1].priority;

	return 0;
}