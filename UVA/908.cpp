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
	int total, x, y, cost, K, M, i(0);	
	vector< pair<int, pair<int, int> > > EdgeList, KList;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> total){
		EdgeList.clear(); KList.clear();
		if (i) cout << "\n";
		i++;
		
		for (int i = 0; i < total-1; i++)
			cin >> x >> y >> cost;
		
		//K lines
		cin >> K;
		for (int i = 0; i < K; i++){
			cin >> x >> y >> cost;
			KList.push_back(make_pair(cost, make_pair(x-1, y-1)));	
		}
		
		//M lines
		if (true){
			cin >> M;
			for (int i = 0; i < M; i++){
				cin >> x >> y >> cost;
				
				EdgeList.push_back(make_pair(cost, pair<int, int>(x-1, y-1)));
			} 
			
			sort(EdgeList.begin(), EdgeList.end());
			int mst_cost = 0;
			QuickUnion UF(total);
			
			for (int i = 0; i < (int)EdgeList.size(); i++){
				pair<int, pair<int, int> > front = EdgeList[i];
				if (!UF.find(front.second.first, front.second.second)){
					mst_cost += front.first;
					UF.unite(front.second.first, front.second.second);
				}
			}
			
			cout << mst_cost << "\n";
		}
			
		//M+K lines
		if (true){
			for (int i = 0; i < (int)KList.size(); i++)
				EdgeList.push_back(KList[i]);
			
			sort(EdgeList.begin(), EdgeList.end());
			
			int mst_cost = 0;
			QuickUnion UF(total);
			
			for (int i = 0; i < (int)EdgeList.size(); i++){
				pair<int, pair<int, int> > front = EdgeList[i];
				if (!UF.find(front.second.first, front.second.second)){
					mst_cost += front.first;
					UF.unite(front.second.first, front.second.second);
				}
			}
			
			cout << mst_cost << "\n";
		}
	}
	
	return 0;
}
