#include <iostream>
using namespace std;

int main(){
	int test, div_x, div_y, x, y, i;
	
	while(cin >> test && test != 0){
		cin >> div_x >> div_y;
		
		for (i = 0; i < test; i++){
			cin >> x >> y;
			
			if (x == div_x || y == div_y)	cout << "divisa" << endl;
			else if (x > div_x && y > div_y) cout << "NE" << endl;
			else if (x > div_x && y < div_y) cout << "SE" << endl;
			else if (x < div_x && y > div_y) cout << "NO" << endl;
			else cout << "SO" << endl;	
		}
	}
	return 0;
}


