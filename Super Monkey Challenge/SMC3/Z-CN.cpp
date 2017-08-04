#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int LL;

int main(){
	LL mult, count, next;
	int test;
	string num;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;	
	while (test--){
		cin >> next;
		next--;
	
		count = 0, mult = 1;
		
		while (mult <= next){
			next -= mult;
			count++;
			mult *= 81;
		}
		
		num = "";
		
		while (next){
			num += (next%9)+'1';
			next /= 9;
		}
		
		while (num.length() < 2*count) num += '1';
		num = num.substr(0, num.length()/2) + '0' + num.substr(num.length()/2, num.length());
		reverse(num.begin(), num.end());
		
		cout << num << "\n";
	}
	
	return 0;
}
