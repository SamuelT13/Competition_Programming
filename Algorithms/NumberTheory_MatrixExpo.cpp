#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

typedef long long LL;

const LL MAT_SIZE = 2;

// A struct for a square matrix.
struct matrix{
	LL mat[MAT_SIZE][MAT_SIZE];
	
	matrix() {
		memset(mat, 0, sizeof(mat));
	}
	
	matrix(LL w, LL x, LL y, LL z){
		mat[0][0] = w;
		mat[0][1] = x;
		mat[1][0] = y;
		mat[1][1] = z;
	}
	
	matrix add(const matrix& b, LL mod) const{
		matrix res(*this);
		
		for (LL r = 0; r < MAT_SIZE; r++)
			for (LL c = 0; c < MAT_SIZE; c++)
				res.mat[r][c] = (res.mat[r][c]%mod + b.mat[r][c]%mod) % mod;
		return res;
	}
	
	matrix multiply(const matrix& b, LL mod) const{
		matrix res;
		
		for (LL r = 0; r < MAT_SIZE; r++)
			for (LL c = 0; c < MAT_SIZE; c++)
				for (LL k = 0; k < MAT_SIZE; k++)
					res.mat[r][c] = (res.mat[r][c] % mod + (mat[r][k]%mod) * (b.mat[k][c]%mod)) % mod;
		return res;
	}
	
	matrix operator%(LL mod) const{
		matrix res(*this);
		
		for (LL r = 0; r < MAT_SIZE; r++)
			for (LL c = 0; c < MAT_SIZE; c++)
				res.mat[r][c] %= mod;
		return res;
	}
};

// Calculates Base^Expo mod Mod, where Base is a matrix.
matrix mod_matrix_power(const matrix& base, LL expo, LL mod){
	matrix result = matrix(1, 0, 0, 1) % mod;
	matrix square = base % mod;
	
	for (LL p = 0; p < 63; p++){
		if (expo & (LL(1) << p))
			result = result.multiply(square, mod);
			square = square.multiply(square, mod);
		}
		return result;
}
	
LL calc_recurrence_matrix(LL index, LL a, LL b, LL f0, LL f1, LL mod){
	matrix recur(0, 1, b, a);
	matrix initial(f0, 0, f1, 0);
	matrix res = mod_matrix_power(recur, index, mod).multiply(initial, mod);
	return res.mat[0][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//F(n) = AF(n-1) + BF(n-2)
	
	const LL A = 1;
	const LL B = 1;
	const LL F0 = 1;
	const LL F1 = 1;
	const LL MODULUS = 10;
	LL index;
	
	while (cin >> index)
		cout << calc_recurrence_matrix(index-1, A, B, F0, F1, MODULUS) << "\n";
	
	return 0;
}

