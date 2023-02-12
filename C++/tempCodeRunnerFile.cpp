#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, M;
vector<string> result,word; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        string name;
        cin>>name;
        word.push_back(name); 
    }
    for(int i=0;i<M;i++){
        string name;
        cin>>name;
        if(find(word.begin(),word.end(),name)!= word.end()){
            result.push_back(name);
        }
    }
    sort(result.begin(),result.end());
    cout<<result.size()<<"\n";
    for(auto e : result){
        cout<<e<<"\n";
    }

    return 0;
}