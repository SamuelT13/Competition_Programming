#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vis, topo;
vector<vector<int> > Adj;

void ts(int ind){
	vis[ind] = 1;
	
	for (int i = 0; i < Adj[ind].size(); i++){
		int ind2 = Adj[ind][i];
		
		if (!vis[ind2]) ts(ind2);
	}
	
	topo.push_back(ind);
}

int main(){
	int test, total, ans, x;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> test;
	
	while (test--){
		ans++; vis.clear(); Adj.clear(); topo.clear();
		cin >> total;
		vis.assign(total, 0); Adj.assign(total, vector<int>());
		
		for (int i = 0; i < total; i++){
			cin >> x; x--; if (x == i) continue;
			Adj[x].push_back(i);
		}
		
		for (int i = 0; i < total; i++)
			if (!vis[i]) ts(i);
		reverse(topo.begin(), topo.end());
		
		ans = 0; vis.clear(); vis.assign(total, 0);
		for (int i = 0; i < total; i++)
			if (!vis[topo[i]]) ans++, ts(topo[i]);
		
		cout << ans << "\n";	
	}	
	
	return 0;
}
