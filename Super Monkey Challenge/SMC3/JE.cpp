#include <iostream>
using namespace std;

int main(){
	int total, orig;
	string A, B;
	bool ok;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> total;
	
	while (total--){
		ok = 1;
		
		cin >> A >> B;
		
		if (A.length() != B.length()){cout << "no\n"; continue;}
		
		orig = (A[0]-B[0]+26)%26;
		
		for (int i = 1; i < A.length(); i++)
			ok &= (A[i]-B[i]+26)%26 == orig;
		
		(ok && orig)? cout << "yes\n" : cout << "no\n";
	}
	
	return 0;
}
