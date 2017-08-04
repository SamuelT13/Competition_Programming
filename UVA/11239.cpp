#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <string>
#include <stack>
using namespace std;

struct info{
	int num;
	string n;
};

bool f(info n1, info n2){
	if (n1.num > n2.num) return true;
	else if (n1.num == n2.num) return (n1.n <= n2.n);
	else return false;
}

int main(){
	int i, id(1), j, k;
	stack<string> *names_st = new stack<string>[10000], temp;
	string next, title, t;
	map<string, int> proj;
	map<string, int> names;
	info *test = new info[10000];
	vector<info> v;
	
	while (getline(cin, next) && next != "0"){
		if (next == "1"){
			for (i = 0; i < id-1; i++){
				if (names_st[i].size() > 1){
					while (!names_st[i].empty()){
						t = names_st[i].top();
						names_st[i].pop();
						proj[t]--;
					}
				}
				while(!names_st[i].empty()) names_st[i].pop();	
			}
			
			j = 0;
			for (map<string, int>::iterator it = proj.begin(); it != proj.end(); it++){
				test[j].n = it->first;
				test[j].num = it->second;
				v.push_back(test[j]);
				j++;
			}		
				
			sort(v.begin(), v.end(), f);
			
			for (i = 0; i < v.size(); i++)
				cout << v[i].n << " " << v[i].num << endl;
			proj.clear();
			v.clear();
			names.clear();
			id = 1;
		}
			
		else if (isupper(next[0])){
			proj[next] = 0;
			title = next;
		}
		
		else{
			if (names[next] == 0) 
				names[next] = id++;
			
			j = 0;
			while (!names_st[names[next]-1].empty()){
				t = names_st[names[next]-1].top();
				names_st[names[next]-1].pop();
				temp.push(t);
				
				if (t == title)
					j = 1;
			}
			
			while (!temp.empty()){
				t = temp.top();
				temp.pop();
				names_st[names[next]-1].push(t);
			}
			
			if (!j){
				proj[title]++;
				names_st[names[next]-1].push(title);
			}
		}
	}

	return 0;
}
