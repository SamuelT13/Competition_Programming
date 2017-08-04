#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

class QuickUnion{
	private: 
		int *id; //Stores root
		int *size; //Number of nodes rooted at i
	
	public:
		QuickUnion(int N){
			id = new int[N];
			size = new int[N];
			for (int i = 0; i < N; i++){ 
				id[i] = i; //Stores the root for each node
				size[i] = 1; //1 node rooted at i (i itself)
			}
		}
		
		int root(int i){
			while (i != id[i]){ //Goes up the tree
				id[i] = id[id[i]]; //Path Compression
				i = id[i];
			}
			return i; //Root is the same as node index -> root is the node i
		}
		
		bool find(int p, int q){
			return root(p)==root(q);
		}
		
		void unite(int p, int q){
			int i = root(p);
			int j = root(q);
			
			if (size[i] > size[j]){ //Weighted union (shortest has root of largest)
				id[j] = i;
				size[i] += size[j]; //More nodes
			}
			else{
				id[i] = j;
				size[j] += size[i]; //More nodes
			}
		}
};

int main(){
	vector< pair<int, pair<int, int> > > EdgeList;
	
	for (int i = 0; i < E; i++){
		cin >> u >> v >> w;
		
		EdgeList.push_back(make_pair(w, pair<int, int>(u, v)));
	} 
	
	sort(EdgeList.begin(), EdgeList.end());
	
	int mst_cost = 0;
	QuickUnion UF(V);
	
	for (int i = 0; i < E; i++){
		pair<int, pair<int, int> > front = EdgeList[i];
		if (!UF.find(front.second.first, front.second.second)){
			mst_cost += front.first;
			UF.unite(front.second.first, front.second.second);
		}
	}
	
	cout << "MST cost = " << mst_cost << " (Kruskal's)\n";
	return 0;
}
