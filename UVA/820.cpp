#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

const int MAX_V = 105;
int res[MAX_V][MAX_V], max_flow, flow, s, t;
vector<int> p; //parent
//const int INF = 1000000000;


inline void augment(const int &v, const int &minEdge){
	if (v == s){
		flow = minEdge;
		return;
	}
		
	else if (p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		
		res[p[v]][v] -= flow;
		res[v][p[v]] += flow;
	}
}

int main(){
	int nodes, connections, x, y, count(0), band;
   
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
	while (scanf("%d", &nodes) == 1 && nodes){
		scanf("%d %d %d", &s, &t, &connections);
		s--; t--;
		
		memset(res, 0, sizeof res);

		while (connections--){
			scanf("%d %d %d", &x, &y, &band);
			x--; y--;
			res[x][y] += band;
			res[y][x] += band; 
		}
		
		max_flow = 0;
		
		while (1){
            		flow = 0;
			vector<int> dist(nodes, INT_MAX); dist[s] = 0;
			queue<int> q; q.push(s);
			p.assign(nodes, -1);
		
			while (!q.empty()){
				int index = q.front(); q.pop();
				
				if (index == t) break;
				
				for (int v = 0; v < nodes; v++)
					if (res[index][v] > 0 && dist[v] == INT_MAX){
						dist[v] = dist[index]+1;
						q.push(v);
						p[v] = index;
					}
			}
			
			augment(t, INT_MAX);
			if (flow == 0) break; //No more flow
			max_flow += flow;
		}
        
        	printf("Network %d\nThe bandwidth is %d.\n\n", ++count, max_flow);
	}	
	return 0;
}
