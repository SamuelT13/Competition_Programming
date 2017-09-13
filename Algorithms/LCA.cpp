#include <iostream>
#include <vector>
using namespace std;

typedef long long int LL;
typedef pair<int, int> ii;

const int MAX_VALUE = 1e9;

struct segment_tree{
	int size;
	vector<ii> tree;
	
	segment_tree(const vector<ii>& vals){
		size = vals.size();
		tree.resize(4 * size);
		if (size > 0) initialize(0, 0, size - 1, vals);
	}
	
	ii initialize(int node, int nleft, int nright, const vector<ii>& vals){
		if (nleft == nright) tree[node] = vals[nleft];
		
		else{
			int nmid = (nleft + nright) / 2;
			tree[node] = min(
							  initialize(2 * node + 1, nleft, nmid, vals),
							  initialize(2 * node + 2, nmid + 1, nright, vals)
							);
		}
		
		return tree[node];
	}
	
	ii query(int start, int end) const{
		return query(start, end, 0, 0, size - 1);
	}
	
	ii query(int start, int end, int node, int nleft, int nright) const{
		if (nright < start || end < nleft) return ii(MAX_VALUE, -1);
		if (start <= nleft && nright <= end) return tree[node];
		
		int nmid = (nleft + nright) / 2;
		return min(
					query(start, end, 2 * node + 1, nleft, nmid),
					query(start, end, 2 * node + 2, nmid + 1, nright)
				   );
	}
};

vector<ii> preorder, pos;
vector<int> vis, h;
vector<LL> dist;
vector<vector<ii> > AdjList;

void dfs(int ind){
	preorder.push_back(ii(h[ind], ind));
	vis[ind] = 1;
	
	for (int i = 0; i < AdjList[ind].size(); i++){
		int v = AdjList[ind][i].second;
		
		if (!vis[v]){
			if (h[v] == -1) h[v] = h[ind]+1;
			
			dfs(v); preorder.push_back(ii(h[ind], ind)); 
		}
	}	
}

void find_dist(int ind){ //it's a tree, so there's only 1 unique path between any 2 vertices (i.e. no need for Djikstra)
	for (int i = 0; i < AdjList[ind].size(); i++){
		int v = AdjList[ind][i].second;
		
		if (dist[v] == -1){
			dist[v] = dist[ind] + AdjList[ind][i].first;
			find_dist(v);
		}
	}	
}

int main(){
	int V, Q, y, l, LCA;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> V && V){
		preorder.clear();
		AdjList.clear(); AdjList.assign(V, vector<ii>());
		vis.clear(); vis.assign(V, 0); 
		h.clear(); h.assign(V, -1);
		dist.clear(); dist.assign(V, -1);
		pos.clear(); pos.assign(V, ii(MAX_VALUE, -MAX_VALUE));
		
		for (int i = 1; i < V; i++){
			cin >> y >> l;
			AdjList[i].push_back(ii(l, y)), AdjList[y].push_back(ii(l, i));
		}
	
		dist[0] = h[0] = 0, find_dist(0), dfs(0);
		segment_tree tree(preorder);
		
		for (int i = 0; i < preorder.size(); i++)
			pos[preorder[i].second].first  = min(pos[preorder[i].second].first, i),
			pos[preorder[i].second].second = max(pos[preorder[i].second].second, i);
		
		cin >> Q;
		
		for (int i = 0; i < Q; i++){
			if (i) cout << " "; cin >> y >> l;
				
			LCA = tree.query(min(pos[y].first, pos[l].first),
							 max(pos[y].second, pos[l].second)).second;
			cout << dist[y] + dist[l] - 2*dist[LCA];
		}

		cout << "\n";
	}
	
	return 0;
}
