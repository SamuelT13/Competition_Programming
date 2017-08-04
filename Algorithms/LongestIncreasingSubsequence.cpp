#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, i, j, maxim, next;
	vector<int> LIS, A;
	
	scanf("%d",&n);
	
	for (i = 0; i < n; i++){
		scanf("%d", &next);
		A.push_back(next);
		LIS.push_back(0);
		maxim = 0;
		
		for (j = i-1; j >= 0; j--)
			if (A[j] < A[i] && LIS[j] > maxim)
				maxim = LIS[j];
		
		LIS[i] = maxim+1;
	}
	
	maxim = 0;
	for (i = 0; i < n; i++){
		if (LIS[i] > maxim) maxim = LIS[i];
		cout << LIS[i] << " ";} cout << endl;
		
	printf("%d\n",maxim);
	
	return 0;
}
