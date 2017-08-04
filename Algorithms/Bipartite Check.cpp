#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	queue<int> q; q.push(s);
	vector<int> color(V,-1); color[s] = 0;
	bool isBipartite = true;
	
	while (!q.empty() && isBipartite){
		int index = q.front(); q.pop();
		
		for (int j = 0; j < (int)AdjList[index].size(); j++){
			int ind2 = AdjList[index][j];
			if (color[ind2] == -1){
				color[ind2] = 1-color[index];
				q.push(ind2);
			}
			else if (color[ind2] == color[ind]){
				isBipartite = false;
				break;
			}
		}
	}
	
	return 0;
}
