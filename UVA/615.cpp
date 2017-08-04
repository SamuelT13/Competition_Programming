#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int,vector<int> > AdjList;
map<int,int> dfs_num;

void dfs(int index, bool& ok){
	dfs_num[index] = 1;
	
	for (int j = 0; j < (int)AdjList[index].size(); j++){
		int ind2 = AdjList[index][j];
		//cout << index << " " << ind2 << endl;
		if (dfs_num[ind2] == 1)
			ok = false;
		else
			dfs(ind2, ok);
	}
}

int main(){
	map<int,int> f, s;
	int first, second, i(1), root;
	bool ok;
	map<int,int>:: iterator it, jt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> first >> second && (first != -1 || second != -1)){
		if (!first && !second){
			ok = true;
			root = -1;
			for (it = f.begin(); it != f.end(); it++){
				for (jt = s.begin(); jt != s.end(); jt++)
					if (it->first == jt->first)
						break;
		
				if (jt == s.end()){
					root = it->first;
					break;
				}
			}
			
			if (root == -1 && !f.empty()) ok = false;
			
			if (ok){
				//cout << root << endl;
				dfs(root,ok);
				if (ok)
					for (it = dfs_num.begin(); it != dfs_num.end(); it++)
						if (it->second == -1){ok = false; break;}
			}
			
			if (ok) cout << "Case " << i++ << " is a tree.\n";
			else cout << "Case " << i++ << " is not a tree.\n";
			AdjList.clear(); f.clear(); s.clear(); dfs_num.clear();
		}
		else{
			AdjList[first].push_back(second);
			f[first]++;
			s[second]++; 
			dfs_num[first] = dfs_num[second] = -1;
		}		
	}
	return 0;
}

