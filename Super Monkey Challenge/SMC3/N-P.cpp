#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int test;
	string next, temp, rev;
	bool ok;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		ok = false;
		cin >> next;
		cout << "Case #" << t << ": ";
		
		rev = next;
		reverse(rev.begin(), rev.end());
		
		if (rev == next){
			cout << "palindrome\n";
			continue;
		}
		
		for (int i = 0; i < next.length(); i++){
			temp = next.substr(0, i) + next.substr(i+1, next.length());
			
			rev = temp;
			reverse(rev.begin(), rev.end());
			
			if (rev == temp){
				cout << "near-palindrome\n";
				ok = true;
				break;
			}
		}
		
		if (ok) continue;
		cout << "neither\n";
	}
	
	return 0;
}
