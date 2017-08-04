#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, int> visited;
map<string, vector<string> > east, west;
	
bool found;

void lookup(string pos, string target, char dir){
	visited[pos] = 1;
	
	if (dir == 'w')
		for (int i = 0; i < west[pos].size(); i++){
			if (west[pos][i] == target) found = true;
 			else if (!visited[west[pos][i]]) lookup(west[pos][i], target, dir);
 		}
 		
 	else 
		for (int i = 0; i < east[pos].size(); i++){
			if (east[pos][i] == target) found = true;
			else if (!visited[east[pos][i]]) lookup(east[pos][i], target, dir);
 		}
}

int main(){
	string next, p1, p2;
	bool e, w;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> next;
	
	while (cin >> next && next != "Consultas:"){
		p1 = next;
		cin >> p2;
		
		east[p2].push_back(p1);
		west[p1].push_back(p2);
	}
	
	while (cin >> next && next != "Fin."){
		p1 = next;
		cin >> p2;
		
		visited.clear(); found = false; lookup(p1, p2, 'e'); lookup(p2, p1, 'w'); e = found;
		visited.clear(); found = false; lookup(p1, p2, 'w'); lookup(p2, p1, 'e'); w = found;
		
		if ((!e && !w)) cout << "La posicion relativa de " << p1 << " y " << p2 << " es desconocida.\n";
		else if (e) cout << p1 << " esta al oeste de " << p2 << ".\n";
		else if (w) cout << p1 << " esta al este de " << p2 << ".\n";
	}
    
	return 0;
}
