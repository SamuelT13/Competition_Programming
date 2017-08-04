#include <iostream>
using namespace std;

int faces;

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
			
			if (i == j){
				faces++;
				return;
			}
			
			if (size[i] > size[j]){ //Weighted union (shortest has root of largest)
				id[j] = i;
				size[i] += size[j]; //More nodes
			}
			else{
				id[i] = j;
				size[j] += size[i]; //More nodes
			}
		}
		
		void show(int N){
			for (int i = 0; i < N; i++) cout << id[i] << " "; cout << endl;
		}
};

int main(){
	int nodes, edges, id_x, id_y;
	char x, y;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> nodes >> edges){
		QuickUnion alp(52);
		faces = 1;
		
		while (edges--){
			cin >> x >> y;
			if (isupper(x)) id_x = x-'A';
			else id_x = 26+x-'a';
			if (isupper(y)) id_y = y-'A';
			else id_y = 26+y-'a';
			
			alp.unite(id_x,id_y);
 		}
 		
		cout << faces << "\n";
	}
	
	return 0;
	
}
