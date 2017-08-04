#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main(){
	vector<int> lists;
	int total, num;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> total;
	lists.assign(total+1, INF);
	
	for (int i = 0; i < total; i++){
		cin >> num;
		*lower_bound(lists.begin(), lists.end(), num) = num;
	}
	
	for (int i = 0; i < total+1; i++)
		if (lists[i] == INF){
			cout << i << "\n";
			break;
		}
		
	return 0;
}
