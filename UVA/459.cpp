#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
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
	int test, count(0), amount_test(0), i, largest;
	string next;
	QuickUnion tree(0);
	set<int> roots;

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	cin >> test;
	getline(cin, next); getline(cin, next);
	
	while (test){
		getline(cin, next);
		largest = next[0]-'A';
		tree = QuickUnion(largest+1);
		
		while (getline(cin,next) && !next.empty())
			tree.unite(next[0]-'A',next[1]-'A');
		
	
		if (amount_test) cout << "\n";
		amount_test++;	
			
		test--;
		roots.clear();
			
		for (i = 0; i < largest+1; i++) roots.insert(tree.root(i));
		count = 0;
		cout << roots.size() << "\n";
	}
	
	return 0;
}
