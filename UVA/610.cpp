#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int UNVISITED = -1;
const int VISITED = 1;
const int EXPLORED = 2;

struct br{
	int x, y;
};

int dfsNumberCounter;
vector<int> dfs_num, dfs_parent, dfs_low, dfs_vis;
vector<int> *AdjList;
br temp;
vector<br> edges;

bool order(br e1, br e2){
	if (e1.x == e2.x) return e1.y < e2.y;
	return e1.x < e2.x;
}

void articulationPointAndBridge(int index) {
	dfs_vis[index] = EXPLORED;
	dfs_low[index] = dfs_num[index] = dfsNumberCounter++; // dfs_low[index] <= dfs_num[index]
	
	for (int j = 0; j < (int)AdjList[index].size(); j++) {
		int ind2 = AdjList[index][j];
		
		if (dfs_vis[ind2] == UNVISITED) { // a tree edge
			//cout << "EDGE: ";
			cout << index+1 << " " << ind2+1 << "\n";
			//temp.x = index; temp.y = ind2;
			//edges.push_back(temp);
			dfs_parent[ind2] = index;
			
			articulationPointAndBridge(ind2);
			
			if (dfs_low[ind2] > dfs_num[index]){ // for bridge
				//cout << "BRIDGE: ";
				//temp.x = ind2, temp.y = index;
				//edges.push_back(temp);
				cout << ind2+1 << " " << index+1 << "\n";
			}
			dfs_low[index] = min(dfs_low[index], dfs_low[ind2]); // update dfs_low[index]
		}
		
		else if (ind2 != dfs_parent[index] && dfs_vis[ind2] == EXPLORED){ // a back edge and not direct cycle
			//cout << "BACK EDGE: ";
			cout << index+1 << " " << ind2+1 << "\n";
			//temp.x = index; temp.y = ind2;
			//edges.push_back(temp);
			dfs_low[index] = min(dfs_low[index], dfs_num[ind2]); // update dfs_low[index]
		}
	} 
	
	dfs_vis[index] = VISITED;
}

int main(){
	int size, node, total, next, e, i, count(1);
	char par;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(cin >> total >> e && (total || e)){
		cout << count++ << "\n\n";
		dfsNumberCounter = 0;
		dfs_num.clear(); dfs_num.assign(total, UNVISITED); 
		dfs_low.clear(); dfs_low.assign(total, 0);
		dfs_parent.clear(); dfs_parent.assign(total, 0);
		dfs_vis.clear(); dfs_vis.assign(total,UNVISITED);
		edges.clear();
		
		AdjList = new vector<int>[total];	
	
		while (e--){
			cin >> node >> next;
			AdjList[node-1].push_back(next-1);
			AdjList[next-1].push_back(node-1);
		}
		
		for (i = 0; i < (int)dfs_num.size(); i++)
			if (dfs_num[i] == UNVISITED)
				articulationPointAndBridge(i);
			
		//sort(edges.begin(), edges.end(), order);
		//for (i = 0; i < (int)edges.size(); i++) cout << edges[i].x+1 << " " << edges[i].y+1 << "\n";
		cout << "#\n";
	}
	
	return 0;
}

