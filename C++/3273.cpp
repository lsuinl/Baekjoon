#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n,x,result=0;
    vector<int> lists={};
    map<int, bool> num={};
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        lists.push_back(a);
        num[a]=true;
    }
    sort(lists.begin(),lists.end());
    cin>>x;
    for(int i=0;i<(n/2+1);i++){
        if(num[x-lists[i]]==true)
            result++;
    }
    cout<<result;
    return 0;
}