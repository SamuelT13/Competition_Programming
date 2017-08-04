#include <iostream>
using namespace std;

const int UNVISITED = -1;

int main(){
	int total_s, row, col, start, i, j, r, c;
	char **grid;
	bool cycle;
	int **visited;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> row >> col >> start && (row || col || start)){
		cycle = false;
		total_s = 0;
		grid = new char*[row];
		visited = new int*[row];
		
		for (i = 0; i < row; i++){
			grid[i] = new char[col];
			visited[i] = new int[col];
			for (j = 0; j < col; j++){
				cin >> grid[i][j];
				visited[i][j] = UNVISITED;
			}
		}
		
		r = 0; c = start-1;
		visited[r][c] = total_s;
				
		while (true){
			total_s++;
			if (grid[r][c] == 'N') r--;
			else if (grid[r][c] == 'S') r++;
			else if (grid[r][c] == 'W') c--;
			else c++;
			
			if (r < 0 || r >= row || c < 0 || c >= col) break;
			if (visited[r][c] != UNVISITED){
				cycle = true;
				break;
			}
			else
				visited[r][c] = total_s;
		}
		
		if (cycle) cout << visited[r][c] << " step(s) before a loop of " << total_s-visited[r][c] << " step(s)\n";
		else cout << total_s << " step(s) to exit\n"; 
	}
	return 0;	
}
