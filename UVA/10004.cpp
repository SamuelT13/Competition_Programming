#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int VISITED = 1;
const int UNVISITED = -1;

vector<int> *AdjList;
vector<int> dfs_num;
vector<int> topo;

void dfs(int index){
    dfs_num[index] = VISITED;
    
    for (int j = 0; j < (int)AdjList[index].size(); j++){
        int ind2 = AdjList[index][j];
        
        if (dfs_num[ind2] == UNVISITED)
            dfs(ind2);
    }
    
    topo.push_back(index);
}

int main(){
	int V, E, x, y, s;
	bool isBipartite;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> V && V){
        	isBipartite = true;
        	topo.clear();
        	dfs_num.clear();
        	dfs_num.assign(V, UNVISITED);
        
		cin >> E;
		AdjList = new vector<int>[V];
		
		for (int i = 0; i < E; i++){
			cin >> x >> y;
			s = x;
			AdjList[x].push_back(y);
            		AdjList[y].push_back(x);
		}
		
		if (E){
            		//dfs(s);
            		//reverse(topo.begin(), topo.end());
            		//s = topo[0];
            		//for (unsigned int i = 0; i < topo.size(); i++) cout << topo[i] << " "; cout << endl;
            
			queue<int> q; q.push(s);
			vector<int> color(V,-1); color[s] = 0;
		
			while (!q.empty() && isBipartite){
				int index = q.front(); q.pop();
				
				for (int j = 0; j < (int)AdjList[index].size(); j++){
					int ind2 = AdjList[index][j];
		
					if (color[ind2] == -1){
						color[ind2] = 1-color[index];
						q.push(ind2);
					}
					
					else if (color[ind2] == color[index]){
						isBipartite = false;
						break;
					}
				}
			}
		}
		
		(isBipartite)? cout << "BICOLORABLE.\n":cout << "NOT BICOLORABLE.\n";
	}
	
	return 0;
}
