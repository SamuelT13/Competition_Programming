#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

bool *nums;
const long long int MAX_NUMS = 100000001;

void sieve(vector<bool>& nums, long long int limit){
    for (long long int m = 2; m <= sqrt(limit); m++)
    	if (!nums[m])
			for (long long int k = m*m; k <= limit; k += m)
				nums[k] = true;
}

int main(){
	set<int> primes;
	int N;
	vector<bool> nums(MAX_NUMS, false);
	
	sieve(nums, MAX_NUMS-1);
	
	for (int i = 2; i < MAX_NUMS; i++)
        if (!nums[i]) cout << i << endl;
	
	cout << primes.size();
	//for (set<int>::iterator it = primes.begin(); it != primes.end(); it++) cout << *it << " "; cout << endl;
	
	
	while (cin >> N){
		;
	}
	
	return 0;	
}
