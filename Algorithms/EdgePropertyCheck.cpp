#include <iostream>
#include <vector>
using namespace std;

vector<int> *AdjList;
vector<int> dfs_num;
vector<int> dfs_parent;

const int UNVISITED = -1;
const int VISITED = 1;
const int EXPLORED = 2;

void graphCheck(int index){
	dfs_num[index] = EXPLORED;
	
	for (int j = 0; j < (int)AdjList[index].size(); j++){
		int ind2 = AdjList[index][j];
		
		if (dfs_num[ind2] == UNVISITED){
			//cout << "EDGE: " << index << " - " << ind2 << "\n"; 
			dfs_parent[ind2] = index;
			graphCheck(ind2);
		}
		else if (dfs_num[ind2] == EXPLORED){
			if (ind2 == dfs_parent[index])
				cout << "TWO WAYS: " << index << " - " << ind2 << ", " << ind2 << " - " << index << "\n";
			else
				cout << "BACK EDGE (Cycle): " << index << " - " << ind2 << "\n";
		}
		else if (dfs_num[ind2] == VISITED)
			cout << "Forward/Cross Edge: " << index << " - " << ind2 << "\n";
	}
	
	dfs_num[index] = VISITED;
}

int main(){
	int x, y, V, i;
		
	cin >> V;
	
	dfs_num.assign(V, UNVISITED);
	dfs_parent.assign(V, 0);
	AdjList = new vector<int>[V];
	
	while (cin >> x >> y){
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}
	
	for (i = 0; i < V; i++)
		if (dfs_num[i] == UNVISITED) graphCheck(i);
		
	return 0;
}
