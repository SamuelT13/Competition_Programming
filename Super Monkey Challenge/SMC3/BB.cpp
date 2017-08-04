#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int A, B, C, test;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
			
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cout << "Case #" << t << ": ";
		cin >> A >> B >> C;
		
		cout << fixed << showpoint << setprecision(2) << (2*C)/double(A+B) << "\n";
	}
}
