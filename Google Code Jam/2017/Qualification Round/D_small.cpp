#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<char> > grid;
int dim;

struct info{
	char change;
	int x, y;
	
	info(char c, int x0, int y0): change(c), x(x0), y(y0){};
};

bool check(char add, int r, int c){
	int count, x, y;
	
	count = 0;
	for (int i = 0; i < dim; i++)	
		if (i != c && grid[r][i] != '+' && grid[r][i] != '.') count++;
	if (count == 2 || (count == 1 && add != '+')) return false; //CHECKING ROW
	
	count = 0;
	for (int i = 0; i < dim; i++)	
		if (i != r && grid[i][c] != '+' && grid[i][c] != '.') count++;
	if (count == 2 || (count == 1 && add != '+')) return false; //CHECKING COLUMN
	
	count = 0;
	for (int i = 1; i < dim; i++){
		x = r+i, y = c+i;
		
		if (x >= dim || y >= dim) break;
		if (grid[x][y] != 'x' && grid[x][y] != '.') count++;
	}
	if (count == 2 || (count == 1 && add != 'x')) return false; //CHECKING DOWN-RIGHT DIAG
	
	count = 0;
	for (int i = 1; i < dim; i++){
		x = r-i, y = c-i;
		
		if (x < 0 || y < 0) break;
		if (grid[x][y] != 'x' && grid[x][y] != '.') count++;
	}
	if (count == 2 || (count == 1 && add != 'x')) return false; //CHECKING UP-LEFT DIAG
	
	count = 0;
	for (int i = 1; i < dim; i++){
		x = r+i, y = c-i;
		
		if (x >= dim || y < 0) break;
		if (grid[x][y] != 'x' && grid[x][y] != '.') count++;
	}
	if (count == 2 || (count == 1 && add != 'x')) return false; //CHECKING DOWN-LEFT DIAG

	
	for (int i = 1; i < dim; i++){
		x = r-i, y = c+i;
		
		if (x < 0 || y >= dim) break;
		if (grid[x][y] != 'x' && grid[x][y] != '.') count++;
	}
	if (count == 2 || (count == 1 && add != 'x')) return false; //CHECKING UP-RIGHT DIAG
	
	return true;
}

int main(){
	int total, test, x, y, score, j;
	vector<info> changes;
	char c;
	bool rev;
	ifstream in("D-small-attempt2.in");
	ofstream out("out.txt");
	
	ios_base::sync_with_stdio(false);
    in.tie(NULL);	
	
	in >> test;
	
	for (int t = 1; t <= test; t++){
		in >> dim >> total;
		
		grid.clear(); grid.assign(dim, vector<char>());	
        changes.clear();
        score = 0;
		
		for (int i = 0; i < dim; i++) grid[i].assign(dim, '.');
		
		for (int i = 0; i < total; i++){
			in >> c >> x >> y; x--; y--;
			grid[x][y] = c;
		}
		
		for (int x = 0; x < dim; x++){
			j = x;
			int i = 0;
			if (grid[i][j] != 'o' && grid[i][j] != '.' && check('o', i, j)){
					grid[i][j] = 'o';
					changes.push_back(info('o', i, j));
				}
				
			else if (grid[i][j] == '.'){
				if (check('o', i, j)){
					grid[i][j] = 'o';
					changes.push_back(info('o', i, j));
				}
				else if (check('x', i, j)){
					grid[i][j] = 'x';
					changes.push_back(info('x', i, j));
				}
				else if (check('+', i, j)){
					grid[i][j] = '+';
					changes.push_back(info('+', i, j));
				}
			}
			if (grid[i][j] == '.') continue;
			else if (grid[i][j] == 'o') score += 2;
			else score++;
		}
		for (int i = dim-1; i >= 1; i--){
			if (i && grid[0][dim-1] == 'o') rev = true;
			else rev = false;
			
			for (int x = 0; x < dim; x++){
				if (rev) j = dim-x-1;
				else j = x;
				
				if (grid[i][j] != 'o' && grid[i][j] != '.' && check('o', i, j)){
					grid[i][j] = 'o';
					changes.push_back(info('o', i, j));
				}
				
				else if (grid[i][j] == '.'){
					if (check('o', i, j)){
						grid[i][j] = 'o';
						changes.push_back(info('o', i, j));
					}
					else if (check('x', i, j)){
						grid[i][j] = 'x';
						changes.push_back(info('x', i, j));
					}
					else if (check('+', i, j)){
						grid[i][j] = '+';
						changes.push_back(info('+', i, j));
					}
				}
				
				if (grid[i][j] == '.') continue;
				else if (grid[i][j] == 'o') score += 2;
				else score++;
			}
		}
		
		out << "Case #" << t << ": " << score << " " << changes.size() << "\n";
		
		for (int i = 0; i < changes.size(); i++) out << changes[i].change << " " << changes[i].x+1 << " " << changes[i].y+1 << "\n";

        //for (int i = 0; i < dim; i++){ for (j = 0; j < dim; j++) out << grid[i][j]; out << "\n";}
    }
	
	return 0;
}
