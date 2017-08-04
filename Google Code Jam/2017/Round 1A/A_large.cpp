#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	int test, R, C, ind;
	vector<vector<char> > grid;
	vector<bool> row;
	ifstream in("A-large.in");
	ofstream out("out.txt");
	
	ios_base::sync_with_stdio(false);
	in.tie(NULL);
	
	in >> test;
	
	for (int t = 1; t <= test; t++){
		in >> R >> C;
		grid.clear(); grid.assign(R, vector<char>());
		row.clear(); row.assign(R, false);
		
		for (int i = 0; i < R; i++){
			grid[i].assign(C, '0');
			
			for (int j = 0; j < C; j++){
				in >> grid[i][j];
				if (grid[i][j] != '?') row[i] = true;
			}
		}
		
		for (int i = 0; i < R; i++){
            if (!row[i]) continue;
			for (int j = 0; j < C; j++){
				if (grid[i][j] != '?'){
					for (int l = 0; l < j; l++) if (grid[i][l] != '?') break; else grid[i][l] = grid[i][j];
					for (int l = j+1; l < C; l++) if (grid[i][l] != '?') break; else grid[i][l] = grid[i][j];
				}
			}
        }
	
        for (int m = 0; m < R; m++){
            for (int i = 0; i < R; i++){
                if (row[i]) continue;
                if (i && row[i-1]) ind = i-1;
                else if (i < R-1 && row[i+1]) ind = i+1;
                else continue;
                row[i] = true;
                for (int j = 0; j < C; j++) grid[i][j] = grid[ind][j];
            }
        }
		out << "Case #" << t << ":\n";
		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++) out << grid[i][j]; out << "\n";
		}
	}
		
	return 0;
}
