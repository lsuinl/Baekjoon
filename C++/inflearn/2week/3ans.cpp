#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    // 정의, 입력받기
	long long n, k;
	cin>>n;
	vector<long long> T(n+1);
	for(int i=1; i<=n; i++) cin>>T[i];
	cin>>k;

	vector<long long> sT(T); //T벡터를 복사해서 저장
	sort(sT.begin(), sT.end()); //정렬
	long long rest = n; 
	for(int i=1; i<=n; i++) {
		if(k < (rest * (sT[i] - sT[i-1]))) {
			int index = k % rest;
			int cnt = 0;
			for(int j=1; j<=n; j++){
				if(T[j] >= sT[i]) {
					if(cnt == index) {
						cout<<j;
						return 0;
					}
					cnt++;
				}		
			}
		}
		else{
			k -= (rest * (sT[i] - sT[i-1]));
			rest--;
		}			
	}
	cout<<"-1";
	return 0;
}