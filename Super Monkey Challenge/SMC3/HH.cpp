using namespace std;

const int INF = 1e9;

int main(){
	vector<vector<int> > AdjMat;
	int m(INF), V, E, x, y, c;
	vector<int> ans;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> V >> E;
	
	AdjMat.assign(V, vector<int>());
	for (int i = 0; i < V; i++){
		AdjMat[i].assign(V, INF);
		AdjMat[i][i] = 0;
	}
	
	for (int i = 0; i < E; i++){
		cin >> x >> y; x--, y--;
		AdjMat[x][y] = AdjMat[y][x] = 1;
	}
	
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)	
			for (int j = 0; j < V; j++)
				AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k]+AdjMat[k][j]);
	
	for (int i = 0; i < V; i++){
		c = -1;
		for (int j = 0; j < V; j++){
			if (i == j) continue;
			c = max(AdjMat[i][j], c);
		}
		
		if (c < m){
			m = c; ans.clear(); ans.push_back(i+1);
		}
		else if (c == m) ans.push_back(i+1);
	}

	if (m == INF) cout << "none\n"; 
	else{
		cout << ans.size();
		for (int i = 0; i < ans.size(); i++) cout << " " << ans[i];
		cout << "\n";
	}
	
	return 0;
}
