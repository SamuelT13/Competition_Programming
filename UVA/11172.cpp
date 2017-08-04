#include <iostream>
using namespace std;

int main(){
	int a, b, test;
	
	cin >> test;
	
	while(test-- > 0){
		cin >> a >> b;
		
		if (a < b)	cout << "<" << endl;
		else if (a > b) cout << ">" << endl;
		else cout << "=" << endl;
	}
	
	return 0;
}
