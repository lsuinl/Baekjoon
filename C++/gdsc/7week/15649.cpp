// #include <iostream>

// using namespace std;
// int n,m;
// int arr[8]={0,};
// int check[8]={0,};

// void BFS(int number){
//     if(number==n){ //탈출조건
//         return;
//     }
    
//     if(arr[m-1]!=0){
//         for(int i=0;i<m;i++){
//             cout<<arr[i];
//         }
//         cout<<'\n';
//         BFS();
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin>>n>>m;
//     for(int i=0;i<m;i++){
//         check[i]=m-i;
//     }
//     BFS(number+1);
//     return 0;
// }

#include <iostream>

using namespace std;
int n,m;
int arr[9]={0,};
int check[9]={0,};

void DFS(int number){
    if(number==m){ //탈출조건(뽑은 개수가 m개가되면)
    for(int i=0;i<m;i++){
        cout<<arr[i]<<' '; //출력
    } 
    cout<<"\n";
    return;
    }
    
    for(int i = 1; i <= n; i++) 
    {
        if(!check[i])
        {
            check[i] = true; //방문여부체크
            arr[number] = i; //배열에 뽑아낸 숫자 저장
            DFS(number+1);//뽑아낸 개수+1해서 재귀
            check[i] = false; //false로 초기화해서 다른 DFS에 지장없도록 함s
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    DFS(0);
    return 0;
}