#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    //우선순위 큐.(오름차순배열=greater)
    priority_queue<int, vector<int>, greater<int>> q;
    int n;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin>>n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == 0) {//0입력시
			if (q.size()) { //배열에 값이 존재하면
				cout << q.top()<<"\n"; //가장 작은 값 출력
				q.pop();//제거
			}
			else {
				cout << 0 << "\n"; //배열에 값이 없으면 0
			}
		}
		else { //0이 아니면 
			q.push(num); //값 넣기
		}
	}
}
