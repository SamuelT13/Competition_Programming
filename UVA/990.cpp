#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int dist[31], value[31], constant, total, trea, i, j;
	int memo[31][1001], res[31], values, next(0);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> total >> constant){
		if (next++) cout << "\n";
		cin >> trea;
		
		for (i = 1; i <= trea; i++){
			cin >> dist[i] >> value[i];
			dist[i] *= 3*constant;
		}
		
		for (i = 0; i <= total; i++)
			memo[0][i] = 0;
	
		for (i = 1; i <= trea; i++)	
			for (j = 0; j <= total; j++)
				if (dist[i] > j)
					memo[i][j] = memo[i-1][j]; 
				else		
					memo[i][j] = max(memo[i-1][j], value[i]+memo[i-1][j-dist[i]]);
		
	
		/*for (i = 0; i <= trea; i++){
			for (j = 0; j <= total; j++)
				cout << memo[i][j] << " ";
			cout << endl;
		}*/
		
		j = 0;
		values = 0;
		for (i = trea; i > 0; i--)	
			if (memo[i][total] != memo[i-1][total]){
				res[j++] = i;
				values += value[i];
				total -= dist[i];
			}
		
		cout << values << "\n" << j << "\n";
		for (i = j-1; i >= 0; i--)
			cout << dist[res[i]]/(3*constant) << " " << value[res[i]] << "\n";	
	}
	
	return 0;
	
}
