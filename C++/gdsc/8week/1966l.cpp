// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin>>t;

//     for(int a=0;a<t;a++){
//         queue<pair<int,int>> q;
//         vector<int> map;
//         int papers, wonder, result=0;
//         cin>>papers>>wonder;
//         for(int i=0;i<papers;i++){
//             int r;
//             cin>>r;
//             map.push_back(r);
//             q.push({i,r}); //1번째:문서번호 , 2번째:우선순위
//         }
//         while(!q.empty()){
//             if(q.front().second==9){
//                 q.pop();
//                 auto it =find(map.begin(),map.end(),q.front().second);
//                 map.erase(it);
//                 result++;
//             }
//             else{
//             for(int i=q.front().second+1;i<=9;i++){ //가장 앞에 있는 문서의 우선순위보다 높은 우선순위 찾기
//                 if(map.end()!=find(map.begin(),map.end(),i)){ //찾으면 뒤로 보내기(삭제x)
//                     q.push({q.front().first,q.front().second});
//                     q.pop();
//                     result++;
//                     break;
//                 }
//                 else if(i==9){//끝까지 우선순위가 높은 걸 못찾으면 삭제해도됨.
//                     if(q.front().first==wonder){ //삭제할 숫자가 궁굼한 문서였다면
//                         while(!q.empty()) q.pop(); //다지우기
//                         result++;
//                     }
//                     else{
//                     q.pop();
//                     //remove(map.begin(),map.end(),q.front().second);
//                     auto it =find(map.begin(),map.end(),q.front().second);
//                     map.erase(it);
//                     result++;
//                     }
//                 }
//             }
//             }
//         }
//         cout<<result;
//     }

//     return 0;
// }
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int count=0;
    int test_case;
    cin >> test_case;
    int n, m,ipt;//문서의 개수, 궁금한 문서 위치, 중요도
    for (int i = 0; i < test_case; ++i) {
        count = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq; // 우선순위 큐
        for (int j = 0; j < n; ++j) {
            cin >> ipt;
            q.push({ j, ipt });
            pq.push(ipt);
        }
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value) {
                pq.pop();
                ++count;
                if (index == m) {
                    cout << count << endl;
                    break;
                }
            }
            else q.push({ index,value });
        }
    }
}