#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int UNVISITED = -1;
const int VISITED = 1;

struct br{
	int x, y;
};

bool order(br b1, br b2){
	if (b1.x == b2.x) return b1.y < b2.y;
	
	return b1.x < b2.x;
}

int dfsNumberCounter;
vector<int> dfs_num, dfs_parent, dfs_low;
vector<int> *AdjList;
vector<br> bridges; 
br temp;

void articulationPointAndBridge(int index) {
	dfs_low[index] = dfs_num[index] = dfsNumberCounter++; // dfs_low[index] <= dfs_num[index]
	
	for (int j = 0; j < (int)AdjList[index].size(); j++) {
		int ind2 = AdjList[index][j];
		
		if (dfs_num[ind2] == UNVISITED) { // a tree edge
			dfs_parent[ind2] = index;
			
			articulationPointAndBridge(ind2);
			
			if (dfs_low[ind2] > dfs_num[index]){ // for bridge
				temp.x = min(index,ind2); temp.y = max(index,ind2);
				bridges.push_back(temp);
			}
			dfs_low[index] = min(dfs_low[index], dfs_low[ind2]); // update dfs_low[index]
		}
		
		else if (ind2 != dfs_parent[index]) // a back edge and not direct cycle
			dfs_low[index] = min(dfs_low[index], dfs_num[ind2]); // update dfs_low[index]
	} 
}

int main(){
	int size, node, total, next, i;
	char par;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(cin >> total){
		dfsNumberCounter = 0;
		dfs_num.clear(); dfs_num.assign(total, UNVISITED); 
		dfs_low.clear(); dfs_low.assign(total, 0);
		dfs_parent.clear(); dfs_parent.assign(total, 0);
		bridges.clear();
		AdjList = new vector<int>[total];	
	
		while (total--){
			cin >> node >> par >> size >> par;
			while (size--){
				cin >> next;
				AdjList[node].push_back(next);
			} 
		}
		
		for (i = 0; i < (int)dfs_num.size(); i++)
			if (dfs_num[i] == UNVISITED)
				articulationPointAndBridge(i);
				
		sort(bridges.begin(), bridges.end(), order);
		
		cout << bridges.size() << " critical links\n";
		for (i = 0; i < (int)bridges.size(); i++) cout << bridges[i].x << " - " << bridges[i].y << "\n";
		cout << "\n";
	}
	
	return 0;
}

