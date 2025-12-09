#include <iostream>
#include <vector>

using namespace std;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,maxSum=0,result=0;
    vector<int> people,data;
    cin>>n;
    people.resize(n);
    fill(data.begin(),data.end(),0);
    for(int i=0;i<n;i++){
        cin>>people[i];
    }
    for(int i=0;i<n;i++){
        bool visited[1001]={false,};
        visited[i]=true;
        int node = people[i]-1,count=1;
        while(1){
            if(!visited[node]){
                visited[node]=true;
                count++;
                node=people[node]-1;
            }
            else{
                if(count>maxSum){
                    maxSum=count;
                    result=i+1;
                }
                break;
            }
        }
    }

    cout<<result;
    return 0;
}