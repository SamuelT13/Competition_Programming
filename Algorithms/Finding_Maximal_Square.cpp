#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<vector<char> > grid;
	vector<vector<int> > sq;
	int R, C;
	
	cin >> R >> C;
	
	grid.assign(R, vector<char>());
	sq.assign(R, vector<int>());
	for (int i = 0; i < R; i++){
		sq[i].assign(C, 0);
		grid[i].assign(C, '0');
		for (int j = 0; j < C; j++) cin >> grid[i][j];
	}
	
	for (int i = 0; i < R; i++) if (grid[i][0] == '1') sq[i][0] = 1;
	for (int i = 0; i < C; i++) if (grid[0][i] == '1') sq[0][i] = 1;
	
	for (int i = 1; i < R; i++)
		for (int j = 1; j < C; j++)
			if (grid[i][j] == '1')
				sq[i][j] = min(min(sq[i-1][j], sq[i][j-1]), sq[i-1][j-1])+1;
				
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) cout << sq[i][j] << " "; cout << endl;
	}
	
	return 0;
}
