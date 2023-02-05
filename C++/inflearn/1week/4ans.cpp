#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int n, res = 2147000000, can[2][21], ch[21];
void DFS(int L, int s) {
	if (L == n/2) {
		vector<int> A, B;
		for (int i = 0; i < n; i++) {
			if (ch[i] == 1) A.push_back(i);
			else B.push_back(i);
		}
		int sumA = 0, sumB = 0;
		for (int i = 0; i < A.size(); i++) {
			sumA+=can[0][A[i]];
			sumB+=can[1][B[i]];
		}
        
	//	res =min(res, abs(sumA - sumB)); 오류나서 잠간 주석처리했음
	}
	else {
		for (int i = s; i < n; i++) {
			ch[i] = 1;
			DFS(L+1, i+1);
			ch[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>can[0][i]>>can[1][i];
	}
	DFS(0, 0);
	cout<<res;
	return 0;
}