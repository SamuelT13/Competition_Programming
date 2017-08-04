#include <iostream>
#include <cstdio>
using namespace std;

const int values[5] = {1,5,10,25,50};
const int coins = 7490;
long long int memo[coins][6];

long long int change(int coin, int remaining){
	if (coin == 5)
		return 0;
	if (remaining < 0)
		return 0;
	if (!remaining)
		return 1;

	if (memo[remaining][coin] != -1)
		return memo[remaining][coin];
		
	memo[remaining][coin+1] = change(coin+1,remaining);

	if (remaining >= values[coin]){
		memo[remaining-values[coin]][coin] = change(coin, remaining-values[coin]);
		return memo[remaining][coin+1] + memo[remaining-values[coin]][coin];
	}
	else // remaining - values[coin] < 0 -> remaining-values[coin+i] < 0 ?
		return memo[remaining][coin+1]; // == 0 ?
}
int main(){
	int i, j, num;
	
	for (i = 0; i < coins; i++)
		for (j = 0; j < 5; j++)
			memo[i][j] = -1;
		
 	while (scanf("%d",&num) != EOF)
		printf("%lld\n", change(0, num));

	return 0;
}
