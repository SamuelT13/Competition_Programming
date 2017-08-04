#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> ii;

vector<int> topo_s, visited;
vector<ii> *AdjList;

void topo(int index){
	visited[index] = 1;
	
	for (int j = 0; j < (int)AdjList[index].size(); j++){
		int ind2 = AdjList[index][j].first;
		
		if (visited[ind2] == -1) topo(ind2);
	}
	
	topo_s.push_back(index);
}

int main(){
	int test, systems, wormholes, ind, x, y, time;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	while (test--){
		topo_s.clear();
		cin >> systems >> wormholes;
		
		AdjList = new vector<ii>[systems];
		
		for (int i = 0; i < wormholes; i++){
			cin >> x >> y >> time;
			ind = x;
			
			AdjList[x].push_back(make_pair(y, time));
		}
	
	
		visited.assign(systems, -1);
		topo(ind);
		vector<int> dist(systems, INF); dist[topo_s[topo_s.size()-1]] = 0;
	
		//Bellman-Ford Relaxation Algorithm
		for (int i = 0; i < systems-1; i++)
			for (int u = 0; u < systems; u++)
				for (int j = 0; j < (int)AdjList[u].size(); j++){
					ii v = AdjList[u][j];
					dist[v.first] = min(dist[v.first], dist[u] + v.second);
				}
			
		//Negative Cycle Check
		bool hasNegativeCycle = false;
	
		for (int u = 0; u < systems; u++)
			for (int j = 0; j < (int)AdjList[u].size(); j++){
				ii v = AdjList[u][j];
			
				if (dist[v.first] > dist[u] + v.second)
					hasNegativeCycle = true;
			}

		hasNegativeCycle?cout << "possible\n":cout << "not possible\n";
	}
	
	return 0;
}
