#include <iostream>
#include <vector>
using namespace std;

const int UNVISITED = -1;
vector<int> dfs_num, dfs_low, visited, S;
int numSCC, dfsNumberCounter;
vector<int> *AdjList;

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
		//cout << "SCC " << ++numSCC << ":";
	    ++numSCC;
		
		while (1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			//cout << " " << v;
			if (index == v) break;
		}
		//cout << "\n";
	}
}

int main(){
	int inter, streets, i, j, V, W, way;
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	while(cin >> inter >> streets && (inter||streets)){
		dfs_num.clear(); dfs_low.clear(); visited.clear(); S.clear();
		 
		AdjList = new vector<int>[inter];
	
		for (i = 0; i < inter; i++) AdjList[i].clear();
		
		for (i = 0; i < streets; i++){
			cin >> V >> W >> way;
		
			if (way == 1) AdjList[V-1].push_back(W-1);
			else {
				AdjList[V-1].push_back(W-1);
				AdjList[W-1].push_back(V-1);
			}
		}
		
		dfsNumberCounter = numSCC = 0;
  		dfs_num.assign(inter, UNVISITED);
    	dfs_low.assign(inter, 0);
		visited.assign(inter, 0);
	
        for (i = 0; i < inter; i++){
            if (dfs_num[i] == UNVISITED)
                  tarjanSCC(i);
			if (numSCC > 1) break;
		}
		
		if (numSCC > 1) cout << 0 << "\n";
		else cout << 1 << "\n";
	}
		
	return 0;
}
