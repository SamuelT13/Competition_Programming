#include <iostream>
using namespace std;

int main(){
	int x, y, i, j, num(1), count;
	char board[105][105];

	while (cin >> x >> y && (x || y)){
		if (num != 1) cout << endl;
		
		for (i = 0; i < 105; i++)
			for (j = 0; j < 105; j++)
				board[i][j] = '.';
			
		for (i = 1; i < x+1; i++)
			for (j = 1; j < y+1; j++)	
				cin >> board[i][j];
			
		for (i = 1; i < x+1; i++)
			for (j = 1; j < y+1; j++)
				if (board[i][j] == '.'){
					count = 0;
					if (board[i+1][j] == '*') count++;
					if (board[i+1][j+1] == '*') count++;
					if (board[i+1][j-1] == '*') count++;
					if (board[i-1][j] == '*') count++;
					if (board[i-1][j+1] == '*') count++;
					if (board[i-1][j-1] == '*') count++;
					if (board[i][j+1] == '*') count++;
					if (board[i][j-1] == '*') count++;
					
					board[i][j] = int('0'+count);
				}
			
		cout << "Field #" << num++ << ":" << endl;
		for (i = 1; i < x+1; i++){
			for (j = 1; j < y+1; j++)	
				cout << board[i][j];
			cout << endl;
		}
					
	}
	return 0;
}
