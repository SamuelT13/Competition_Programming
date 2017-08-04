#include <iostream>
using namespace std;

int main(){
	int cost[3], test, temp, i, j, t;
	
	cin >> test;
	
	for (t = 1; t <= test; t++){
		cin >> cost[0] >> cost[1] >> cost[2];
		
		for (i = 0; i < 3; i++)
			for (j = 2; j >= i; j--)
				if (cost[i] > cost[j]){
					temp = cost[i];
					cost[i] = cost[j];
					cost[j] = temp;
				}

		cout << "Case " << t << ": " <<cost[1] << endl;
	}
}
