#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> ii;

//weight is int

int main(){
	vector<int> dist(V, INF); dist[s] = 0; //s is source node
	priority_queue<ii, vector<ii>, greater<ii> > pq;	//sorts by increasing weight
	pq.push(ii(0, s)); //push (0, s) weight/node pair
	
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

	return 0;	 
}
