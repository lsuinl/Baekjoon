#include <iostream>

using namespace std;

int main(){
    int N,B,C;
    long long result=0;
    cin>>N;

    int member[N];
    for(int i=0;i<N;i++) 
        cin>>member[i]; //응시생수
    
    cin>>B>>C;
    
    for(int i=0;i<N;i++){
        result++;
        member[i]-=B;
        int cpeople = member[i] % C ==0 ? member[i]/C:member[i]/C+1;
        if(member[i]>0) result+=cpeople;
    }
    cout<<result;
    return 0;
}