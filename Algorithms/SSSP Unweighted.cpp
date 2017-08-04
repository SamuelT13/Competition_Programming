#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int s; //source
vector<int> p;

void printPath(int index){
	if (index == s){
		cout << s;
		return;
	}
	printPath(p[index]);
	cout << " " << index;
}

int main(){
	
	vector<int> dist(V, INF); dist[s] = 0;
	queue<int> q; q.push(s); //start index
	while (!q.empty()){
		int index = q.front(); q.pop();
		
		for (int j = 0; j < (int)AdjList[index].size(); j++){
			int ind2 = AdjList[index][j];
			
			if (dist[ind2] == INF){
				dist[ind2] = dist[index] + 1;
				p[ind2] = index;
				q.push(ind2);
			}
		}
	}
	
	printPath(t); cout << "\n";
	return 0;
}
