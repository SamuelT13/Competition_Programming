#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	int test, d, a1, a2;
	double A, C;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
			
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cout << "Case #" << t << ": ";
		cin >> d >> a1 >> a2;
		
		A = (a1-a2)/2.0; C = -d;
		
		if (a1 - a2 <= 0){cout << "impossible\n"; continue;}
		
		cout << sqrt(-4*A*C)/(2*A) << "\n";
	}
	
	return 0;
}
