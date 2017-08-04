#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

typedef long long int LL;
typedef pair<LL, LL> ii;

int main(){
	vector<int> p;
	set<ii> h;
	LL N(1e2);
	
	p.push_back(2);
	h.insert(ii(4, 2));
	
	for (LL i = 3; i < N; i++){
		set<ii>::iterator it = h.lower_bound(ii(i, 0));
		
		if (it->first > i){
			p.push_back(i);
			if (i*i < 1e7) h.insert(ii(i*i, i));
		}
		else{
			do{
				h.insert(ii(it->first+it->second, it->second));
				h.erase(it);
				it = h.lower_bound(ii(i, 0));
			} while (it->first == i);
		}
	}
	
	for (int i = 0; i < p.size(); i++)
		cout << p[i] << " "; cout << endl;
}
