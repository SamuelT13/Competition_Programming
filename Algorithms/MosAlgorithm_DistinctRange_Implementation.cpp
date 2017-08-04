#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Mo's algorithm, offline

struct info{
	int start, end, ind, num; //ind for query order
	
	info(int s, int e, int i, int n): start(s), end(e), ind(i), num(n){};	

	bool operator <(const info& next) const{
		if (end == next.end) return num > next.num; //prioritize nums over queries
		
		return end < next.end; //for mo's algorithm
	}
};

int LSOne(int x){
	return x&(-x);
}

struct fenwick{
	vector<int> nums;
	
	fenwick(int N){
		nums.assign(N+1, 0);
	}
	
	int rsq(int b){
		int sum(0);
		
		for (; b; b -= LSOne(b)) sum += nums[b];
		return sum;
	}
	
	int rsq(int a, int b){
		return (a == 1)? rsq(b) : rsq(b) - rsq(a-1);
	}
	
	void update(int ind, int val){
		for (; ind < (int)nums.size(); ind += LSOne(ind)) nums[ind] += val;
	}
};

int main(){
	vector<int> count, res;
	vector<info> list;
	int N, Q, num, x, y;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> Q;
	count.assign(300, 0); res.assign(Q, 0);
	
	for (int i = 1; i <= N; i++){
		cin >> num;
		list.push_back(info(i, i, -1, num));
	}		
	
	for (int i = 0; i < Q; i++){
		cin >> x >> y;
		list.push_back(info(x, y, i, -1));
	}
	
	sort(list.begin(), list.end());
	
	fenwick tree(N);
    
	//left to right endpoints
	for (int i = 0; i < N+Q; i++)
		if (list[i].num > -1){ //number
			tree.update(list[i].end, 1); //change recorded occurrence pos of num
			
			if (count[list[i].num]) tree.update(count[list[i].num], -1); //delete prev pos
        
			count[list[i].num] = list[i].end;
		}
		
		else res[list[i].ind] = tree.rsq(list[i].start, list[i].end); //query
	
	for (int i = 0; i < Q; i++) cout << res[i] << "\n";

	return 0;
}
