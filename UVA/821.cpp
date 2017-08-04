#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> ii;

int **AdjMat;
//AdjMat[i][j] has the weight of edge (i, j)
// or INF (1B) if there is no such edge
// AdjMat is a 32-bit signed integer array

int main(){
	int maxi, x, y, count, sum, ind(0);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	
	while (cin >> x >> y && (x||y)){
		maxi = count = sum = 0;
		AdjMat = new int*[101];
	
		for (int i = 0; i < 101; i++){
			AdjMat[i] = new int[101];
			for (int j = 0; j < 101; j++) AdjMat[i][j] = INF;
		}
		
		do{
			AdjMat[x][y] = 1;
			maxi = max(maxi, max(x,y));
		} while (cin >> x >> y && (x||y));
	
		for (int k = 0; k < maxi+1; k++)
			for (int i = 0; i < maxi+1; i++)
				for (int j = 0; j < maxi+1; j++)
					AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
		
		for (int i = 0; i < maxi+1; i++)
			for (int j = 0; j < maxi+1; j++)
				if (i != j && AdjMat[i][j] != INF){
					count++;
					sum += AdjMat[i][j];
				}
				
		cout << "Case " << ++ind << ": average length between pages = " << double(sum)/count << " clicks\n";
	}	
	return 0;
}


