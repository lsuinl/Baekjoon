#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int kda[3]={0,},cur=0;
	string s;
	getline(cin,s);

	for(int i=0;i<s.length();i++){
		if(s[i]!='/')
			kda[cur]=kda[cur]*10+(s[i]-'0');
		else{
			cur++;
		}
	}
	//cout<<kda[0]<<endl<<kda[1]<<endl<<kda[2]<<endl;
	if(kda[1]==0||kda[0]+kda[2]<kda[1])
	cout<<"hasu";
	else
		cout<<"gosu";
	return 0;
}