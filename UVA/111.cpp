#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	int n, i, j, longest;
	map<int,int> order;
	vector<int> student, lis;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for (i = 1; i <= n; i++){
		cin >> j;
		order[j] = i;
	}	
	
	while (cin >> j){
		student.push_back(order[j]);
	
		for (i = 1; i < n; i++){
			cin >> j;
			student.push_back(order[j]);
		}
		
		for (i = 0; i < student.size(); i++){
				longest = 0;
				for (j = 0; j < lis.size(); j++)
					if (student[i] > student[j] && lis[j] > longest)
						longest = lis[j];
				lis.push_back(longest+1);
			}
		longest = 0;
		for (i = 0; i < lis.size(); i++)
			if (!i || longest < lis[i])
				longest = lis[i];
		
		student.clear();
		lis.clear();
		for (i = 0; i < n; i++)
			cout << student[i] << " "; cout << "\n";
		cout << longest << "\n";
	}
	
	return 0;
}
