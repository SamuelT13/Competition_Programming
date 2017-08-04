#include <iostream>
#include <vector>	
#include <set>
using namespace std;

int main(){
	int test, total, next, c, count;
	vector<set<int> > chambers;
	bool ok;
    	vector<bool> press;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cin >> total;
        	press.clear(); press.assign(total, 1);
		chambers.clear(); chambers.assign(total, set<int>());
		
		for (int i = 0; i < total; i++){
			cin >> c;
			
			for (int j = 0; j < c; j++){
				cin >> next;
				chambers[i].insert(next-1);
			}
		}
		
		for (int i = 0; i < total; i++){ //repeat ~(total) times
            		count = 0;
            
			for (int j = 0; j < total; j++){
				if (!press[j]) continue; //already un-pressed
				ok = false;
				for (int k = 0; k < total; k++)
					if (chambers[k].count(j)){ //found a button that already opens this door -> can press jth button (for now)
						ok = true;
						break;
					}
                
				if (!ok){ 
                    			chambers[j].clear(); //un-press jth button
                    			press[j] = 0;
                    			count++;
                		}
			}
            
            		if (!count) break; //no new buttons were un-pressed
        	}
		
		cout << "Case #" << t << ":";
		for (int i = 0; i < total; i++)
			if (!press[i]) cout << " 0";
			else cout << " 1";
		cout << "\n";
	}
	
	return 0;
}
