#include <iostream>
#include <vector>
using namespace std;

typedef long long int LL;

vector<int> p;
void list_p(int N){
	vector<bool> pr(N+1, 0); pr[0] = pr[1] = 1;
	p.assign(N+1, 0);
	
	for (int i = 2; i*i <= N; i++)
		if (!pr[i]) 
			for (int j = i*i; j <= N; j += i)
				pr[j] = 1;
				
	for (int i = 2; i <= N; i++)
		if (!pr[i])
			p[i] = 1;
}

LL mod_expo(int N, int expo, int mod){
	LL ans(1), sq(N);
	
	while (expo){
		if (expo & 1) ans = (ans*sq)%mod;
		expo >>= 1;
		sq = (sq*sq)%mod;
	}
	
	return ans;	
}


vector<int> e;
LL calc(int N, const vector<int>& m, int total){
	e.assign(N+1, 0);
	
	//assigning exp to factorials in num/denom
	e[N]++;
	for (int i = 0; i < total; i++)
		if (m[i] > 1) e[m[i]]--;
	
	//prop exp (because it's a factorial)
	for (int i = N-1; i >= 2; i--) e[i] += e[i+1];
	
	//getting rid of neg exps
	for (int i = N; i >= 2; i--)
		if (p[i]){
			e[i/p[i]] += e[i];
			e[p[i]] += e[i];
			e[i] = 0;
		}
			
	//eliminating trailing 0s
	int mi = min(e[2], e[5]);
	e[2] -= mi, e[5] -= mi;
	

	for (int i = 1; i <= N; i++)
		cout << i << ": " << e[i] << endl;
		
	LL ans = 1;
	for (int i = 2; i <= N; i++)
		if (e[i])
			ans = (ans * mod_expo(i, e[i], 10))%10,
			e[i] = 0;

	return ans;
}

int main(){
	int N, total;
	vector<int> m;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	list_p(1e5);
	
	cin >> N >> total;
	m.assign(total, 0);
	for (int i = 0; i < total; i++) cin >> m[i];

	cout << calc(N, m, total) << "\n";
		
	return 0;
}
