#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int test, total, limit, link, n, sum;
	deque<int> people;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
			
	cin >> test;
	
	for (int t = 1; t <= test; t++){
		cout << "Case #" << t << ": ";
		people.clear();
		
		cin >> total >> limit >> link;
		
		for (int i = 0; i < total; i++){
			cin >> n; people.push_back(n);
		} sort(people.begin(), people.end());
		
		if (people.back() + link > limit){cout << "impossible\n"; continue;}
		
		for (int i = 0; i < total; i++){
			sum = link + people.back(); people.pop_back();
			
			if (people.size() && people.front() + sum <= limit) people.pop_front();
		
			if (!people.size()){cout << i*2 + 1 << "\n"; break;}
		}
	}
	
	return 0;
}
