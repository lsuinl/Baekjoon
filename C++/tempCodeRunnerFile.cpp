#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,x,result=0;
    vector<int> lists={};
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        lists.push_back(num);
    }
    cin>>x;
    for(int i=0;i<lists.size();i++){
        if(find(lists.begin(), lists.end(), x-lists[i]) != lists.end()){
            lists.erase(lists.begin()+i);
            lists.erase(find(lists.begin(), lists.end(), x-lists[i]));
            result++;
        }
    }
    cout<<result;
    return 0;
}