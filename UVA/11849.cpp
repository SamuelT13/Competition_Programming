#include <iostream>
#include <set>
using namespace std;

int main(){
	set<int> cds;
	int n, m, next, i, num;
	
	while (cin >> n >> m && (n || m)){
		num = 0;
		for (i = 0; i < n; i++){
			cin >> next;
			cds.insert(next);
		}
		for (i = 0; i < m; i++){
			cin >> next;
			if (cds.find(next) != cds.end())
				num++;
		}
		cds.clear();
		cout << num << endl;
	}
}
