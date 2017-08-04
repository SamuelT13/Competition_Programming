#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x, y, test;
	
	cin >> test;
	
	while(test-- > 0){
		cin >> x >> y;
		cout << (int)(ceil((x-2)/3.0)*ceil((y-2)/3.0)) << endl;
	}
	
	return 0;
}
