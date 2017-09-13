#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

vector<vector<int> > cap, flow, graph;
int s, t, V, N, max_flow, check;
vector<int> curr_cap, p; //parent
const int INF = 1e9;

int bfs(){
	p.clear(); p.assign(N+1, -1);
	curr_cap.clear(); curr_cap.assign(N+1, 0);
    
	queue<int> q;
	q.push(N);
	
	p[N] = -2;
	curr_cap[N] = INF;
	
	while (!q.empty()){
		int curr = q.front(); q.pop();
        
		for (int i = 0; i < graph[curr].size(); i++){
			int to = graph[curr][i];

			if (p[to] == -1)
				if (cap[curr][to] - flow[curr][to] > 0){
					p[to] = curr;
					curr_cap[to] = min(curr_cap[curr],
										cap[curr][to] - flow[curr][to]);
                                       
					if (to == t) return curr_cap[t];
					q.push(to);
				}
		}
	}
	
	return 0;
}

int edmondsKarp(){
	int c_flow; max_flow = 0;
    
	while (1){
		c_flow = bfs();
        
		if (!c_flow) break;
        
		max_flow += c_flow;
		
		int curr = t;
        
		while (curr != s){
			int prev = p[curr];
			flow[prev][curr] += c_flow;
			flow[curr][prev] -= c_flow;
			curr = prev;
		}
	}
	
	return max_flow;
}

int main(){
	int games, played, A, B, co, champ, m_score, o, teams;
	map<ii, int> order;
	vector<int> left, score;
	bool ok;
	char c;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> V >> games >> played && V||games||played){
		s = 0; V--, t = 1 + (V*(V-1))/2 + V, teams = (V*(V-1))/2, N = t+1;
		ok = 1, co = check = 0, champ = games*V;
		
		order.clear();
		left.clear(); left.assign(V*(V-1)/2, games);
		score.clear(); score.assign(V+1, 0);
		cap.clear(); cap.assign(N+1, vector<int>(N+1, 0));
		flow.clear(); flow.assign(N+1, vector<int>(N+1, 0));
		graph.clear(); graph.assign(N+1, vector<int>());

		for (int i = 1; i <= V; i++)
			for (int j = i+1; j <= V; j++)
				order[ii(i, j)] = co++;
		
		for (int i = 0; i < played; i++){
			cin >> A >> c >> B;
			
			if (c == '=') score[A]++, score[B]++;
			else if (c == '>') score[A] += 2;
			else score[B] += 2;
			
			if (A && B) left[order[ii(min(A, B), max(A, B))]]--;
			else champ--;
		}
			
		m_score = score[0] + champ*2;
		
		cap[N][0] = INF, graph[N].push_back(0), graph[0].push_back(N);
		
		for (int i = 1; i <= V; i++)
			for (int j = i+1; j <= V; j++){
				o = order[ii(i, j)]+1;
				
				cap[0][o] = 2*left[o-1], graph[0].push_back(o), 
				graph[o].push_back(0); //source to pairing
		
				cap[o][teams+i] = 2*left[o-1], graph[o].push_back(teams+i), 
				graph[teams+i].push_back(o); //pairing to 1st team
				
				cap[o][teams+j] = 2*left[o-1], graph[o].push_back(teams+j), 
				graph[teams+j].push_back(o); //pairing to 2nd team
				check += 2*left[o-1]; //keeping track of flow
			}
		
		for (int i = 1; i <= V; i++)
			if (m_score-1-score[i] >= 0)
				cap[teams+i][t] = m_score-1-score[i], graph[teams+i].push_back(t), 
				graph[t].push_back(teams+i); //team to sink
	
			else{ ok = 0; break;}
        
		max_flow = edmondsKarp();
		
		(m_score > 0 && ok && max_flow == check)? cout << "Y\n" : cout << "N\n";
	}
	
	return 0;
}
