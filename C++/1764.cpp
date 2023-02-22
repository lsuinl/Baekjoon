#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>

using namespace std;
int N, M;
map<string,int> word; 
vector<string> result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<M+N;i++){
        string name;
        cin>>name;
        word[name]++;
        if (word[name] >1)
            result.push_back(name);
    }
    sort(result.begin(), result.end());
    cout<<result.size()<<"\n";
    for(auto e : result){
        cout<<e<<"\n";
    }

    return 0;
}