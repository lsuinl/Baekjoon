#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n;
	cin>>n;
	stack<int> s;
	vector<int> h(n+1), res(n+1, 0);
	for(int i=1; i<=n; i++){
		cin>>h[i];
	}
	for(int i=n; i>=1; i--){
		while(!s.empty() && h[i]>h[s.top()]){
			res[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	for(int i=1; i<=n; i++){
		cout<<res[i]<<" ";
	}
	return 0;
}



// 타임리미트 나는 O(n^2)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	ios_base::sync_with_stdio(false);
// 	//freopen("input.txt", "rt", stdin);
// 	int n;
// 	cin>>n;
// 	vector<int> h(n+1), res(n+1);
// 	for(int i=1; i<=n; i++){
// 		cin>>h[i];
// 	}
// 	for(int i=n; i>=1; i--){
// 		for(int j=i-1; j>=1; j--){
// 			if(h[j]>h[i]){
// 				res[i]=j;
// 				break;
// 			}
// 		}
// 	}
// 	for(int i=1; i<=n; i++){
// 		printf("%d ", res[i]);
// 	}	
// 	return 0;
// }