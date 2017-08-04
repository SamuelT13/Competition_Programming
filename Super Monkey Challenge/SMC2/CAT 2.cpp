#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long int ULL;

int main(){
	int test;
	string next, target("#CAT");
	vector<ULL> memo;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	while (test--){
		memo.clear(); memo.assign(4, 0); memo[0] = 1; //# <- starting point
		//memo[1] <- C; memo[2] <- CA; memo[3] <- CAT
		
		cin >> next;
		
		for (int i = 0; i < next.length(); i++)
			for (int j = 1; j < 4; j++)
				if (next[i] == target[j]) memo[j] += memo[j-1];
			
		cout << memo[3] << "\n";
	}
	
	return 0;
	
}
