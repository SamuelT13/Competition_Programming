#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct door{
	int need, bonus;
};

bool order(door d1, door d2){
	return d1.need < d2.need;
}

int main(){
	int test, total, easy, super, current, trade;
	vector<door> list;
	door temp;
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> test;
	
	while (test--){
		cin >> total;
		current = trade = 0; list.clear();
		
		while (total--){
			cin >> easy >> super;
			if (super < easy) super = easy;
			
			temp.need = easy; temp.bonus = 1;
			list.push_back(temp);	
			
			temp.need = super; temp.bonus = 2;
			list.push_back(temp);		
		}
		
		sort(list.begin(), list.end(), order);
		
		for (int i = 0; i < (int)list.size(); i++){
			if (current < list[i].need){
				trade += list[i].need-current;
				current = list[i].need;
			}
			
			current += list[i].bonus;
		}
		//cout << current << "\n";
		cout << trade << "\n";
	}
	
	return 0;
}
