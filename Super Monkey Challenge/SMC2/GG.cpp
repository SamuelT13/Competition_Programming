#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int total, Q, R;
	vector<int> sum;
	vector<int>::iterator it;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> total;
	sum.assign(total, 0);
	
	for (int i = 0; i < total; i++){
		cin >> sum[i];
		if (i) sum[i] += sum[i-1];
	}
	
	cin >> Q;
	
	for (int i = 0; i < Q; i++){
		cin >> R;
		
		it = lower_bound(sum.begin(), sum.end(), R);
		
		(it == sum.end())? cout << "none\n" : cout << it-sum.begin()+1 << "\n";
	}
	
	return 0;
}
