//NOT FINISHED

#include <iostream>
#include <vector>
using namespace std;


struct info{
	int x, y;
	bool  operator ==(info n2){
		return ((this->x == n2.x && this->y == n2.y)||(this->x == n2.y && this->y == n2.x));
	}
};

vector<int> *AdjList;
vector<int> dfs_num;
vector<int> dfs_parent;
vector<info> edges; 
vector<info> chain;
vector<info> out;
info temp;

const int UNVISITED = -1;
const int VISITED = 1;
const int EXPLORED = 2;

void graphCheck(int index){
	dfs_num[index] = EXPLORED;
	
	for (int j = 0; j < (int)AdjList[index].size(); j++){
		int ind2 = AdjList[index][j];
		
		if (dfs_num[ind2] == UNVISITED){
			//cout << "EDGE: " << index << " - " << ind2 << "\n"; 
			dfs_parent[ind2] = index;
			graphCheck(ind2);
		}
		else if (dfs_num[ind2] == EXPLORED){
			if (ind2 == dfs_parent[index]){
				temp.x = index; temp.y = ind2;
				edges.push_back(temp);
				cout << "TWO WAYS: " << index << " - " << ind2 << ", " << ind2 << " - " << index << "\n";
			}	
			else{
				for (int i = 0; i < (int)edges.size(); i++){
					cout << "CHAIN: " << edges[i].x << " " << edges[i].y << "\n";
					chain.push_back(edges[i]);
				}
				edges.clear();
				
				cout << "BACK EDGE (Cycle): " << index << " - " << ind2 << "\n";
			}
		}
     
		else if (dfs_num[ind2] == VISITED){
			temp.x = index; temp.y = ind2;
			edges.push_back(temp);
			cout << "Forward/Cross Edge: " << index << " - " << ind2 << "\n";
		}	
	}
	
	dfs_num[index] = VISITED;
}

int main(){
	int x, y, V, i, j, total, count(0);
	char par;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	while (cin >> V){
		if (!count){
			cout << "\n";
			count++;
		}
		
		dfs_num.clear(); dfs_num.assign(V, UNVISITED);
		dfs_parent.clear(); dfs_parent.assign(V, 0);
		AdjList = new vector<int>[V];
		edges.clear(); chain.clear(); out.clear();
	
		for (i = 0; i < V; i++){
			cin >> x >> par >> total >> par;
			while (total--){
				cin >> y;
				AdjList[x].push_back(y);
			}
		}
	
		for (i = 0; i < V; i++){
			for (j = 0; j < (int)AdjList[i].size(); ++) cout << AdjList[i][j] << " ";
			cout << "\n";
		}
		for (i = 0; i < V; i++)
			if (dfs_num[i] == UNVISITED) graphCheck(i);
		
		for (i = 0; i < (int)edges.size(); i++){		
			for (j = 0; j < (int)chain.size(); j++)
				if (edges[i] == chain[j]) break;
			if (j == chain.size())
				out.push_back(edges[i]);
		}
	
		cout << out.size() << " critical links\n";
		for (vector<info>::iterator it = out.begin(); it != out.end(); it++)
			cout << min(it->x,it->y) << " - " << max(it->x,it->y) << "\n";
	}
	
	return 0;
}
