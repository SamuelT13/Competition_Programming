#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int test, move, total, ans;
	vector<int> curr, need;
	
	cin >> test;
	
	while (test--){
		cin >> total;
		curr.clear(); curr.assign(total, 0);
		need.clear(); need.assign(total, 0);
		ans = 0;
		
		for (int i = 0; i < total; i++) cin >> curr[i];
		for (int i = 0; i < total; i++) cin >> need[i];
		
		for (int i = 0; i < total-1; i++)
			curr[i+1] -= need[i]-curr[i], ans += int(abs(need[i]-curr[i]));
	
		cout << ans << "\n";
	}
	
	return 0;
}
