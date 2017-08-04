#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> ii;

//AdjMat[i][j] has the weight of edge (i, j)
// or INF (1B) if there is no such edge
// AdjMat is a 32-bit signed integer array

int main(){
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
	
}


