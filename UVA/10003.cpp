#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*long long int cut(int left, int right, vector<int> values){
	if (left+1 == right) return 0;
	
	long long int minim;
	
	for (int i = left+1; i <= right-1; i++)
		if (i == left+1)
			minim = cut(left,i,values)+ cut(i,right,values) + values[right]-values[left];
		else
			minim = min(cut(left,i,values)+ cut(i,right,values) + values[right]-values[left], minim);
	
	return minim;
}*/



int main(){
	int l, n, i, j, k, next;
	vector<int> values;
	int memo[55][55];
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> l && l){
		cin >> n;
		
		values.clear();
		
		values.push_back(0);
		for (i = 0; i < n; i++){
			cin >> next;
			values.push_back(next);
		}
		
		values.push_back(l);
		
		for (i = 1; i <= n+1; i++)
			for (j = i-1; j >= 0; j--){
				if (i == j+1)
					memo[j][i] = 0;
				else{
					for (k = j+1; k <= i-1; k++)
						if (memo[j][k]+memo[k][i] < memo[j][i] || k == j+1)
							memo[j][i] = memo[j][k]+memo[k][i];
				memo[j][i] += values[i]-values[j];
			}
		}
		
		/*for (i = 0; i <= n+1; i++){
			for (j = 0; j <= n+1; j++)
				cout << memo[i][j] << " "; cout << endl;
			}*/
			
		cout << "The minimum cutting is " << memo[0][n+1] << ".\n";
	}
	
	return 0;
}
