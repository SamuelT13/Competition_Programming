#include <iostream>
#include <string>
using namespace std;

int main(){
	int total, ind, rep;
	string s;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> total;
	
	for (int t = 0; t < total; t++){
		if (t) cout << "\n";
		
		cin >> s;
		rep = s.length()*2 - 1;
		
		
		for (int i = 0; i <= rep/2; i++){
			ind = 0;
			for (int j = 0; j < s.length(); j++){
				if (j + i >= s.length()-1) cout << s[ind++];
				else cout << " ";
			}
			cout << "\n";
		}
		
		for (int i = rep/2 + 1; i < rep; i++){
			ind = i-rep/2; 
			
			for (int j = 0; j < s.length(); j++)
				if (ind >= s.length())  cout << " ";
				else cout << s[ind++];

			cout << "\n";
		}
	}
	
	return 0;
}
