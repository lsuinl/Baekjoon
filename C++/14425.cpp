#include <iostream>
#include <map>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    map<string, bool> answer;
    int sum=0;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        answer[a]=true;
    }
    for(int i=0;i<m;i++){
        string a;
        cin>>a;
        if(answer[a]==true)
            sum++;
    }
    cout<<sum;
    return 0;
}