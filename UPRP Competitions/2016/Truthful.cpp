#include <iostream>
#include <vector>
using namespace std;

int main(){
	int test, total, n, ans(0);
	vector<int> guess;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cin >> total;
		
		ans = 0; guess.clear();
		guess.assign(total+1, 0);
		
		for (int i = 0; i < total; i++){
			cin >> n;
			guess[n]++;
		}
		
		for (int i = 1; i <= total; i++)
			if (guess[i] == i) ans = i;
			
		cout << "Case #" << t << ": " << ans << "\n";
	}
	
	return 0;
}
