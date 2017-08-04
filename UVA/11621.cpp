#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int two, three;
	unsigned long long int k, m;
	vector<unsigned long long int> n;
	
	while (cin >> m && m){
		n.clear();
		
		for (two = 0; two < 32; two++)
			for (three = 0; three < 32; three++){
				n.push_back(pow(2,two)*pow(3,three));
			}
		
		sort(n.begin(), n.end());
		
		for (k = 0; k < n.size(); k++)
			if (n[k] >= m){
				cout << n[k] << endl;
				break;
			}			
	}
	
	return 0;
}
