#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int LL;
vector<LL> ans;
vector<int> prime;


void p(){
	int N(1e5);
	vector<bool> pr(N+1, 0); pr[0] = pr[1] = 1;
	
	for (int i = 2; i*i <= N; i++)
		if (!pr[i])
			for (int j = i*i; j <= N; j += i)
				pr[j] = 1;
	
	for (int i = 2; i <= N; i++)
		if (!pr[i]) prime.push_back(i);
}

void man_fact(LL n){
	for (int i = 0; prime[i]*prime[i] <= n; i++)
		while (n % prime[i] == 0) n /= prime[i], ans.push_back(prime[i]);	
	
	if (n > 1) ans.push_back(n);
}

LL abs_val(LL a){
	return (a > 0)? a : -a;
}

LL gcd(LL a, LL b){
	LL c;
	
	while (b){
		c = b;
		b = a%b;
		a = c;
	}
	
	return a;
}

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

LL pollard_rho(LL n, LL c){
	LL d, x(2), y(2);
	
	while (1){
		x = (mulmod(x, x, n)+c)%n;
		
		y = (mulmod(y, y, n)+c)%n;
		y = (mulmod(y, y, n)+c)%n;
        
		d = gcd(x-y, n);
		if(d > 1) return d;
	}
}

void solve(LL n) {
	int num(2);
	LL d(n);
	
	if(n == 1) return;
	
	if(isProbablePrime(n)){ ans.push_back(n); return;}
	
	if(n < 1e9){ man_fact(n); return;}
	
	while (d == n) d = pollard_rho(n, num++);
	
	solve(d), solve(n/d);
}

int main(){
	int total;
	LL next;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	p();
	
	cin >> total;
	
	for (int t = 0; t < total; t++){
		cin >> next;
		
		if (isProbablePrime(next)){
			cout << next << "\n"; continue;
		}
		
		ans.clear();
		solve(next);
		sort(ans.begin(), ans.end());
	
		for (int i = 0; i < ans.size(); i++)
			if (!i) cout << ans[i];
			else cout << " " << ans[i];
		cout << "\n";
	}
	
	return 0;
}
