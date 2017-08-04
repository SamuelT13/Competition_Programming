#include <iostream>
#include <vector>
using namespace std;

int LSOne(int n){
	return n&(-n);
}

class fenwick{
	public:
		vector<long long int> ft;
		fenwick(int n){
			ft.assign(n+1,0);
		}
		long long int rsq(int b){
			long long int sum = 0;
			for (; b > 0; b -= LSOne(b)) 
				sum += ft[b];
			return sum;
		}
		long long int rsq(int a, int b){
			return (a == 1)? rsq(b):rsq(b)-rsq(a-1);
		}
		void adjust(int k, int v){
			for (;k < ft.size(); k += LSOne(k)) ft[k] += v;
		}
		void show(){
			for (int l = 0; l < ft.size(); l++)cout << ft[l] << " "; cout << endl;
		}
};

int main(){
	fenwick tree(100);
	int i, q, a, b;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (i = 1; i <= 100; i++)
		if (i % 2) tree.adjust(i,i);
	
	cin >> q;
	
	for (i = 0; i < q; i++){
		cin >> a >> b;
		cout << "Case " << i+1 << ": " << tree.rsq(a,b) << "\n";
	}
	
	return 0;
}
