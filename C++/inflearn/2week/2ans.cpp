#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);

	string S, T;
	int cnt=0;
	unordered_map<char, int> sH, tH;
	cin>>S>>T;
	for(auto x : T) tH[x]++;
	int L=T.size()-1;
	for(int i=0; i<L; i++) sH[S[i]]++;
	int lt=0;
	for(int rt=L; rt<S.size(); rt++){
		sH[S[rt]]++;
		if(sH==tH) cnt++;
		sH[S[lt]]--;
		if(sH[S[lt]]==0) sH.erase(S[lt]);
		lt++;
	}
	cout<<cnt<<endl;
	return 0;
}

