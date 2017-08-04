#include <iostream>
using namespace std;

int totient(int num){
	double ans(num);
	
	for (int p = 2; p*p <= num; p++)
		if (num % p == 0){
			while (num % p == 0)
				num /= p;
			ans *= 1.0 - (1.0/p);
		}
	
	if (num > 1)
		ans *= 1.0 - (1.0/num);
	
	return ans;
}

int main(){
	return 0;
}
