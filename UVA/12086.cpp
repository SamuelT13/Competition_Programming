#include <iostream>
#include <vector>
using namespace std;

int LSOne(int x){
	return (x & (-x));
}

class Fenw{
	private:
 		vector<int> ft;
	public:
		Fenw(int n){
			ft.assign(n+1,0);
		}
		int rsq(int b){
			int sum(0);
			for (; b > 0; b -= LSOne(b)) 
				sum += ft[b];
				return sum;
		}
		int rsq(int a, int b){
			return rsq(b) - (a == 1 ? 0:rsq(a-1));
		}
		void adjust(int k, int v){
			for (; k < ft.size(); k += LSOne(k)) ft[k] += v;
		}
};


int main(){
	int N, i, cur, x, y, test(1);
	string oper;
	
	while (cin>> N && N){
		if (test != 1)
			cout << endl;
		cout << "Case " << test++ << ":\n";
		Fenw ohms(N);
		int val[N+1];
		
		for (i = 1; i <= N; i++){
			cin >> cur;
			val[i] = cur;
			ohms.adjust(i, val[i]);
		}
		
		while (cin >> oper && (oper != "END")){
			cin >> x >> y;
			
			if (oper == "M"){
				cout << ohms.rsq(x,y) << endl;
			}
			else{
				ohms.adjust(x, -val[x]);
				val[x] = y;
				ohms.adjust(x, val[x]);
			}
		}
	}
	
	return 0;
}
