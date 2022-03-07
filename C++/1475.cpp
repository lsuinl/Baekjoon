#include <iostream>

using namespace std;

int main(void) {
	int n, num[10] = {}, maxx = -1, suin = 0;
	cin>>n;
	while (n >= 10) { //입력받은 방의 번호가 일의자리숫자가 될 때까지
		num[n % 10]++; //방 번호%10(==점점 자릿수가 줄어드는 방번호의 일의 자리숫자 저장. 
		n /= 10; //방번호 10씩 나누기=>(자릿수가 하나씩 줄어듦)
	}
	num[n]++;
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) //방 번호가 6 또는 9인경우
			suin += num[i];//따로 6과 9의 횟수를 더해서 저장
		else
			maxx = max(maxx, num[i]); //가장 많이 반복되는 숫자 찾기
	}
	maxx = max(maxx, (suin + 1) / 2);//6과 9가 겹치는 횟수를 나누기를 통해서 구하고 반복에서 찾은 최댓값과 비교 
	cout<<maxx;//최댓값 출력
}
