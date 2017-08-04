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
	int N, K, i, cur, x, y, test(1);
	string oper;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> N >> K){
	fenwick negat(N), zero(N);
	int *val;
	val = new int[N+1];
	for (i = 1; i <= N; i++){
		cin >> cur;
		val[i] = cur;
		if (val[i] < 0)
			negat.adjust(i,1);
		else if (!val[i])
			zero.adjust(i,1);
	}
		
	for (i = 0; i < K; i++){
		cin >> oper >> x >> y;
			
		if (oper == "P"){
			if (zero.rsq(x,y))
				cout << 0;
			else if (negat.rsq(x,y)%2)
				cout << '-';
			else cout << '+';
		}
		else{
			if ((val[x] < 0 && y >= 0) || (val[x] >= 0 && y < 0))
				negat.adjust(x,1);
			if (!val[x] && y)
				zero.adjust(x,-1);
			if (val[x] && !y)
				zero.adjust(x,1);				
			val[x] = y;
			}
		}
		cout << '\n';
	}
	
	return 0;
}
