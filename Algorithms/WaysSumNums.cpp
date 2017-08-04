#include <iostream>
using namespace std;

const int MOD = 1000000000; //CHANGE
const int M_SIZE = 100*100+1; //CHANGE
long long int memo[M_SIZE][M_SIZE];

long long int ways(int n, int K){
	if (K == 1) return 1;
	else if (memo[n][K] != -1) return memo[n][K];
	else{
		long long int num = 0;
		for (int X = 0; X <= n; X++)
			num += (ways(n-X, K-1))%MOD;
		return memo[n][K] = (num)%MOD;	
	}
}

int main(){
	int n, K, i, j;
	
	for (i = 0; i < M_SIZE; i++)
		for (j = 0; j < M_SIZE; j++)
			memo[i][j] = -1;
			
	scanf("%d%d",&n, &K);
	
	printf("%d\n", ways(n,K));
	
	return 0;
}
