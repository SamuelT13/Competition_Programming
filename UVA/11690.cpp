#include <iostream>
using namespace std;

class QuickUnion{
	private: 
		int *id; //Stores root
		int *size; //Number of nodes rooted at i
		int *money;
	public:
		QuickUnion(int N, int m[]){
			id = new int[N];
			size = new int[N];
			money = new int[N];
			for (int i = 0; i < N; i++){ 
				id[i] = i; //Stores the root for each node
				size[i] = 1; //1 node rooted at i (i itself)
				money[i] = m[i];
			}
		}
		
		int cash(int i){
			return money[i];
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
				money[i] += money[j];
			}
			else{
				id[i] = j;
				size[j] += size[i]; //More nodes
				money[j] += money[i];
			}
		}
};

int main(){
	int test, total, friendships, next, *m, i, x, y;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	while (test--){
		cin >> total >> friendships;
		m = new int[total];
		
		for (i = 0; i < total; i++){
			cin >> m[i];
		}
		QuickUnion tree(total, m);
		
		for (i = 0; i < friendships; i++){
			cin >> x >> y;
			if (!tree.find(x,y)) tree.unite(x,y);
		}
		
		
		//for (i = 0; i < total; i++) cout << tree.root(i) << " "; cout << endl;
		
		for (i = 0; i < total; i++)
			if (tree.cash(tree.root(i)) != 0) break;
		
		
		if (i != total) cout << "IMPOSSIBLE\n";
		else cout << "POSSIBLE\n";
	}
	return 0;
}
