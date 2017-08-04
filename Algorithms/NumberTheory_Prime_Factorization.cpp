#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int LL;

//Check if N is prime using trial division
bool is_prime_td(int n){
	if (n < 2) return false;

	int r = sqrt(n);
	for (int d = 2; d <= r; d++)
		if (n % d == 0) return false;
	
	return true;
}

//Check if N is prime by dividing by primes
//Prime numbers stored must have at least one greater than sqrt(N), and are in ascending order
bool is_prime_pd(int n, const vector<int>& primes){
	if (n < 2) return false;
	
	int r = sqrt(n);
	for (int i = 0; primes[i] <= r; i++)
		if (n % primes[i] == 0) return false;
		
	return true;
}

//List of prime factors of N, in ascending order of Factors
void factorization_td(int n, vector<int>& factors){
	int r = sqrt(n);
	for (int d = 2; d <= r; d++)
		while (n % d == 0){
			factors.push_back(d);
			n /= d;
			r = sqrt(n);
		}
	
	if (n > 1) factors.push_back(n);
}

//List of prime factors of N, in ascending order of Factors
//Prime numbers stored must have at least one greater than sqrt(N), and are in ascending order
void factorization_pd(int n, const vector<int>& primes, vector<int>& factors){
	int r = sqrt(n);
	for (int i = 0; primes[i] <= r; i++)
		while (n % primes[i] == 0){
			factors.push_back(primes[i]);
			n /= primes[i];
			r = sqrt(n);
		}
		
	if (n > 1) factors.push_back(n);
}

//Calculates base^expo mod Mod
LL mod_power(int base, int expo, int mod){
	LL result = 1 % mod;
	LL square = base % mod; //a^1
	
	for (int p = 0; p < 31; p++){
		if (expo && (1 << p)) //pth bit is set
			result = (result * square) % mod;
		square = (square * square) % mod;
	}
	
	return result;	
}

//Miller Rabin
bool isProbablePrime(LL n){
	LL x, y;
	
	if (n == 2 || n == 3) return 1;
	if (n == 1) return 0;
	if (n % 2 == 0) return 0;

	for (int i = 0; i < 10; i++){
		x = rand()%(n-4) + 2;
		y = mod_power(x, n-1, n);
		if (y != 1) return 0;
	}
	
	return 1;	
}

//Miller-Rabin Primality Test to N using A as a witness
bool miller_rabin(int n, int a, int d, int s){
	if (a > n-2) return true;
	
	LL x = mod_power(a, d, n);
	if (x == 1 || x == n-1) return true;
	
	for (int k = 1; k < s; k++){
		x = (x*x) % n;
		if (x == 1) return false;
		if (x == n-1) return true;
	}
	
	return false;
}

//Check if N is prime using the Miller-Rabin Primality Test.
//The set of witnesses used always works for N < 4,759,123,141
bool is_prime_mr(int n){
	if (n < 6){
		if (n == 2 || n == 3 || n == 5) return true;
		return false;
	}
	
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
	
	int d = (n-1)/2;
	int s = 1;
	
	while ((d & 1) == 0){
		d /= 2;
		s++;
	}
	
	return miller_rabin(n, 2, d, s) && miller_rabin(n, 7, d, s) && miller_rabin(n, 61, d, s);
}

//List all primes up to N using the Sieve of Eratosthenes in O(NloglogN)
void list_primes(int n, vector<int>& primes){
	vector<bool> primality(n + 1, true);
	primality[0] = primality[1] = false;
	
	for (int i = 2; i*i <= n; i++)
		if (primality[i])
			for (int j = i*i; j <= n; j += i)
				primality[j] = false;
				
	for (int i = 2; i <= n; i++)
		if (primality[i]) primes.push_back(i);
}

//List a prime factor of every integer up to N using a modified version of SoE
void factorization_sieve(int n, vector<int>& factors){
	factors = vector<int>(n+1, 0);
	factors[1] = 1;
	int i;
	
	for (i = 2; i*i <= n; i++)
		if (factors[i] == 0){
			factors[i] = i;
			for (int j = i*i; j <= n; j += i)
				factors[j] = i;
		}
		
	for (; i <= n; i++)
		if (factors[i] == 0)
			factors[i] = i;
}
