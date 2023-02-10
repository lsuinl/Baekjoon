#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	string str, res;
    locale e;
	cin>>str;
    for (int i = 0; i < str.size(); i++)
    { // 대문자만들기
        str[i] = toupper(str[i], e);
    }
	unordered_map<char, int> sH, ch;
	for(char x : str) sH[x]++;
	for(char x : str){
		sH[x]--;
		if(ch[x]==1) continue;
		while(res.size()!=0 && res.back()>x && sH[res.back()]>0){
			ch[res.back()]=0;
			res.pop_back();	
		}
		res.push_back(x);
		ch[x]=1;
	}
	cout<<res;	
	return 0;
}