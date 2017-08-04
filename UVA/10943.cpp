#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e6;

int main(){
	int N, K;
	vector<vector<int> > ways;
	
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    
	while (cin >> N >> K && (N||K)){
		ways.clear();
		ways.assign(N+1, vector<int>());
		
		for (int i = 0; i <= N; i++) ways[i].assign(K+1, 0);
		
		for (int i = 0; i <= N; i++) ways[i][1] = 1; //1 way, using i
		
		for (int i = 0; i <= N; i++)
			for (int j = 2; j <= K; j++)
				for (int k = 0; k <= i; k++) ways[i][j] = (ways[i][j]+ways[i-k][j-1])%mod;
			
		cout << ways[N][K] << "\n";
	}
	
	return 0;
}
