#include <iostream>
using namespace std;

typedef long long int LL;

int main(){
	bool notok;
	LL num, p;
	int c(1);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	while (cin >> num >> p && (num||p)){
		notok = 0;
		
		while (num){
			notok |= (num%p > 1);
			num /= p;
		}
		
		cout << "Case #" << c++ << ": ";
		(notok)? cout << "no\n" : cout << "yes\n";
	}
	
	return 0;
}
