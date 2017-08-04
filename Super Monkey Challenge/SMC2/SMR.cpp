#include <iostream>
using namespace std;

typedef unsigned long long int ULL;

int main(){
	int test, N;
	ULL total, mult, time;
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> test;
	
	while (test--){
		cin >> N;
		total = mult = 1;
		time = 0;
		
		for (int i = N; i >= 2; i--){
			mult *= i;
			total += mult;
			time += i*i*i;
		}
		
		cout << total << " " << time << "\n";
	}	
	
	return 0;
}
