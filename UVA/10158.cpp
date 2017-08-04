#include <iostream>
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
		
		void show(int N){
			for (int i = 0; i < N; i++) cout << id[i] << " "; cout << endl;
		}
};

int main(){
	int people, op, x, y, i, enemy_x, enemy_y;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> people;
	QuickUnion countries(2*people);
	
	while (cin >> op >> x >> y && (op || x || y)){
		enemy_x = x+people;
		enemy_y = y+people;
		
		if (op == 1){	
			if (countries.find(x,enemy_y)) cout << -1 << "\n"; //If x ~ enemy_y && enemy_y * y, then x * y
			else{
				countries.unite(x,y);
				countries.unite(enemy_x, enemy_y);
			}
		}
		
		else if (op == 2){
			if (countries.find(x,y)) cout << -1 << "\n"; //If x ~ y, then x !* y
			else{
				countries.unite(x, enemy_y);
				countries.unite(enemy_x ,y);
			}
		}
		else if (op == 3){
			if (countries.find(x,y)) cout << 1 << "\n"; //Check if x ~ y
			else cout << 0 << "\n";
		}
		else{
			if (countries.find(enemy_x,y)) cout << 1 << "\n"; //Check if enemy_x ~ y -> x * y
			else cout << 0 << "\n";
		}
	}
	
	//countries.show(2*people);
	
	return 0;
}
