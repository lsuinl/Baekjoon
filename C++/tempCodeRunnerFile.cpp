#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

int main(){
    stack<int> s;
    vector<int> v;
    int n; cin>>n;

    v.resize(n);
    for(int i=0;i<n;i++){
        int a;  cin>>a;
        s.push(a);
        v[i]=a;
    }

    int maxx=s.top();
    v[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        if(v[i]<s.top())
            v[i]=s.top();
        else if(v[i]<maxx)
            v[i]=maxx;
        else
            v[i]=-1;
        maxx = s.top()>maxx?s.top():maxx;
        s.pop();
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}