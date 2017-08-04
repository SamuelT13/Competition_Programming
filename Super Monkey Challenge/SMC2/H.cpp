#include <iostream>
#include <vector>
using namespace std;

typedef long long int LL;
const LL lim = 1e9;

int main(){
	vector<LL> ans;
	LL N, sum(0), ind(0), m;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
			
	for (LL i = 2; ; i++){
		m = (i*(i-1))/2;
		
		while (ind < m) ind++, sum += 9;
		
		ans.push_back(sum); if (sum > lim) break;
	}
    
	while (cin >> N && N)
		(*lower_bound(ans.begin(), ans.end(), N) == N)?
			cout << lower_bound(ans.begin(), ans.end(), N)-ans.begin()+2 << "\n" :
			cout << "impossible\n";
			
	return 0;
}
