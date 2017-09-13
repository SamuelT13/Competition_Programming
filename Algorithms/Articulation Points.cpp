#include <iostream>
#include <vector>
using namespace std;

vector<int> low, num, parent;
vector<vector<int> > AdjList;
vector<bool> art;
int count, rootch, root;

void artPoints(int ind){
	low[ind]= num[ind] = count++;
	
	for (int i = 0; i < AdjList[ind].size(); i++){
		int ind2 = AdjList[ind][i];
		
		if (num[ind2] == -1){
			parent[ind2] = ind;
			if (ind == root) rootch++;
			
			artPoints(ind2);

			if (low[ind2] >= num[ind] && ind != root) art[ind] = 1;
			if (low[ind2] > num[ind]) ; //bridge
		
			low[ind] = min(low[ind], low[ind2]);
		}
		else if (ind2 != parent[ind]) low[ind] = min(low[ind], num[ind2]);
	}
}

int main(){
	int V, E, x, y;


	count = 0; num.assign(V, -1); low.assign(V, 0); parent.assign(V, -1); art.assign(V, 0);
	
	for (int i = 0; i < V; i++)
		if (num[i] == -1){
			root = i, rootch = 0;
			artPoints(i);
			art[i] = (rootch > 1);
		}
	
	for (int i = 0; i < V; i++)
		if (art[i]) cout << "Articulation point: " << i << endl;
		
	return 0;
}
