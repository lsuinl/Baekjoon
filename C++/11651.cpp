#include <iostream>
#include <algorithm>

using namespace std;

struct xy{
    int x,y;
};

bool compare(xy a, xy b){
    if(a.y==b.y)
        return a.x<b.x;
    else
        return a.y<b.y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x,y;
    cin>>n;
    xy* arr= new xy[n];
    for(int i=0;i<n;i++){
        cin>>x>>y;
        arr[i]=xy{x,y};
    }
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
        cout<<arr[i].x<<" "<<arr[i].y<<"\n";
    delete[] arr;
    return 0;
}

