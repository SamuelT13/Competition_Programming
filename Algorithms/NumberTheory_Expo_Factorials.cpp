#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

//Calculates base^expo in O(logexpo)
LL power(int base, int expo){
	LL result = 1;
	LL square = base; //a^1
	
	for (int p = 0; p < 31; p++){
		if (expo & (1 << p)) //pth bit is set
			result *= square;
		square *= square;
	}
	
	return result;
}

//Calculates base^expo mod Mod
LL mod_power(int base, int expo, int mod){
	LL result = 1 % mod;
	LL square = base % mod; //a^1
	
	for (int p = 0; p < 31; p++){
		if (expo & (1 << p)) //pth bit is set
			result = (result * square) % mod;
		square = (square * square) % mod;
	}
	
	return result;	
}

//Calculates mod inverse of N in modulus Mod. Make sure Mod is prime!
LL mod_inverse(int n, int mod){
	return mod_power(n, mod-2, mod);
}

//Factorials up to N! modulo Mod
void mod_factorials(int n, int mod, vector<LL>& factorials){
	factorials.resize(n+1);
	factorials[0] = (1 % mod);
	
	for (int k = 1; k <= n; k++)
		factorials[k] = (k*factorials[k-1]) % mod;
}

//Calculates binomial coefficient C(n, k) in modulo Mod
LL combinations(int n, int k, int mod, const vector<LL>& factorials){
	LL upper = factorials[n];
	LL lower = factorials[k] * factorials[n-k];
	
	lower = mod_inverse(lower % mod, mod);
	return (upper*lower) % mod;
}

//Calculates Greatest Common Divisor of A and B
LL gcd(LL a, LL b){
	LL c;
	
	while (a != 0){
		c = a;
		a = b % a;
		b = c;
	}
	
	return b;
}

//Calculates Least Common Multiple of A and B
LL lcm (LL a, LL b){
	return (a*b)/gcd(a, b);
}

//Calculates remainder of dividing Number by Mod
//Base is an integer from 2 to 10
int large_mod(const string& number, int base, int mod){
	LL remainder = 0;
	
	for (int k = 0; k < number.size(); k++)
		remainder = (base * remainder + number[k] - '0') % mod;
	
	return remainder;
}
