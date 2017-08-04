#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> ii;

vector<ii> *AdjList;

int main(){
	int test, servers, cables, s, e, x, y, weight;
	
	cin >> test;
	
	for(int j = 1; j <= test; j++){
		cin >> servers >> cables >> s >> e;
		
		AdjList = new vector<ii>[servers];
		
		for (int i = 0; i < cables; i++){
			cin >> x >> y >> weight;
			AdjList[x].push_back(make_pair(y,weight));
			AdjList[y].push_back(make_pair(x,weight));
		}	
		
		vector<int> dist(servers, INF); dist[s] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, s));
		
		while (!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			
			if (d > dist[u]) continue;	//longest weighted path is discarded
			
			for (int j = 0; j < (int)AdjList[u].size(); j++){
				ii v = AdjList[u][j];
				
				if (dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u] + v.second;		//relax op
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		
		cout << "Case #" << j << ": ";
		(dist[e] == INF)?cout << "unreachable\n":cout << dist[e] << "\n";
	}
	return 0;	 
}
