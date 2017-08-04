#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	int test, chars, price, l, sum, i, j;
	string line;
	map<char,int> money;
	char letter;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cin >> test;
	
	while (test-- > 0){
		cin >> chars;
		sum = 0;
		
		for (i = 0; i < chars; i++){
			cin >> letter >> price;
			money[letter] = price;
		}
		
		cin >> l;
		getline(cin, line);
		for (i = 0; i < l; i++){
			getline(cin, line);
			for (j = 0; j < line.length(); j++)
				sum += money[line[j]];
		}
		
		cout << double(sum)/100 << "$" << endl;
		money.clear();
	}
	
	return 0;
}
