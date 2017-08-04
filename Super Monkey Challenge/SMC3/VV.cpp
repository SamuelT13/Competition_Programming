#include <iostream>
using namespace std;

typedef unsigned long long int ULL;

int main(){
	int test;
	ULL N, R;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	while (test--){
		cin >> N >> R;
		
		for (int i = 0; i < N; i++)
			R = (R*N)/(N-1);
		cout << R << "\n";
	}
	
	return 0;
}
