#include <iostream>
#include <vector>
#include <string>
using namespace std;

//string A
//H(A) = C * B^N + V(a0) * B^(N-1) + V(a1) * B(N-2) + ... + V(aN) * B^0 mod M
//M = 2^64 ULL
//C: odd
//V(ai): 0 to 25 for alphabet (only one case)
//B: odd && B > V(ai) && prime && rand

/* Prefix hash
h[0] = C ULL;
for (int i = 1; i <= N; i++) h[i] = h[i-1]*B + V(a[i-1]);
*/

/* Hash Generator
HASH CALC_HASH(int s, int e){
	return h[e] - h[s] * POW[e-s];
}
*/

/* Pow Generator
POW[0] = 1ULL;
for (int i = 1; i <= N; i++) POW[i] = POW[i-1]*B;
*/

/* Compare Function (non-equality)
bool compare(int A, int B){
	int s = 0, e = N - max(A, B) + 1, m;
	
	while (e-s > 1){
		m = (e+s)/2;
		
		if (calc_hash(a, a+m) == calc_hash(b, b+m)) s = m;
		else e = m;
	}
	
	return cad[A+s] < cad[B+s];
}
*/

/* Static Map
vector< pair<HASH, V> > M[1e6];
*/
