#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int box[26][26];
bool visited[26][26];
vector<int> result;


vector<vector<int>> check = {{0,-1},{0,1},{-1,0},{1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
void DFS(int i, int j,int n){
    for(int a=0;a<check.size();a++){
        int x=i+check[a][0];
        int y=j+check[a][1];
        if(x>=0 &&x<n &&y>=0 && y<n ){
            if(box[x][y]==1 &&visited[x][y]==false ){
                visited[x][y]=true;
                result.back()++;
                DFS(x,y,n);
            }
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        for(int j=0;j<n;j++){
            box[i][j]=word[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(box[i][j]==1 && visited[i][j]==false){
                visited[i][j]=true;
                result.push_back(1);
                DFS(i,j,n);
            }
        }
    }
    sort(result.begin(),result.end());
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}