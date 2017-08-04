#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <limits>
using namespace std;

int main(){
	string next, sub;
	int test;
	map<char, int> word1, word2;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	
	for (int i = 0; i < test; i++){
		word1.clear(); word2.clear();
		
		getline(cin, next);
		stringstream str_s(next);
		while (str_s >> sub) for (int k = 0; k < (int)sub.size(); k++) word1[sub[k]]++;
		
		getline(cin, next);
		stringstream str_c(next);
		while (str_c >> sub) for (int k = 0; k < (int)sub.size(); k++) word2[sub[k]]++;			
		
		(word1 == word2)? cout << "yes\n" : cout << "no\n";	
	}
	
	return 0;
}
