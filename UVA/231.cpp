#include <iostream>
#include <vector>
using namespace std;

int main(){
	int num, longest, i, k(0), j;
	vector<int> nums, lis;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> num){
		if (num == -1){
			if (nums.empty()) return 0;
			for (i = 0; i < nums.size(); i++){
				longest = 0;
				for (j = 0; j < lis.size(); j++)
					if (nums[i] <= nums[j] && lis[j] > longest)
						longest = lis[j];
					lis.push_back(longest+1);
			}
		longest = 0;
		for (i = 0; i < lis.size(); i++)
			if (!i || longest < lis[i])
				longest = lis[i];
		
		if (k) cout << "\n"; 
		cout << "Test #" << ++k << ":\n"
			 << "  maximum possible interceptions: " << longest << "\n"; 
			nums.clear();
			lis.clear();
		}
		
		else
			nums.push_back(num);
	}
	
	return 0;
}
