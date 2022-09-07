#include <iostream>

using namespace std;

int main()
{

    int suin[11];
    
    suin[1]=1, suin[2]=2, suin[3]=4;
    for(int i=4;i<11;i++){
        suin[i]= suin[i-1]+suin[i-2]+suin[i-3];
    }   

    int t;
    cin>>t;
    for(int i=0; i<t;i++){
        int n; //반복문 안에서 선언해야함
        cin>>n;
        cout<<suin[n]<<endl;
    }
}

//필요한 식:
//1,2,3은 기본으로 이전의 자연수가 없으므로 따로 세어 지정.
//4부터 11까지적용
//만약 4를 만드는 경우의 수를 구하는 경우,
//3인 상태에서1을 더하는 경우, 2인상태에서 2를 더하는 경우, 1인 상태에서 1을 더하는 경우가 필요함
//다른 숫자들도 마찬가지, 11인경우에도 10인상태+1, 9+2, 8+3이다.
//따라서, 규칙을 따르게 되면 i의 경우의 수는= i-3, i-2, i-1의 합이다.