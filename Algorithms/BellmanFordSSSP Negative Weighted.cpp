#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> ii;

int main(){
	vector<int> dist(V, INF); dist[s] = 0;

	//Bellman-Ford Relaxation Algorithm
	for (int i = 0; i < V-1; i++)
		for (int u = 0; u < V; u++)
			for (int j = 0; j < (int)AdjList[u].size(); j++){
				ii v = AdjList[u][j];
				dist[v.first] = min(dist[v.first], dist[u] + v.second);
			}
			
	//Negative Cycle Check
	bool hasNegativeCycle = false;
	
	for (int u = 0; u < V; u++)
		for (int j = 0; j < (int)AdjList[u].size(); j++){
			ii v = AdjList[u][j];
			
			if (dist[v.first] > dist[u] + v.second)
				hasNegativeCycle = true;
		}
			
	return 0;
}
