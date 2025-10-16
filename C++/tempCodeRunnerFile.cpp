#include <iostream>
#include <set>
#include <deque>
using namespace std;

int n,m;
set<int> s;

void pickNum(deque<int> list){
    cout<<"냥";
    if(list.size()==m){
        for(int x : list){
            cout<<x<<" ";
        }
        cout<<"\n";
    } 
    else{
        for (int x : s) {

            if(list.empty()||list.back()<=x){
                list.push_back(x);
                pickNum(list);
                list.pop_back();
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.insert(a);
    }

    deque<int> d;
    pickNum(d);
    return 0;
}