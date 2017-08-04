#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double EPS = 1e-5;
vector<vector<double> > A, B;

bool inversa(int N){
	int jmax;
	double temp;
	
	for (int i = 0; i < N; i++){
		jmax = i; //largest element in A at col i, with row >= i
		for (int j = i+1; j < N; j++)
			if (abs(A[j][i]) > abs(A[jmax][i])) jmax = j;
	
		for (int j = 0; j < N; j++) //swap rows i and jmax
			swap(A[i][j], A[jmax][j]), swap(B[i][j], B[jmax][j]);

		if (abs(A[i][i]) < EPS) return false;
		
		temp = A[i][i]; //normalize row i
		for (int j = 0; j < N; j++)
			A[i][j] /= temp, B[i][j] /= temp;
		
		//Eliminate non-zero values in col i
		for (int j = 0; j < N; j++){
			if (i == j) continue;
			temp = A[j][i];
			
			for (int k = 0; k < N; k++)
				A[j][k] -= A[i][k]*temp, B[j][k] -= B[i][k]*temp;
		}
	}
	return true;
}

int main(){
	return 0;
}
