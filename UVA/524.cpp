#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> nums;
set<int> primes;

void ring(int ind, int total){
	if (ind == total){
		if (!primes.count(nums[0] + nums[ind-1])) return;
		
		for (int i = 0; i < nums.size(); i++){
			if (i) cout << " ";
			cout << nums[i];
		}
		cout << "\n";
		return;
	}
	
	for (int i = 2; i <= total; i++)
		if (find(nums.begin(), nums.end(), i) == nums.end() && primes.count(nums[ind-1]+i)){
			nums.push_back(i);
			ring(ind+1, total);
			nums.erase(nums.begin()+nums.size()-1);
		}
	
}

int main(){
	int test, total;
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    primes.insert(2); primes.insert(3); primes.insert(5); primes.insert(7); primes.insert(11); 
    primes.insert(13); primes.insert(17); primes.insert(19); primes.insert(23); primes.insert(29); primes.insert(31); //at most 16+15 = 31
	//cin >> test;
	
	for (int t = 1; cin >> total; t++){
        if (t != 1) cout << "\n";
        cout << "Case " << t << ":\n";
		nums.clear();
		nums.push_back(1);
		ring(1, total);
	}
}
