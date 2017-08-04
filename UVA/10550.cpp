#include <iostream>
using namespace std;

int main()
{
	int deg(360), start, one, two, three, s;
	
	while(cin >> start >> one >> two >> three && (start+one+two+three))
	{
		cout << 3*deg + 9*((40+ start - one)%40 + (40 + two - one)%40 + (40 + two - three)%40) << endl;
	}
	
	return 0;
}
