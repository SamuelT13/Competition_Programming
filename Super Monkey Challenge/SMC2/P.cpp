#include <stdio.h>
#include <stdbool.h>

int list_primes(int primes[]){
	int i, c = 0, j;
	bool primality[101] = {false};
	primality[0] = primality[1] = true;
	
	for (i = 2; i*i <= 100; i++)
		if (!primality[i])
			for (j = i*i; j <= 100; j += i)
				primality[j] = true;
	for (i = 2; i <= 100; i++)
		if (!primality[i]) primes[c++] = i;
		
	return c;
}

int main(){
	int primes[100] = {0}, i, j, total, test, next, m, n, p_num, count, nums[110];
	
	total = list_primes(primes);
	
	scanf("%d", &test);
	
	while (test--){
		m = -1;
		scanf("%d", &n);
		
		for (i = 0; i < n; i++) scanf("%d", &nums[i]);
		
		for (i = 0; i < total; i++){
			count = 0;
			for (j = 0; j < n; j++)
				if (nums[j] % primes[i] == 0) count += nums[j];
			
			if (count > m){
				m = count;
				p_num = primes[i];
			}
		}
		
		printf("%d\n", p_num);
	}
	
	return 0;
}
