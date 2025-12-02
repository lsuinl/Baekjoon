#include <iostream>
#include <vector>
#include <climits>
//이분탐색 적용
using namespace std;

vector<int> sqlid;
int n;
int a,b,minSum=INT_MAX;

void binary(int fix,int start, int end){
    if(start>end)
        return;
    int mid = (start+end)/2;
    int sum = sqlid[fix]+sqlid[mid];

    if(abs(sum)<abs(minSum)){ //최소.
        minSum=sum;
        a=sqlid[fix];
        b=sqlid[mid];
        //cout<<a<<" "<<b<<endl;
        binary(fix,start,mid-1);
        binary(fix,mid+1,end);
    }
    //이전보다 크면, 작은데부터
    else if(sum>minSum){
        binary(fix,start,mid-1);
    }
    //작으면 큰데부터
    else{
        binary(fix,mid+1,end);
    }
        
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    sqlid.resize(n);
    for(int i=0;i<n;i++){
        cin>>sqlid[i];
    }
    for(int i=0;i<n-1;i++){
        binary(i,i+1,n-1);
    }

    cout<<a<<" "<<b;
    return 0;
}