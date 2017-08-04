#include <iostream>
using namespace std;

int main(){
	int people, person_cost, person_amount, budget, num_h, num_w, cost, i, j;
	
	while (cin >> people >> budget >> num_h >> num_w){
		cost = -1;
		
		for (i = 0; i < num_h; i++){
			cin >> person_cost;
			for (j = 0; j < num_w; j++){
				cin >> person_amount;
				
				if (person_amount >= people && person_cost*people <= budget)
					if (cost == -1) cost = person_cost*people;
					else if (person_cost*people < cost) cost = person_cost*people;
			}
		}
		
		if (cost == -1) cout << "stay home" << endl;
		else cout << cost << endl;
	}
	return 0;
}
