#include <iostream>
#include <set>
using namespace std;

int main(){
	int test, N, A, C, x0(0);
	set<int> nums;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cout << "Case #" << t << ": ";
		
		cin >> N >> A >> C;
		nums.clear();
		
		for (x0 = 0; ; x0 = (A*x0 + C)%N)
			if (nums.count(x0)) break;
			else nums.insert(x0);
		
		cout << nums.size() << "\n";
	}
	
	return 0;
}
