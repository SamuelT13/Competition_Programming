#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long int cut(int left, int right, vector<int> values){
	if (left+1 == right) return 0;
	
	long long int minim = 1000000000;
	
	for (int i = left+1; i <= right-1; i++)
		minim = min(cut(left,i,values)+ cut(i,right,values) + values[right]-values[left], minim);
	
	return minim;
}



int main(){
	int l, n, i, next;
	vector<int> values;
	
	values.push_back(0);
	scanf("%d%d",&l,&n);
	
	for (i = 0; i < n; i++){
		scanf("%d",&next);
		values.push_back(next);
	}
	
	values.push_back(l);
		
	cout << cut(0, n+1, values) << endl;
}
