#include <iostream>
#include <vector>

using namespace std;

int N;
char candi[50][50];
int check(int i, int j)
{
    int result = 0;
    int source, suin;
    bool change= false;

    // 처음색깔바꾼버전(가로편)
    for (int z = 0; z < 5; z++)
    {
        suin = 1;
        switch(z){
            case 0:
                source=candi[i][j];
                break;
            case 1:
                if (i - 1 != -1) source =candi[i - 1][j];
                break;
            case 2:
                if (i + 1 != N) source = candi[i + 1][j];
                break;
            case 3:
                if (j - 1 != -1) {
                    source = candi[i][j - 1];
                    candi[i][j-1]=candi[i][j];
                    change= true;
                }
                break;
            default:
                if (j + 1 != N) {
                    source = candi[i][j + 1];
                    candi[i][j+1]=candi[i][j];
                    change= true;
                }
                break;
        }
        
        for (int a = j + 1; a < N; a++)
        { // 오른쪽 검사
            if (source == candi[i][a])    suin++; 
            else    break;
        }
        for (int a = j -1; a > -1; a--)
        { // 왼쪽검사
            if (source == candi[i][a])    suin++;
            else    break;
        }
        result = suin > result ? suin : result;
        if(change){ //바뀐값 원상복구..
            if(z==3) candi[i][j-1]=source;
            else candi[i][j+1]=source;
            change=false;
            source=candi[i][j];
        }
    }
    
    // 세로편
    for (int z = 0; z < 5; z++)
    {
        suin = 1;
        switch(z){
            case 0:
                source=candi[i][j];
                break;
            case 1:
                if (i - 1 != -1) {
                    source =candi[i - 1][j];
                    candi[i-1][j]=candi[i][j];
                    change= true;
                }
                break;
            case 2:
                if (i + 1 != N){
                    source = candi[i + 1][j];
                    candi[i+1][j]=candi[i][j];
                    change= true;
                }
                break;
            case 3:
                if (j - 1 != -1) source = candi[i][j - 1];
                break;
            default:
                if (j + 1 != N) source = candi[i][j + 1];
                break;
        }

        for (int a = i + 1; a < N; a++)
        { // 아래검사
            if (source == candi[a][j]) suin++;
            else    break;
        }
        for (int a = i -1; a > -1; a--)
        { // 위검사
            if (source == candi[a][j])    suin++;
            else    break;
        }
        result = suin > result ? suin : result;
        if(change){ //바뀐값 원상복구..
            if(z==1) candi[i-1][j]=source;
            else candi[i+1][j]=source;
            change=false;
            source=candi[i][j];
        }

    }
   // cout << i << " " << j << " " << result << endl;
    return result;
}

int main()
{

    int result = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    { // 입력받기
        for (int j = 0; j < N; j++)
            cin >> candi[i][j];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int checki=check(i, j);
            result = checki > result ? checki : result;
        }
    }
    cout << result;
    return 0;
}