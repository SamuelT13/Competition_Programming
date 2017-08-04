#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> coin;
	int total, n, i, j, *coins, min;
	
	scanf("%d%d",&total, &n);
	coins = new int[n];
	
	for (i = 0; i < n; i++)
		scanf("%d",&coins[i]);
		
	for (i = 0; i <= total; i++){
		coin.push_back(0);

		if (i){
			min = total+1;
			for (j = 0; j < n; j++)
				if (i-coins[j] >= 0 && coin[i-coins[j]] < min)
					min = coin[i-coins[j]];
			coin[i] = min+1;
		}
	}
	
	printf("%d\n", coin[total]);
	
	return 0;
}
