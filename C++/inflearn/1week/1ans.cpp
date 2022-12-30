#include<iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n, len=__INT_MAX__;
	string str;
	cin>>n;
	vector<string> words;
	for(int i=0; i<n; i++){
		cin>>str;
		words.push_back(str);
		len=min(len, int(str.size()));
	}
	string res="";
	for(int i=0; i<len; i++){
		string tmp="";
		for(auto &s : words) tmp+=s[i];
		int m=count(tmp.begin(), tmp.end(), tmp[0]);
		if(m==n) res+=tmp[0];
		else break;
	}
	cout<<res;
	return 0;
}




// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	ios_base::sync_with_stdio(false);
// 	//freopen("input.txt", "rt", stdin);
// 	int n, len=INT_MAX;
// 	string str;
// 	cin>>n;
// 	vector<string> words;
// 	for(int i=0; i<n; i++){
// 		cin>>str;
// 		words.push_back(str);
// 		len=min(len, int(str.size()));
// 	}
// 	string res="";
// 	for(int i=0; i<len; i++){
// 		set<char> tmp;
// 		for(auto &s : words) tmp.insert(s[i]);
// 		if(tmp.size()==1) res+=words[0][i];
// 		else break;
// 	}
// 	cout<<res;
// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	ios_base::sync_with_stdio(false);
// 	//freopen("input.txt", "rt", stdin);
// 	int n, len=INT_MAX;
// 	string str;
// 	cin>>n;
// 	vector<string> words;
// 	for(int i=0; i<n; i++){
// 		cin>>str;
// 		words.push_back(str);
// 	}
// 	string res=words[0];
// 	for(int i=1; i<words.size(); i++){
// 		while(words[i].find(res)!=0){
// 			res=res.substr(0, res.size()-1);
// 		}
// 	}
// 	cout<<res;
// 	return 0;
// }


