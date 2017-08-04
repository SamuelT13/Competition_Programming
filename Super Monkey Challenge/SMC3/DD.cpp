#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int test, total, turns;
	vector<int> nums, ds;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cout << "Case #" << t << ": ";

		cin >> total;
		nums.clear(); ds.clear();
		nums.assign(total, 0);
		
		for (int i = 0; i < total; i++) cin >> nums[i];
		
		turns = 0, ds = nums;
		while (ds.size()){
			turns++, ds.clear();
			
			for (int i = 1; i < nums.size(); i++)
				if (nums[i] < nums[i-1]){
					ds.push_back(nums[i]);
					nums.erase(nums.begin()+i);
					i--;
				}
			nums = ds;
		}
		
		cout << turns << "\n";
	}
	
	return 0;
}
