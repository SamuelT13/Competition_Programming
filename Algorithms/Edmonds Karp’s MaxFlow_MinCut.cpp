#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int AdjMatrix[MAX_V][MAX_V];
int res[MAX_V][MAX_V], max_flow, flow, s, t;
vector<int> p; //parent


void augment(int v, int minEdge){
	if (v == s)
		flow = minEdge;
		
	else if (p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		
		res[p[v]][v] -= flow;
		res[v][p[v]] += flow;
	}
}

int main(){
	// set up the 2d AdjMatrix 'res', 's', and 't' with appropriate values
	
	//code
	
	max_flow = 0;
	
	while (1){
		flow = 0;
		p.assign(MAX_V, -1);
		vector<int> dist(MAX_V, INF); dist[s] = 0;
		queue<int> q; q.push(s);
		
		while (!q.empty()){
			int index = q.front(); q.pop();
			
			if (index == t) break;
			
			for (int v = 0; v < MAX_V; v++)
				if (res[index][v] > 0 && dist[v] == INF){
					dist[v] = dist[index]+1;
					q.push(v);
					p[v] = index;
				}
		}
		
		augment(t, INF);
		if (flow == 0) break; //No more flow
		max_flow += flow;
	}
	
	return 0;
}
