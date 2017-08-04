#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
	public:
	int key, c;
};

vector<info> speak[26];

int dr[8] = {1, 0,-1, 0};
int dc[8] = {0, 1, 0,-1};

char ** grid;

int floodfill(int r, int R, int c, int C, char c1, char c2){
	if (r < 0 || r >= R || c < 0 || c >= C) return 0;
	if (grid[r][c] != c1) return 0;
	int ans = 1;
	grid[r][c] = c2;
	
	for (int d = 0; d < 4; d++)
		ans += floodfill(r+dr[d], R, c+dc[d], C, c1, c2);
	return ans;
}

bool f(vector<info> v1, vector<info> v2){
	return v1[0].c > v2[0].c;
}

int main(){
	int r, c, i, j, count(0), test;
	//ifstream in("test.txt"); ofstream out("ok.txt");
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	while (test--){
		cin >> r >> c;
		grid = new char*[r];
		for (i = 0; i < 26; i++)
			speak[i].clear();
		
		for (i = 0; i < r; i++){
			grid[i] = new char[c];
			for (j = 0; j < c; j++)
				cin >> grid[i][j];
		}	
	
		for (i = 0; i < 26; i++){
			info temp;
			temp.key = 'a'+i;
			temp.c = 0;		
			speak[i].push_back(temp);
		}
			
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				if (grid[i][j] != 'A'){
					speak[grid[i][j]-'a'][0].key = grid[i][j];
					speak[grid[i][j]-'a'][0].c++;
					floodfill(i,r,j,c,grid[i][j],'A');
				}
		
		stable_sort(speak, speak+26, f);
		
		cout << "World #" << ++count << "\n";
		
		for (i = 0; i < 26; i++)
			if (speak[i][0].c) cout << char(speak[i][0].key) << ": " << speak[i][0].c << "\n";
		
		/*for (i = 0; i < r; i++){
			for (j = 0; j < c; j++)
				cout << grid[i][j];
			cout << endl;
		}*/	
	}
	
	return 0;
}
