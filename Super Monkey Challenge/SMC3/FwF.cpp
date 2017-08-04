#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <algorithm>
using namespace std;

int main(){
	int test, total, A, B;
	map<int, string, greater<int> > words;
	string s; 
	
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cout << "Case #" << t << ": ";
		cin >> total; words.clear();
		
		for (int i = 0; i < total; i++){
			cin >> A >> B;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); cin.clear();
			getline(cin, s);
			
			if (words[min(A,B)] == "") words[min(A,B)] = s;
		}
		
		cout << words.begin()->second << "\n";
	}
	
	return 0;
}
