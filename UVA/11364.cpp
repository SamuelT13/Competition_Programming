#include <iostream>
using namespace std;

int main(){
	int test, stores, dist, min, max, i;
	
	cin >> test;
	
	while(test-- > 0){
		cin >> stores;
		min = 100;
		max = -1;
		
		for (i = 0; i < stores; i++){
			cin >> dist;
			if (dist > max) max = dist;
			if (dist < min) min = dist;
		}
		
		cout << 2*(max-min) << endl;
	}
}
