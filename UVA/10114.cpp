#include <iostream>
using namespace std;

int main(){
	int months, rec, i, j, num, m, old;
	double down, pay, loan, price, dep;
	
	while(cin >> months >> down >> loan >> rec && months > 0){
		price = loan+down;
		num = old = 0;
		pay = loan/months;
		
		for (i = 0; i < rec; i++){
			cin >> m;
			if (i == 0) {
				cin >> dep;
				m = 1;
			}
			
			for (j = old; j < m; j++){	
				price *= (1-dep);
				if (j) loan -= pay;
				if (price > loan && !num) num = j;
			}
			
			if (i != 0) cin >> dep;
			
			old = m;
		}
		
		if (!num)
			for (j = old; j <= months; j++){
				price *= (1-dep);
				if (j) loan -= pay;
				if (price > loan){
					num = j;
					break;
				}
			}
			
		if (num == 1) cout << "1 month" << endl;
		else cout << num << " months" << endl;
	}
	
	return 0;
}
