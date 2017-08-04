#include <iostream>
using namespace std;

int main(){
	int n, *comp, *part, i;
	
	while (cin >> n && n != -1){
		comp = new int[n+1];
		part = new int[n+1];
		
		comp[0] = part[1] = 1;
		comp[1] = part[0] = 0;
		
		for (i = 2; i <= n; i++){
			comp[i] = comp[i-2]+2*part[i-1];
			part[i] = comp[i-1]+part[i-2];
		}
		
		cout << comp[n] << endl;
	}
	
	return 0;
}
