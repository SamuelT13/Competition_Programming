#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long int LL;

LL mulmod(LL a, LL b, LL c){
	LL x(0), y(a%c);
	
	while (b > 0){
		if (b % 2) x = (x + y) % c;
		y = (y * 2) % c;
		b >>= 1;
	}
	
	return x % c;
}

LL modpow(LL base, LL p, LL mod){
	LL n = 1, sq = base%mod;
	
	for (int i = 0; i < 63; i++){
		if (p & LL(1)<<i) n = mulmod(n, sq, mod);
		sq = mulmod(sq, sq, mod);
	}

	return n;
}

bool isProbablePrime(LL n){
	LL x, y;
	
	if (n == 2 || n == 3) return 1;
	if (n == 1) return 0;
	if (n % 2 == 0) return 0;

	for (int i = 0; i < 10; i++){
		x = rand()%(n-4) + 2;
		y = modpow(x, n-1, n);
		if (y != 1) return 0;
	}
	
	return 1;	
}

int main(){
	LL next;
	
	while (cin >> next) cout << next << ": " << isProbablePrime(next) << endl;
}
