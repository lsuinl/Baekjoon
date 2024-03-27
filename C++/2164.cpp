#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int n;
    cin>>n;
    //버리고,옮기고.버리고,,옮기고
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    while(q.size()>1){
        q.pop();
        if(q.size()==1) break;
        int num=q.front();
        q.pop();
        q.push(num);
    }
    
    cout << q.front();
    
    return 0;
}