#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;
int n, d, k;
int res= 0;//최소왜안됨
void DFS(int L, int s, int bit, vector<int> &st, vector<int> &pow){
	if(L==k){
		int cnt = 0;
		for(int i=1; i<=n; i++) if((bit&st[i])==st[i]) cnt++;
		res=max(res, cnt);
	}
	else{
		for (int i=s; i<=d; i++){
			DFS(L+1, i+1,  bit+pow[i], st, pow);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin >> n >> d >> k;
	vector<int> st(n+1), pow(d+1);
	pow[1]=1;
	for(int i=2; i<=d; i++) pow[i]=pow[i-1]*2;
	for(int i=1; i<=n; i++){
		int m, num;
		cin>>m;
		for(int j=1; j<=m; j++){
			cin>>num;
			st[i]+=pow[num];	
		}
	}
	DFS(0, 1, 0, st, pow);
	cout << res;
	return 0;
}
