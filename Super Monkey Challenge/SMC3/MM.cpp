#include <iostream>
#include <vector>
using namespace std;

typedef long long int LL;
const LL mod = 1e9+7;

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

LL mod_inverse(int n, int mod){
	return mod_power(n, mod-2, mod);
}

LL combinations(int n, int k, int mod, const vector<LL>& factorials){
	LL upper = factorials[n];
	LL lower = factorials[k] * factorials[n-k];
	
	lower = mod_inverse(lower % mod, mod);

	return (upper*lower) % mod;
}

int main(){
	vector<LL> fact(1e6+10, 1);
	LL test, total, spaces;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (LL i = 2; i < 1e6+10; i++) fact[i] = (i*fact[i-1])%mod;
	
	cin >> test;
	
	while (test--){
		cin >> total >> spaces;
		
		spaces = (spaces-total-1);
		total--;
		
		if (spaces < total){ cout << 0 << "\n"; continue;}
		
		cout << (combinations(spaces, total, mod, fact) * fact[total])%mod << "\n";
	}
	
	return 0;
}
