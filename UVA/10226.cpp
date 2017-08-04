#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main(){
	map<string, int> trees;
	int test, num, i, j;
	string s;
	
	cin >> test;
	cin.ignore(1000,'\n');
	getline(cin, s);
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);
		
	for (i = 0; i < test; i++){
		num = 0;
		
		if (i) cout << endl;
		
		while(getline(cin, s) && s != ""){
			trees[s]++;
			num++;
		}
		
		for (map<string, int>::iterator it = trees.begin(); it != trees.end(); it++)
			cout << it->first << " " << double(it->second)/num*100 << endl;
	
		trees.clear();
	}
	
	return 0;
}
