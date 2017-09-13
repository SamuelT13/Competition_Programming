#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long int LL;
typedef pair<LL, LL> ii;

const int OK = 0;
const int UPD = 1;
const LL mod = 1e9+9;

struct segment_tree{
	vector<LL> tree;
	int N;
	vector<ii> lazy;
	
	void prop(int node, int nl, int nr){
		if (lazy[node].first == OK) return;
		
		tree[node] = (tree[node]*lazy[node].second)%mod;
		
		if (nl == nr){ lazy[node].first = OK, lazy[node].second = UPD; return;} //leaf
		
		lazy[2*node].first = lazy[2*node+1].first = lazy[node].first;
		
		lazy[2*node].second = (lazy[2*node].second*lazy[node].second)%mod;
		lazy[2*node+1].second = (lazy[2*node+1].second*lazy[node].second)%mod;

		lazy[node].first = OK, lazy[node].second = UPD;
	}
	
	segment_tree(int s){
		N = s;
		tree.resize(N*4);
		lazy.resize(N*4);
		
		init(1, 0, N-1);
	}
	
	LL init(int node, int nl, int nr){
		int nm = (nl+nr)/2;
		
		lazy[node].first = OK, lazy[node].second = UPD;
		
		if (nl == nr){ //leaf
			tree[node] = 1;
			return tree[node];
		}
		
		return tree[node] = (init(2*node, nl, nm) + init(2*node+1, nm+1, nr))%mod;
	}
	
	
	void mult(int start, int end, LL val){
		mult(start, end, 1, 0, N-1, val);
	}
	
	LL mult(int start, int end, int node, int nl, int nr, LL val){
		int nm = (nl+nr)/2;
		
		prop(node, nl, nr);
		
		if (end < nl || start > nr) return tree[node];
		
		if (start <= nl && nr <= end){
			lazy[node].first = OK, lazy[node].second = UPD;
			
			if (nl != nr){
				lazy[2*node].first = lazy[2*node+1].first = UPD;
				lazy[2*node].second = (lazy[2*node].second*val)%mod;
				lazy[2*node+1].second = (lazy[2*node+1].second*val)%mod;
			}
			return tree[node] = (val*tree[node])%mod;
		}
		
		return tree[node] = (mult(start, end, 2*node, nl, nm, val) +
							mult(start, end, 2*node+1, nm+1, nr, val))%mod;
	}
	
	LL query(int start, int end){
		return query(start, end, 1, 0, N-1);
	}
	
	LL query(int start, int end, int node, int nl, int nr){
		int nm = (nl+nr)/2;
		
		if (end < nl || start > nr) return 0;
		prop(node, nl, nr);
		
		if (start <= nl && nr <= end) return tree[node];
		
		LL query_l = query(start, end, 2*node, nl, nm),
			query_r = query(start, end, 2*node+1, nm+1, nr);
		
		return (query_l + query_r)%mod;
	}
};

int main(){
	LL total, Q, m, x, y, v;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	while (cin >> total >> Q){
		segment_tree st(total);
	
		for (int i = 0; i < Q; i++){
			cin >> m >> x >> y; x--, y--;
		
			if (m) cout << (mod+st.query(x, y))%mod << "\n";
			else{ cin >> v; st.mult(x, y, v%mod);}
		}
	}
	
	return 0;
}
