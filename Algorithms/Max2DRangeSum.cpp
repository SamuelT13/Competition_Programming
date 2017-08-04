#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int **matrix, i, j, k, l, size, sub, maxsub;
	
	scanf("%d",&size);
	
	matrix = new int*[size];
	
	for (i = 0; i < size; i++){
		matrix[i] = new int[size];
		for (j = 0; j < size; j++){
			scanf("%d",&matrix[i][j]);
			
			if (i) matrix[i][j] += matrix[i-1][j];
			if (j) matrix[i][j] += matrix[i][j-1];
			if (i && j) matrix[i][j] -= matrix[i-1][j-1];
		}
	}
		
	maxsub = -100*1000*1000;
	
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			for (k = i; k < size; k++)
				for (l = j; l < size; l++){
					sub = matrix[k][l];
					
					if (i) sub -= matrix[i-1][l];
					if (j) sub -= matrix[k][j-1];
					if (i && j) sub += matrix[i-1][j-1];
					
					maxsub = max(maxsub,sub);	
				}
	printf("%d\n",maxsub);
	
	return 0;
}
