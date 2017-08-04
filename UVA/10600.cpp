#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
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
	int test, x, y, cost, schools, connections, new_cost;
	//ifstream in("input.txt"); ofstream out("output1.txt");
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	while (test--){
		cin >> schools >> connections;
	
		vector< pair<int, pair<int, int> > > EdgeList, edges;
		
		for (int i = 0; i < connections; i++){
			cin >> x >> y >> cost;
			
			EdgeList.push_back(make_pair(cost, pair<int, int>(min(x-1, y-1), max(x-1, y-1))));
			
			sort(EdgeList.begin(), EdgeList.end());
		} 
		
		//First MST
		int mst_cost = 0;
		QuickUnion UF(schools);
		edges.clear();
		
		for (int i = 0; i < connections; i++){
			pair<int, pair<int, int> > front = EdgeList[i];
			if (!UF.find(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unite(front.second.first, front.second.second);
				edges.push_back(EdgeList[i]);
			}
		}
		
		//Second-best MST		
		cout << mst_cost  << " ";
		mst_cost = -1;
		for (int j = 0; j < (int)edges.size(); j++){
            int count(0);
            int p = 
			new_cost = 0;
			QuickUnion UF(schools);
			
			for (int i = 0; i < connections; i++){
				pair<int, pair<int, int> > front = EdgeList[i];
	
				if (!UF.find(front.second.first, front.second.second) && EdgeList[i] != edges[j]){
                    count++;
					new_cost += front.first;
					UF.unite(front.second.first, front.second.second);
				}
			}
			
			if ((mst_cost == -1 || new_cost <= mst_cost) && count == schools-1) mst_cost = new_cost;
		}
		cout << mst_cost << "\n";
	}
	return 0;
}
