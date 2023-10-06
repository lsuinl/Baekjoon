// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std; 

// int main(){
//     long long n,m,result=0,sum,min;
//     vector<int> tree;
//     cin>>n>>m;
//     for(int i=0;i<n;i++){
//         int length;
//         cin>>length;
//         tree.push_back(length);
//     }

//     sort(tree.begin(),tree.end());
//     int slice = tree[tree.size()-1]<m ?0:(tree[tree.size()-1]-m);
//     do{
//         sum=0;
//         for(int i=0;i<tree.size();i++){
//             sum+=(tree[i]-slice)>0 ? (tree[i]-slice):0;
//         }
//         if(sum>=m && min>=sum){
//             min=sum;
//             result=slice;
//         }
//         slice++;
//     }while(sum>=m);

//     cout<<result;
//     return 0;
// }

  #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> tree;

int main() {
    cin >> n >> m;

    for(auto i =0; i<n;i++) {
        int x;
        cin >> x;
        tree.push_back(x);
    }

    int start =0;
    int end= *max_element(tree.begin(),tree.end());
    int result=0;

    while(start<=end) {
        long long int total = 0;
        int mid = (start+end) / 2;
        for(auto i =0; i<n;i++) {
            if (tree[i]>mid) total += tree[i] - mid;
        }
        if(total<m) {
            end = mid -1;
        } else {
            result = mid;
            start = mid +1;
        }
    }
    cout << result;
}