#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int n;
    map<string,int> book;
    cin>>n;
    for(int i=0;i<n;i++){
        string bookname;
        cin>>bookname;
        book[bookname]++;
    }
    string result;
    int cmp=0;
    for(auto e : book){
        if(cmp<e.second){
            cmp=e.second;
            result=e.first;
        }
    }
    cout<<result;
    return 0;
}