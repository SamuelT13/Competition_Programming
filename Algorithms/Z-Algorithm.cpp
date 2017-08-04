#include <iostream>
#include <vector>
using namespace std;

/* Z - Algorithm */

//"One application of the Z Algorithm is for the standard string matching problem of finding matches for a pattern T of length m in a string S of length n. 
//We can do this in O(n+m) time by using the Z Algorithm on the string T * S (that is, concatenating T, *, and S) where * is a character that matches nothing. 
//The indices i with Z[i] = m correspond to matches of T in S."

string S;
vector<int> Z; //"Z[i] is the length of the longest substring starting from S[i] which is also a prefix of S"

int main(){
	int n, L, R, k;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> S;
	n = S.length(), L = R = 0;
	
	Z.assign(n, 0);
	
	for (int i = 1; i < n; i++)
		if (i > R){
			L = R = i;
			while (R < n && S[R-L] == S[R]) R++;
			Z[i] = R-L, R--;
		}
		
		else{
			k = i-L;
			
			if (Z[k] < R-i+1) Z[i] = Z[k];
			else{
				L = i;
				while (R < n && S[R-L] == S[R]) R++;
				Z[i] = R-L, R--;
			}
		}

	for (int i = 0; i < n; i++)
		cout << i << ": " << Z[i] << "\n";
		
	return 0;
}
