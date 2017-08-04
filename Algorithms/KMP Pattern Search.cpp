#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_N 100010

string T, P; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess() { // call this before calling kmpSearch()
	int i = 0, j = -1; b[0] = -1; // starting values

	while (i < m) { // pre-process the pattern string P
		while (j >= 0 && P[i] != P[j]) j = b[j]; // different, reset j using b
		
		i++; j++; // if same, advance both pointers
		b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
	}
} // in the example of P = "SEVENTY SEVEN" above

int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
	int i = 0, j = 0; // starting values

	while (i < n) { // search through string T
		while (j >= 0 && T[i] != P[j]) j = b[j]; // different, reset j using b

		i++; j++; // if same, advance both pointers

		if (j == m) { // a match found when j == m
			return i-j;
			j = b[j]; // prepare j for the next possible match
		} 
	}
}

int main(){
	int test;
	string next, rev;
	
	cin >> test;
	
	while (test--){
		cin >> next;
		rev = next;
		reverse(rev.begin(), rev.end());
		
		T = next.length();
		P = rev.length();
		
		cout << next << " " << rev << "\n";	 	 
	}
	
	return 0;
}
