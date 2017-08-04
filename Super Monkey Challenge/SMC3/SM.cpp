#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int test, total, avai, c, ind;
	vector<int> req, col;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		c = ind = 0;
		cout << "Case #" << t << ": ";
		
		req.clear(); col.clear();

		cin >> total;
		req.assign(total, 0);
		for (int i = 0; i < total; i++) cin >> req[i];
		
		cin >> avai;
		col.assign(avai, 0);
		for (int i = 0; i < avai; i++) cin >> col[i];
		
		sort(req.begin(), req.end()); sort(col.begin(), col.end());
		
		for (int i = 0; i < avai; i++)
            if (ind >= total) break;
			else if (req[ind] <= col[i]) c++, ind++;
		
		(c == total)? cout << "yes\n" : cout << "no\n";
	}
	return 0;
}
