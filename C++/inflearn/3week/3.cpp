// #include <iostream>
// #include <vector>

// using namespace std;

// int n;

// class people{
//     public:
//     char name;
//     int stat;
// };

// int point(people suin[],int number){
//     char name=suin[number].name;
//     int stat=suin[number].stat;
//     int result=0;
//     for(int i=0;i<n;i++){
//         if(name!=suin[i].name){
//             if(stat>suin[i].stat){
//                 result+=suin[i].stat;
//             }
//         }
//     }

//     return result;
// }

// int main(){
//     cin>>n;
//     people suin[n];
//     for(int i=0;i<n;i++){
//         cin>>suin[i].name>>suin[i].stat;
//     }

//     for(int i=0;i<n;i++){
//         cout<<point(suin, i)<<'\n';
//     }
//     return 0;
// }

#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    
    multimap<char, int> suin;
    char a[n];
    int b[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        suin.insert(pair<char,int>(a[i],b[i]));
    }
    for(int i=0;i<n;i++){
        int name=a[i];
        int stat=b[i];
        int result=0;
        multimap<char,int>::iterator checkdown=suin.lower_bound(name);
        multimap<char,int>::iterator checkup=suin.upper_bound(name);
        multimap<char,int>::iterator check;
        for(check=suin.begin();check!=checkdown;check++)
            if(check->second<stat)  result+=check->second;
        for(check=checkup;check!=suin.end();check++)
            if(check->second<stat)  result+=check->second;
        cout<<result<<"\n";
    }
    return 0;
}