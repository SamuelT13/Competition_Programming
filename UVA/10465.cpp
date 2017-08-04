#include <iostream>
#include <algorithm>
using namespace std;

struct info{
	int left, beer;
};

int main(){
	int m,n,t, time;
	info memo[10001];
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> m >> n >> t){
		int min = m>n? n:m;
		int max = m>n? m:n;
		
		for (time = 0; time <= t; time++){
			if (time-min < 0){
				memo[time].beer = 0;
				memo[time].left = time;
			}
			else if (time-max < 0){
				memo[time] = memo[time-min];
				memo[time].beer++;
			}
			else{
				memo[time] = memo[time-max].left < memo[time-min].left? memo[time-max]:memo[time-min];
				memo[time].beer++;
			}
		}
		
		cout << memo[t].beer;
		if (memo[t].left) cout << " " << memo[t].left << "\n";
		else cout << "\n";	
	}
	 
	
	return 0;
}


