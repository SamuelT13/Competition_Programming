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
	int test, nuts, bolts, connect, count(0);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	while (test--){
		cin >> nuts >> bolts;
		
		AdjList = new vector<int>[nuts];
		
		for (int i = 0; i < nuts; i++)
			for (int j = 0; j < bolts; j++){
				cin >> connect;
				if (connect)
					AdjList[i].push_back(nuts+j);
			}
			
		int MCBM = 0;
		match.assign(nuts+bolts+1, -1);
		
		for (int i = 0; i < nuts; i++){
			vis.assign(nuts, -1);
			MCBM += Aug(i);
		}
		
		cout << "Case " << ++count << ": a maximum of " << MCBM << " nuts and bolts can be fitted together\n";
	}
	return 0;
}

