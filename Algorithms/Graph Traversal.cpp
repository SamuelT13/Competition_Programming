#include <iostream>
#include <vector>
using namespace std;

//DEPTH FIRST TRAVERSAL (DFS)
vector<int> dfs_num;
const int VISITED = 1;
const int UNVISITED = -1;

void dfs(int u){
	dfs_num[u] = VISITED;
	
	for (int j = 0; j < (int)AdjList[u].size(); j++){
		pair<int,int> v = AdjList[u][j];
		if (dfs_num[v.first] == UNVISITED)
			dfs(v.first);
	}
}

//BREADTH FIRST TRAVERSAL (BFS)

*** INSIDE int main() ***
	vector<int> d(V, INF); d[s] = 0;
	queue<int> q; q.push(s);
	
	while (!q.empty()){
		int u = q.front(); q.pop();
		
		for (int j = 0; j < (int)AdjList[u].size(); j++){
			pair<int, int> v = AdjList[u][j];
			
			if (d[v.first] == INF){
				d[v.first] = d[u]+1;
				q.push(v.first);
			}
		}
	}
