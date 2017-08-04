#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;
char w[3] = {'C', 'A', 'T'};

bool order(string f, string s){
	if (f.length() == s.length()) return f < s;
	return f.length() < s.length();
}

void generate_ans(int N, int c, string curr){
	if (c == 2){
		ans.push_back(curr+string(N, w[c])); return;
	}
	
	for (int i = 1; i <= N; i++)
		if (N % i == 0) generate_ans(N/i, c+1, curr+string(i, w[c]));
}

int main(){
	int test, N;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> test;
	
	while (test--){
		ans.clear();
		cin >> N;
		
		generate_ans(N, 0, "");
		sort(ans.begin(), ans.end(), order);

		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << "\n";
	}
	
	return 0;
}
