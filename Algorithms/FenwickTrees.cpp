#include <iostream>
#include <vector>
using namespace std;

int LSOne(int a){
	return a&(-a);
}

class fenwick{
	private:
		vector<int> nums;
	public:
		fenwick(int n){
			nums.assign(n+1,0);
		}
		int rsq(int b){
			int sum = 0;
			for (; b; b -= LSOne(b)) 
				sum += nums[b];
				return sum; 
		}
		int rsq(int a, int b){
			return a == 1? rsq(b):rsq(b)-rsq(a-1);
		}
		int adjust(int k, int v){
			for (; k < nums.size(); k += LSOne(k))
				nums[k] += v;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	return 0;
}

