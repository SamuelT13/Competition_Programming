#include <iostream>
#include <string>
using namespace std;

int main()
{
	char n;
	int count(0);
	
	while(cin.get(n)){
		if (n == '"')
			if (++count % 2)
				cout << "``";
			else
				cout << "''";
		else
			cout << n;	
	}
	
	return 0;
}
