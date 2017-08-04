#include <iostream>
#include <vector>
using namespace std;

//Sparse Tree - static RMQ
vector<int> arr;
vector<vector<int> > st;

void st_init(int N){
	for (int i = 0; i < N; i++) st[i][0] = arr[i];
	
	for (int j = 1; (1 << j) <= N; j++)
		for (int i = 0; i + (1 << j) < N; i++)
			st[i][j] = min( st[i][j-1], 
							st[i + (1 << (j-1))][j-1]);	
}

int st_query(int s, int e){
	int k = 31 - __builtin_clz(e-s);
	return min(st[k][s], st[k][e-(1<<k)]);	
}

int main(){
	int N;
    
    cin >> N;
	
	arr.assign(N, 0); st.assign(N, vector<int>());
	for (int i = 0; i < N; i++){
		cin >> arr[i];
		st[i].assign(N, 0);
	}
	
	st_init(N);
	
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			cout << i << ", " << j << ": " << st_query(i, j) << endl;
	
	return 0;
}
