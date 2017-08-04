#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T, R, C, m;
	vector<vector<char> > grid;
	vector<vector<int> > ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	
	while (T--){
		grid.clear(); ans.clear(); m = 0;
		
		cin >> R >> C;
		grid.assign(R, vector<char>()); ans.assign(R, vector<int>());
		
		for (int i = 0; i < R; i++){
			grid[i].assign(C, '0'), ans[i].assign(C, 0);
			for (int j = 0; j < C; j++) cin >> grid[i][j];
		}

		for (int i = 0; i < R; i++)
			if (grid[i][0] == '.'){ ans[i][0] = 1; m = 1;}
		for (int j = 0; j < C; j++)
			if (grid[0][j] == '.'){ ans[0][j] = 1; m = 1;}
			
		for (int i = 1; i < R; i++)
			for (int j = 1; j < C; j++){
				if (grid[i][j] == 'X') continue;
				
				ans[i][j] = min(min(ans[i-1][j], ans[i][j-1]), 
								ans[i-1][j-1]) + 1;
							
				m = max(ans[i][j], m);
			}
		
		cout << m*m << "\n";
	}
	
	return 0;
}
