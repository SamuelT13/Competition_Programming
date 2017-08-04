#include <iostream>
#include <vector>
using namespace std;

const int UNVISITED = -1;
const int VISITED = 1;

int dfsNumberCounter;
vector<int> dfs_num, dfs_parent, dfs_low;
vector<int> *AdjList;

void articulationPointAndBridge(int index, bool &found) {
	dfs_low[index] = dfs_num[index] = dfsNumberCounter++; // dfs_low[index] <= dfs_num[index]
	
	for (int j = 0; j < (int)AdjList[index].size(); j++) {
		int ind2 = AdjList[index][j];
		
		if (dfs_num[ind2] == UNVISITED) { // a tree edge
			dfs_parent[ind2] = index;
			
			articulationPointAndBridge(ind2, found);
			
			if (dfs_low[ind2] > dfs_num[index]) // for bridge
				found = true;
			dfs_low[index] = min(dfs_low[index], dfs_low[ind2]); // update dfs_low[index]
		}
		
		else if (ind2 != dfs_parent[index]) // a back edge and not direct cycle
			dfs_low[index] = min(dfs_low[index], dfs_num[ind2]); // update dfs_low[index]
	} 
}

int main(){
		
	dfsNumberCounter = 0; found = false;
		
	dfs_num.clear(); dfs_num.assign(V, UNVISITED); 
	dfs_low.clear(); dfs_low.assign(V, 0);
	dfs_parent.clear(); dfs_parent.assign(V, 0);
		
	AdjList = new vector<int>[V];
		
	return 0;
}

