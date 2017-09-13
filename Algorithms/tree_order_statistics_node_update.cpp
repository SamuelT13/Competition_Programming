#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//doesn't work for multi-sets

typedef tree<int, null_type, less<int>,
			 rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
	ordered_set os;
	int total, next;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> total;
	
	while (total--){
		cin >> next;
		os.insert(next);
		cout << os.order_of_key(next) << " ";
	} cout << "\n";
	
	
	for (int i = 0; i < os.size(); i++)
		cout << *os.find_by_order(i) << " ";

	return 0;
}
