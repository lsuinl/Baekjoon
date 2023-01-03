#include <iostream>

using namespace std;

int main(){
    int T;
    int n,a;
    cin>>T;
    for(int i=0;i<T;i++){
        int result=1;
        cin>>n; //사원의 수
        int b[n];

        for(int j=0;j<n;j++){ //서류점수와 면접점수
            cin>>a; //서류성적
            cin>>b[a-1]; //면접성적(등수별로 저장)
        }
        int cutline=b[0]; 
        for(int j=1;j<n;j++){ 
            if(cutline>b[j]){
                result++;
                cutline=b[j];
            }
        }
        cout<<result<<endl;
    }    
    return 0;
}