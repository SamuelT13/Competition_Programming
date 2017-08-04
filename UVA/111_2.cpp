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
	
	for (i = 0; i < n; i++){
		cin >> order[i];
	}	

	while (cin >> j){
		i = 0;
		student.assign(n,0);
		student[j-1] = order[i];i++;
	
		for (; i < n; i++){
			cin >> j;
			student[j-1] = order[i];
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
		
		cout << longest << "\n";
		student.clear();
		lis.clear();
	}
	
	return 0;
}
