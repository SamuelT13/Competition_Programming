#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> memo(2050, 0);
	int mod = 100999, N, ind;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memo[0] = 1;
	for (int i = 1; i <= 2000; i++)
		for (int j = 2000; j >= 0; j--){
			if (j-i < 0) break;
			memo[j] = (memo[j]+memo[j-i])%mod;
		}
	
	cin >> N;
	
	while (N--){
		cin >> ind;
		cout << memo[ind] << "\n";
	}
	
	return 0;
}
