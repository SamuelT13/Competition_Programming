#include <iostream>
#include <vector>
using namespace std;

const int UNVISITED = -1;
vector<int> dfs_num, dfs_low, S, visited;
int numSCC, dfsNumberCounter;

void tarjanSCC(int index){
	dfs_low[index] = dfs_num[index] = dfsNumberCounter++;
	S.push_back(index); //order of visitation
	visited[index] = 1;
	
	for (int j = 0; j < (int)AdjList[index].size(); j++){
		int ind2 = AdjList[index][j];
		
		if (dfs_num[ind2] == UNVISITED)
			tarjanSCC(ind2);
		if (visited[ind2]) //Condition for update
			dfs_low[index] = min(dfs_low[index], dfs_low[ind2]);	
	}
	
	if (dfs_low[index] == dfs_num[index]){ //root of SCC
		cout << "SCC " << ++numSCC << ":";
		while (1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			cout << " " << v;
			if (index == v) break;
		}
		cout << "\n";
	}
}

int main(){
	dfs_num.assign(V, UNVISITED);
	dfs_low.assign(V, 0);
	visited.assign(V, 0);
	dfsNumberCounter = numSCC = 0;
	
	for (int i = 0; i < V; i++)
		if (dfs_num[i] == UNVISITED)
			tarjanSCC(i);
		
	return 0;
}
