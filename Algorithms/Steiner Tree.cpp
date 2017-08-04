#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<vetor<int> > dp, dist;
	int N, K;
	
	for (int i = 1; i < (1<<K); i++){
		for (int j = 0; j < N; j++)
			for (int k = (i-1)&i; k; k = (k-1)&i)
				dp[i][j] = min(dp[i][j],
					       dp[k][j] + dp[i^k][j]);
	
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				dp[i][j] = min(dp[i][j],
					       dp[i][k] + dist[j][k]);
	}
	
	return 0;
}
