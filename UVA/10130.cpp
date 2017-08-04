#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int max_w = 31;
const int max_o = 1001;
int main(){
 	int memo[max_o][max_w], maxim, people;
	int test, i, j, objects, weight[1001], price[1001];
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;	

	while (test--){
		cin >> objects;
		
		for (i = 1; i <= objects; i++)
			cin >> price[i] >> weight[i];
		
		for (j = 0; j < max_w; j++)
			memo[0][j] = 0;
		for (i = 1; i <= objects; i++)
			for (j = 0; j < max_w; j++)
				if (weight[i] > j)
					memo[i][j] = memo[i-1][j];
				else
					memo[i][j] = max(memo[i-1][j], price[i]+memo[i-1][j-weight[i]]);
					
		cin >> people;
		
		maxim = 0;
		for (i = 0; i < people; i++){
			cin >> j;
			maxim += memo[objects][j];
		}
		
		cout << maxim << "\n";
	}
	
	return 0;
}
