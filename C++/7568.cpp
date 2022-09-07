// #include <iostream>
// #include <utility>

// using namespace std;

// int main() {
//     int num;
//     pair<int,int> arr[50];
//     cin >> num;
//     for(int i = 0; i < num; i++)
//         cin >> arr[i].first >> arr[i].second;
//     for(int i = 0; i < num; i++)
//     {
//         int rank = 1;
//         for(int j = 0; j < num; j++)
//             if(arr[i].first < arr[j].first && arr[i].second < arr[j].second)
//                 rank++;
//         cout << rank << ' ';
//     }
// }
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	//사람수만큼 벡터
	//사람한명당 2개 (n행k열)
	vector<vector<int> > people(n, vector<int>(3,1));
	
	for(int i=0;i<people.size();i++){
		cin>>people[i][0]>>people[i][1];
	}

	for(int i=0;i<people.size();i++){
		for(int j=0;j<people.size();j++){
			if(people[i][0]<people[j][0] && people[i][1]<people[j][1])
				people[i][2]++;
		}
	}
	for(int i=0;i<people.size();i++){
		cout<<people[i][2]<<" ";
	}

	return 0;
}

