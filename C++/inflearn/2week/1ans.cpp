#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <_ctype.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	string a;
	int sum=0, res=0;
	cin>>a;
	for(char x : a){
		if(isdigit(x)) res=res*10+(x-48);
		else{
			sum+=res;
			res=0;
		}
	}
	cout<<sum+res;
	return 0;
}