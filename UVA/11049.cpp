#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> *AdjList;
int s; //source

struct info{
	int ind;
	char dir;
};

info *p;

void printPath(int index){
	if (index == s){
		//cout << p[s].dir;
		return;
	}
	printPath(p[index].ind);
	cout << p[index].dir;
}

void fill_Adj(){
	for (int i = 0; i < 36; i++){
		if (i/6) AdjList[i].push_back(i-6);
		if (i/6 != 5) AdjList[i].push_back(i+6);
		if (i%6) AdjList[i].push_back(i-1);
		if (i%6 != 5) AdjList[i].push_back(i+1);
	}
}

bool valid(int x, int y){
	return !(x < 0 || x >= 6 || y < 0 || y >= 6);
}

int main(){
	int s_x, s_y, e_x, e_y, pos_s, pos_e, b_x, b_y, c_x, c_y, pos_b, pos_c;
	p = new info[36];
    
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	
	while (cin >> s_y >> s_x && (s_x || s_y)){		
		AdjList = new vector<int>[36];
		fill_Adj();
		
		/*for (int i = 0; i < 36; i++){
			cout << "Node " << i << ":\n";
			for (int j = 0; j < (int)AdjList[i].size(); j++) cout << AdjList[i][j] << " "; cout << endl;
		}*/
		
		cin >> e_y >> e_x;
		s_x--; s_y--; e_x--; e_y--;
		pos_s = s_x+s_y*6; pos_e = e_x+e_y*6;
		s = pos_s;
		
		for (int i = 0; i < 3; i++){
			cin >> b_y >> b_x >> c_y >> c_x;
			
			if (b_y == c_y)
				for (int j = 0; j < (c_x-b_x); j++){
					pos_b = b_x+j + (b_y-1)*6;
					pos_c = b_x+j + c_y*6; 
					//cout << pos_b << " " << pos_c << endl;
					
					if (pos_b < 0 || pos_b > 35 || pos_c < 0 || pos_c > 35) continue;
				
					if (find(AdjList[pos_b].begin(), AdjList[pos_b].end(), pos_c) != AdjList[pos_b].end()){
						AdjList[pos_b].erase(find(AdjList[pos_b].begin(), AdjList[pos_b].end(), pos_c));
						AdjList[pos_c].erase(find(AdjList[pos_c].begin(), AdjList[pos_c].end(), pos_b));
					}
				}
				
			else
				for (int j = 0; j < (c_y-b_y); j++){
					pos_b = b_x-1 + (b_y+j)*6;
					pos_c = c_x + (b_y+j)*6;
					//cout << pos_b << " " << pos_c << endl;
					
					if (pos_b < 0 || pos_b > 35 || pos_c < 0 || pos_c > 35) continue;
					
					if (find(AdjList[pos_b].begin(), AdjList[pos_b].end(), pos_c) != AdjList[pos_b].end()){
						AdjList[pos_b].erase(find(AdjList[pos_b].begin(), AdjList[pos_b].end(), pos_c));
						AdjList[pos_c].erase(find(AdjList[pos_c].begin(), AdjList[pos_c].end(), pos_b));
					}
				}	
		}
		
		/*for (int i = 0; i < 36; i++){
			cout << "Node " << i << ":\n";
			for (int j = 0; j < (int)AdjList[i].size(); j++) cout << AdjList[i][j] << " "; cout << endl;
		} return 0;*/
		
		vector<int> dist(36, -1); dist[pos_s] = 0;
		queue<int> q; q.push(pos_s); //start index
		
		while (!q.empty()){
			int index = q.front(); q.pop();
		
			for (int j = 0; j < (int)AdjList[index].size(); j++){
				int ind2 = AdjList[index][j];
			
				if (dist[ind2] == -1){
					dist[ind2] = dist[index] + 1;
					if (ind2+1 == index){
						p[ind2].ind = index;
						p[ind2].dir = 'N';
					}
					else if (ind2-1 == index){
						p[ind2].ind = index;
						p[ind2].dir = 'S';
					}
					else if (ind2+6 == index){
						p[ind2].ind = index;
						p[ind2].dir = 'W';
					}
					else{		
						p[ind2].ind = index;
						p[ind2].dir = 'E';
					}
					
					q.push(ind2);
				}
			}
		}
		p[s].dir = 'A';
		printPath(pos_e); cout << "\n";	
	}
	return 0;
}
