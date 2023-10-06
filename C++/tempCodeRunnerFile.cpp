#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    long long n,m,result=0,sum,min;
    vector<int> tree;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int length;
        cin>>length;
        tree.push_back(length);
    }

    sort(tree.begin(),tree.end());
    int slice = tree[tree.size()/2]<m ?0:(tree[tree.size()/2]-m);
    do{
        sum=0;
        for(int i=0;i<tree.size();i++){
            sum+=(tree[i]-slice)>0 ? (tree[i]-slice):0;
        }
        if(sum>=m && min>=sum){
            min=sum;
            result=slice;
        }
        if(sum>=m)
            slice=(tree[tree.size()-1]+slice)/2;
        else if(sum<m)
            slice=slice/2;
    }while(sum>=m);

    cout<<result;
    return 0;
}