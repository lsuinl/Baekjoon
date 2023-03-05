// #include <iostream>
// #include <vector>

// using namespace std;
// int result = 0;
// vector<pair<char, int>> rgb;
// void sorted(int r, int g, int b){
//     if(r<=g && r<=b){
//         rgb.push_back({'r',r});
//         r=1001;
//     }
//     else if(g<=b && g<=r){
//         rgb.push_back({'g',g});
//         g=1001;
//     }
//     else{
//         rgb.push_back({'b',b});
//         b=1001;
//     }

//     if(r<=g && r<=b){
//         rgb.push_back({'r',r});
//         r=1001;
//     }
//     else if(g<=b && g<=r){
//         rgb.push_back({'g',g});
//         g=1001;
//     }
//     else{
//         rgb.push_back({'b',b});
//         b=1001;
//     }
//     if(r!=1001) rgb.push_back({'r',r});
//     else if(g!=1001) rgb.push_back({'g',g});
//     else rgb.push_back({'b',b});
// }

// int main()
// {
//     int n;
//     int r, g, b;
//     char selectrgb;
//     int selectcost;
//     int second;
//     cin>>n;

//     //처음은 가볍게
//     cin >> r >> g >> b;
//     sorted(r,g,b);
//     selectrgb=rgb[0].first;
//     selectcost=rgb[0].second;
//     result+=selectcost;
//     second=rgb[1].second;
//     rgb.clear();
//     for (int i = 1; i < n; i++)
//     {
//         cin >> r >> g >> b;
//         sorted(r,g,b);
//         if(rgb[0].first!=selectrgb){ //색이 다르면 최소값을,, 그대로 더합니다.
//             selectrgb=rgb[0].first;
//             selectcost=rgb[0].second;
//             result+=selectcost;
//             if(rgb[1].first!=selectrgb)second=rgb[1].second;
//             else second=rgb[2].second;
//         }
//         else{ //이전 최솟값과 겹쳐버리면? 비교를합니다.누가이득인가. 그리고 이득인거 더하고, 진놈은 2순위꺼더하기!
//             if((rgb[1].second-rgb[0].second)>(second-selectcost)){
//                 result-=selectcost; //이전거 취소해.
//                 result+=second;
//                 selectrgb=rgb[0].first; //굴러온돌이박힌돌뺀다
//                 selectcost=rgb[0].second;
//                 result+=selectcost;
//                 second=rgb[1].second;
//             }
//             else{
//                 selectrgb=rgb[1].first;
//                 selectcost=rgb[1].second;
//                 result+=selectcost;
//                 second=rgb[2].second;
//             }
//         }
        
//         rgb.clear();
//         cout<<result;
//     }
//     return 0;
// }
#include <iostream>
#include <algorithm>
using namespace std;
int house[1001][3];
int main() {
    int N;
    int cost[3];
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    cin >> N;
    for(int i = 1; i <= N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = min(house[i-1][1],house[i-1][2]) + cost[0];
        house[i][1] = min(house[i-1][0],house[i-1][2]) + cost[1];
        house[i][2] = min(house[i-1][1],house[i-1][0]) + cost[2];
    }
    cout << min(house[N][2],min(house[N][0],house[N][1]));
}

//자결