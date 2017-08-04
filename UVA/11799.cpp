#include <iostream>
using namespace std;

int main(){
	int test, i, j, max, speed, n;
	
	cin >> test;
	
	for (i = 1; i <= test; i++){
		max = 0;
		cin >> n;
		
		for (j = 0; j < n; j++){
			cin >> speed;
			if (speed > max) max = speed;
		}
		
		cout << "Case " << i << ": " <<  max << endl;
	}
	
	return  0;
}
