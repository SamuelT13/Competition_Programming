#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void list_p(int N, vector<int>& p){
	vector<bool> pr(N+1, 0); pr[0] = pr[1] = 1;
	
	for (int i = 2; i*i <= N; i++)
		if (!pr[i])
			for (int j = i*i; j <= N; j += i)
				pr[j] = 1;
				
	for (int i = 2; i <= N; i++)
		if (!pr[i])
			p.push_back(i);
}

vector<int> divi;
//fact is ordered
void gen_div(int curr, const vector<int>& fact, int s, int e){
	if (s == e) divi.push_back(curr);
	
	else{
		int m;
		for (m = s+1; m < e && fact[m] == fact[s]; m++);
		for (int i = s; i <= m; i++){
			gen_div(curr, fact, m, e);
			curr *= fact[s];
		}
	}
}


int main(){
	vector<int> p, f;
	int N;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	list_p(1e5, p);
	cin >> N;
	
	for (int i = 0; p[i]*p[i] <= N; i++)
		while (N % p[i] == 0) f.push_back(p[i]), N /= p[i];
	if (N > 1) f.push_back(N);
	
	gen_div(1, f, 0, f.size());
	
	cout << "Divisors of " << N << ":\n\n";
	sort(divi.begin(), divi.end());
	for (int i = 0; i < divi.size(); i++)
		cout << divi[i] << "\n";

	return 0;
}
