#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

char abc[21][21];
int R, C;
vector<int> result;
vector<vector<int>> check = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void DFS(int i, int j,int num, map<char, bool> tf)
{
    for(int a=0;a<check.size();a++){
        int x = i+check[a][0];
        int y = j+check[a][1];
        if(x>=0 && x<R && y>=0 && y<C){
            if(tf[abc[x][y]]!=true){
                tf[abc[x][y]]=true;
                result.push_back(num+1);
                DFS(x,y,num+1,tf);
            }
        }
    }
}

int main()
{
    cin >> R >> C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>abc[i][j];
        }
    }
    map<char, bool> tf;
    tf[abc[0][0]]=true;
    result.push_back(1);
    DFS(0,0,1,tf);
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
    cout<<result.back();
    return 0;
}