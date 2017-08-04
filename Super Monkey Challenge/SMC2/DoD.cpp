#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int total;
	map<vector<char>,int> count;
	unsigned int i;
	vector<char> next;
	string s;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> total;
	
	while (total--){
		cin >> s;
		next.clear();
		for (i = 0; i < s.length(); i++)
			next.push_back(s[i]);
		sort(next.begin(), next.end());
		
		if (count[next])
			cout << count[next]++ << "\n";
		else
			cout << count[next]++ << "\n"; 
		
		//for (i = 0; i < next.size(); i++)
		//	cout << next[i];
		//cout << "\n";
	}
	
	return 0;
}
