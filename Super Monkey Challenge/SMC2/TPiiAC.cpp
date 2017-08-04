#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

vector<int> vis, dist;
vector<vector<int> > AdjList;

void dfs(int index){
	vis[index] = 1;
	
	for (int j = 0; j < (int)AdjList[index].size(); j++){
		int ind2 = AdjList[index][j];
		
		if (vis[ind2] == -1){
            dist[ind2] = dist[index] + 1;
            dfs(ind2);
        }
	}
}

int main(){
	int test, V, E, x, y, ind;
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> test;
	
	while (test--){
		AdjList.clear(); vis.clear(); dist.clear();
		cin >> V;
		ind = 0;
		E = V-1;
		AdjList.assign(V, vector<int>()); vis.assign(V, -1); dist.assign(V, INT_MAX);
	
		for (int i = 0; i < E; i++){
			cin >> x >> y;
			x--; y--;
			ind = x;
			AdjList[x].push_back(y); AdjList[y].push_back(x);
		}	
        
        dist[ind] = 0;
		dfs(ind);
		int maxim = -1;
        for (int i = 0; i < V; i++)
            if (dist[i] > maxim && dist[i] != INT_MAX){
                ind = i; 
                maxim = dist[i];
            }    
        //cout << "Start: " << ind+1;
        
        
        vis.assign(V, -1); dist.assign(V, INT_MAX); 
        dist[ind] = 0;
        dfs(ind);
		maxim = -1;
        for (int i = 0; i < V; i++)
            if (dist[i] > maxim && dist[i] != INT_MAX){
                ind = i; 
                maxim = dist[i];
            }    
        
       //cout << " | End: " << ind+1 << " | Max: ";
		
		cout << maxim+1 << "\n";
	}
	
	return 0;
}
