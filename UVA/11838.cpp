#include <iostream>
#include <vector>
using namespace std;

const int UNVISITED = -1;
const int VISITED = 1;

vector<int> *AdjList;
vector<int> dfs_num;
 
void dfs(int index){
	dfs_num[index] = VISITED;
	
	for (int j = 0; j < (int)AdjList[index].size(); j++){
        int ind2 = AdjList[index][j];
        if (dfs_num[ind2] == UNVISITED) dfs(ind2);
	}
}


int main(){
	int inter, streets, i, j, V, W, way;
	
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	while(cin >> inter >> streets && (inter||streets)){
		dfs_num.clear(); dfs_num.assign(inter, UNVISITED);
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
		
		for (i = 0; i < inter; i++){
			dfs_num.clear(); dfs_num.assign(inter, UNVISITED);
			dfs(i);
			for (j = 0; j < inter; j++) if (dfs_num[j] == UNVISITED) break;
			if (j != inter) break;
		}
		if (i != inter) cout << 0 << "\n";
		else cout << 1 << "\n";
	}
	
	return 0;
}

