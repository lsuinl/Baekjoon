#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        map<string, int> types;
        set<int> sett;
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            string name, type;
            cin>>name>>type;
            if(types.find(type)!=types.end()){
                types[type]++;
            }
            else{
                types[type]=1;
            }
        }
        int s=1;
        //의상의 종류마다 개수를 카운트해준다.
        //의상의 종류에 그 의상을 입지 않은 경우의 수를 더해서 모두 곱해주고 모두 안 입은 경우의 수 1을 뺸다.
        //ex) headgear(2+1)*eyewear(1+1) - 1 = 5! ..
        //수학미워
        for(auto e : types){
            s*=(e.second+1);
        }
        cout<<s-1<<"\n";
    }

    return 0;
}
//hate math.