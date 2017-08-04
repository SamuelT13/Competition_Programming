//Maximum Cardinality Bipartite Matching (max matchings/groups)
//using Augmenting Paths

#include <iostream>
#include <vector>
using namespace std;

vector<int> match, vis;
vector<int> *AdjList;

int Aug(int index){
	if (vis[index] == 1) return 0;
	vis[index] = 1;
	
	for (int j = 0; j < (int)AdjList[index].size(); j++){
		int ind2 = AdjList[index][j];
		if (match[ind2] == -1 || Aug(match[ind2])){
			match[ind2] = index;
			return 1;
		}
	}
	return 0;
}

// in int main(), build the bipartite graph
// only directed edge from left set to right set is needed

int main(){
	int MCBM = 0;
	match.assign(V, -1);
	
	for (int i = 0; i < Vleft; i++){
		vis.assign(Vleft, -1);
		MCBM += Aug(i);
	}
	
	cout << MCBM << " matchings.\n";
	
	return 0;
}
