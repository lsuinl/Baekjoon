// #include <iostream>
// #include <algorithm>

// using namespace std;

// int up(int a, int b){return a < b; } 

// int main()
// {
//     int n;
//     cin >> n;

//     int suin[n];
//     for (int i = 0; i < n; i++)
//         cin >> suin[i];

//     sort(suin, suin + n, up);
    
//     for (int i = 0; i < n; i++)
//         cout << suin[i]<<"\n";

//     return 0;
// }

#include <iostream>

using namespace std;



int main(){
    //c와 c++의 표준 stream의 동기화를 끊어
    //입출력의 속도를 빠르게 만들어줌
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int suin[10001]={0,};

    cin>>n;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        suin[number]++;
    }
    
    for(int i=1;i<10001;i++){
        while(suin[i]!=0){
            cout<<i<<"\n";
            suin[i]--;
        }
    }
    return 0;
}