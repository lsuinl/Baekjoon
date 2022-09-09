#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b;
	cin>>c>>d;

	int result=min(a+d,b+c);
	cout<<result;
}
