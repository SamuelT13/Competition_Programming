#include <iostream>
using namespace std;

//a_init + 2*a_init*(a_sec/a_init) + 2*a_init*(a_sec/a_init)^2 + ....
//a_init + 2*a_sec/(1 - (a_sec/a_init)) 
//(a_init*a_init + a_init*a_sec)/(a_init-a_sec)

typedef long long int LL;

LL gcd(LL a, LL b){
	LL temp;
	
	while (b){
		temp = a%b;
		a = b;
		b = temp;
	}
	
	return a;
}

int main(){
	LL test, a_init, a_sec, num, denom;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cin >> a_init >> a_sec;
		
		num = a_init*a_init + a_init*a_sec;
		denom = a_init - a_sec;
		
		cout << "Case #" << t << ": " << num/gcd(num, denom) << "/" << denom/gcd(num, denom) << "\n";
	}
	return 0;
}

