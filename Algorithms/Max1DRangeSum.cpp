#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
	vector<int> nums;
	int next, sum(0), maxim(0), i;
	
	
	while (scanf("%d",&next) != EOF)
		nums.push_back(next);
		
		
	for (i = 0; i < nums.size(); i++){
		sum += nums[i];
		maxim = max(sum,maxim);
		
		if (sum < 0) sum = 0;
	}
	
	printf("%d\n",maxim);
	
	return 0;
}
