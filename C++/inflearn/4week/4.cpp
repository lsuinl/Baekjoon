#include <iostream>
 //너는? 이번주내로 내가 죽이겠다.
using namespace std;
int n;
char bracket[20];
pair<int,bool> check[20];//first:괄호가왼쪽?오른쪽? , second:방문여부
int result=0;
void DFS(int length, int left, int right){
    if(length==n*2){
        for(int i=0;i<n*2;i++){
            cout<<bracket[i];
        }
        cout<<'\n';
        result++;
        return;
    }
    if(right==left){ //괄호 숫자가 같으면 필수적으로 왼쪽거를 올려줘야해여
        for(int i=0;i<n;i++){
            if(!check[i].second){ 
                check[i].second=true;
                bracket[length]='(';
                DFS(length+1,left+1,right);
                check[i].second=false;
            }
        }
    }
    else{
        for(int i=0;i<n*2;i++){
            if(!check[i].second){ //방문여부체크
            check[i].second=true;
                if(check[i].first==0){
                    bracket[length]='(';
                    DFS(length+1,left+1,right);
                }
                else{
                    bracket[length]=')';
                    DFS(length+1,left,right+1);
                }
            check[i].second=false;
        }
    }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        check[i]={0,false};
    }
    for(int i=n;i<n*2;i++){
        check[i]={1,false};
    }
    DFS(0,0,0);//깊게
    cout<<result;
    return 0;
}