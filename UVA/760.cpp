#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
const int MAX_N = 100010; // second approach: O(n log n)

string T, P; // the input string, up to 100K characters, and second string
int n; // the length of input string
int m; //the length of second string
int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int c[MAX_N]; // for counting/radix sort
int Phi[MAX_N], LCP[MAX_N], PLCP[MAX_N];

void countingSort(int k) { // O(n)
	int i, sum, maxi = max(300, n); // up to 255 ASCII chars or length of n

	memset(c, 0, sizeof c); // clear frequency table

	for (i = 0; i < n; i++) // count the frequency of each integer rank
		c[i + k < n ? RA[i + k] : 0]++;

	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; 
		sum += t; 
	}
	
	for (i = 0; i < n; i++) // shuffle the suffix array if necessary
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
		
	for (i = 0; i < n; i++) // update the suffix array SA
		SA[i] = tempSA[i];
}

void constructSA() { // this version can go up to 100000 characters
	int i, k, r;
	
	for (i = 0; i < n; i++) RA[i] = T[i]; // initial rankings
	for (i = 0; i < n; i++) SA[i] = i; // initial SA: {0, 1, 2, ..., n-1}

	for (k = 1; k < n; k <<= 1) { // repeat sorting process log n times
		countingSort(k); // actually radix sort: sort based on the second item
		countingSort(0); // then (stable) sort based on the first item
		
		tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0

			for (i = 1; i < n; i++) // compare adjacent suffixes
				tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r

		(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;

		for (i = 0; i < n; i++) // update the rank array RA
			RA[i] = tempRA[i];

		if (RA[SA[n-1]] == n-1) break; // nice optimization trick
	} 
}

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1; // default value
	
	for (i = 1; i < n; i++) // compute Phi in O(n)
		Phi[SA[i]] = SA[i-1]; // remember which suffix is behind this suffix
	
	for (i = L = 0; i < n; i++) { // compute Permuted LCP in O(n)
		if (Phi[i] == -1){ 
			PLCP[i] = 0; 
			continue; 
		} // special case
		
		while (T[i + L] == T[Phi[i] + L]) L++; // L increased max n times
	
		PLCP[i] = L;
		L = max(L-1, 0); // L decreased max n times
		}
		
	for (i = 0; i < n; i++) // compute LCP in O(n)
		LCP[i] = PLCP[SA[i]]; // put the permuted LCP to the correct position
}

int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }

vector<ii> LCS(){                 // returns a pair (the LCS length and its index)
	int i, maxLCP = -1;
  	vector<ii> ans;
  
  	for (i = 1; i < n; i++)                         // O(n), start from i = 1
    		if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] >= maxLCP){
			if (LCP[i] > maxLCP) ans.clear();
			maxLCP = LCP[i];
			ans.push_back(ii(maxLCP, i));
		}
	
  	return ans;
}

int main() {
	int c(0);
    
    	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	while (cin >> T >> P){
		if (c++) cout << "\n";
		
		T += '$'; // add terminating character
		T += P;
		T += '#';
		n = int(T.length());
		m = int(P.length());
	
		constructSA();
		computeLCP();
		vector<ii> ans = LCS();
	    
        	if (ans.size() == 0 || ans[0].first <= 0){ cout << "No common sequence.\n"; continue;}
		
		set<string> s;
        	for (int i = 0; i < ans.size(); i++) s.insert(T.substr(SA[ans[i].second], ans[i].first));
        	for (set<string>::iterator it = s.begin(); it != s.end(); it++) cout << *it << "\n";
	}
	
	return 0;
}
