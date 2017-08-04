#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

typedef long long int LL;

vector<LL> memo;

void fill_memo(int N){
	if (N <= 1) return;
	
	if (N % 2){
		memo[N/2] += 2;
		fill_memo(N/2);
		fill_memo(N/2);
	}
	else{
		memo[N/2]++; memo[N/2-1]++;
		fill_memo(N/2);
		fill_memo(N/2-1);
	}
}


int main(){
	LL num, total, ind;
	int test;
	ifstream in("C-small-2-attempt0.in");
	ofstream out("out.txt");

	ios_base::sync_with_stdio(false);
    in.tie(NULL);	
	
	in >> test;
	
	for (int t = 1; t <= test; t++){
		out << "Case #" << t << ": ";
		in >> num >> total;
		
		memo.clear(); memo.assign(num+1, 0); memo[num]++;
		
		fill_memo(num);
				
		//for (int i = 0; i <= num; i++)
		//	cout << i << " " << memo[i] << endl;
		
		ind = num;
		for (int i = 0; i < total-1; i++){
			while (!memo[ind]) ind--;
			memo[ind]--;
		}
		
		while (!memo[ind]) ind--;
		if (ind == 0) out << "0 0\n"; //shouldn't happen
		else if (ind % 2) out << ind/2 << " " << ind/2 << "\n";
		else out << ind/2 << " " << ind/2-1 << "\n";
	}
		
	return 0;
}
