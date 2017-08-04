#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
	int test, N;
	vector<double> harm(1,0);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 1; i <= 1e6+10; i++)
		harm.push_back(harm[i-1]+1.0/i);
		
	cin >> test;
	
	while (test--){
		cin >> N;
		
		if (N == 1) cout << "0.00\n";
		else cout << fixed << setprecision(2) << N*harm[N-1] << "\n";
	}
	
	return 0;
}
