#include <iostream>
#include <vector>
using namespace std;

int main(){
	int test, peso, total;
	vector<int> p;
	vector<vector<int> > memo;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cin >> peso >> total;
		
		p.clear(); memo.clear();
		p.assign(total+1, 0); memo.assign(total+1, vector<int>());
		
		for (int i = 0; i <= total; i++){
			memo[i].assign(peso+1, 0);
			if (!i) continue;
			cin >> p[i];
		}
		
		for (int i = 1; i <= total; i++)
			for (int j = 0; j <= peso; j++){
				memo[i][j] = memo[i-1][j]; //no colocar objecto
				if (j-p[i] >= 0)
					memo[i][j] = max(memo[i][j], p[i]+memo[i][j-p[i]]);
				}
		
		cout << "Caso #" << t << ": " << memo[total][peso] << "\n";
	}
	
	return 0;
}
