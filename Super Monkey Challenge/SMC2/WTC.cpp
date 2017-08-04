#include <iostream>
using namespace std;

int main(){
	double num;
	int count, test;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	for (int i = 0; i < test; i++){
		count = 0;
		cin >> num;
		
		while (num >= 2.0){
			count++;
			num /= 2;
        	}
		
		cout << "Case #" << i+1 << ": " << count << "\n";
	}
	
	return 0;
}

