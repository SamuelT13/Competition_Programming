#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
using namespace std;

const int MAX_V = 40;
int res[MAX_V][MAX_V], max_flow, flow, s, t;
vector<int> p; //parent

void augment(int v, int minEdge){
	if (v == s)
		flow = minEdge;
		
	else if (p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		
		res[p[v]][v] -= flow;
		res[v][p[v]] += flow;
	}
}

int main(){
	int test, shirts, people, nodes, total;
	ifstream in("in.txt"); ofstream out("out.txt");
	string s1, s2, list[6] = {"XS", "S", "M", "L", "XL", "XXL"};
	in >> test;
	
    	//ios_base::sync_with_stdio(false);
    	//cin.tie(NULL);
    
	while (test--){
		in >> shirts >> people;
		
		nodes = 6+people+2;
		s = 0; t = 6+people+1;
		total = shirts/6;
		
		memset(res, 0, sizeof res);
		
		for (int i = 1; i <= people; i++){
			res[s][i] = 1;
			res[i][s] = 1;
		}
		
		for (int j = 1; j <= people; j++){
			in >> s1 >> s2;
			
			for (int i = 0; i < 6; i++)
				if (list[i] == s1 || list[i] == s2){
					res[j][i+1+people] = 1;
					res[i+1+people][j] = 1;
				}	
				
			for (int i = people+1; i < nodes-1; i++){
				res[i][t] = total;
				res[t][i] = total; 
			}
		}
        
        	//for (int i = 0; i < nodes; i++){
        	//  for (int j = 0; j < nodes; j++) cout << res[i][j]; cout << endl;
        	//}
	
		max_flow = 0;
		
		while (1){
			flow = 0;
			vector<int> dist(nodes, INT_MAX); dist[s] = 0;
			queue<int> q; q.push(s);
			p.assign(nodes, -1);
			
			while (!q.empty()){
				int index = q.front(); q.pop();
				
				if (index == t) break;
				
				for (int v = 0; v < nodes; v++)
					if (res[index][v] > 0 && dist[v] == INT_MAX){
						dist[v] = dist[index]+1;
						q.push(v);
						p[v] = index;
					}
			}
			
			augment(t, INT_MAX);
			if (flow == 0) break; //No more flow
			max_flow += flow;
		}
		(max_flow >= people)? out << "YES\n": out << "NO\n";
	}
	return 0;
}
